#include <condition_variable>
#include <iostream>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <errno.h>

std::mutex m;
std::condition_variable cv;
bool ready = false;
bool processed = false;

void wait_for_server()
{
  {
    std::lock_guard<std::mutex> lk(m);
    ready = true;
    cv.notify_one();
  }
  {
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, []{return processed;});
  }
}

/*
 * Based on
 * https://www.ibm.com/support/knowledgecenter/ssw_ibm_i_72/rzab6/xnonblock.htm
 */
void server(int port, int expected, bool * server_result)
{
  int i, len, rc, on = 1;
  int listen_sd, max_sd, new_sd;
  int desc_ready;
  bool end_server = false;
  bool close_conn = false;
  bool error_flag = false;
  char buffer[80];
  struct sockaddr_in6 addr;
  struct timeval timeout;
  fd_set master_set, working_set;

  std::unique_lock<std::mutex> lk(m);
  cv.wait(lk, []{return ready;});

  /*************************************************************/
  /* Create an AF_INET6 stream socket to receive incoming      */
  /* connections on                                            */
  /*************************************************************/
  listen_sd = socket(AF_INET6, SOCK_STREAM, 0);
  if (listen_sd < 0)
  {
    std::cout << "Server: socket() failed" << std::endl;
    error_flag = true;
    return;
  }

  /*************************************************************/
  /* Allow socket descriptor to be reuseable                   */
  /*************************************************************/
  rc = setsockopt(listen_sd, SOL_SOCKET, SO_REUSEADDR, (char *)&on,sizeof(on));
  if (rc < 0)
  {
    std::cout << "Server: setsockopt() failed" << std::endl;
    close(listen_sd);
    error_flag = true;
    return;
  }

  /*************************************************************/
  /* Set socket to be nonblocking. All of the sockets for      */
  /* the incoming connections will also be nonblocking since   */
  /* they will inherit that state from the listening socket.   */
  /*************************************************************/
  rc = ioctl(listen_sd, FIONBIO, (char *)&on);
  if (rc < 0)
  {
    std::cout << "Server: ioctl() failed" << std::endl;
    close(listen_sd);
    error_flag = true;
    return;
  }

  /*************************************************************/
  /* Bind the socket                                           */
  /*************************************************************/
  memset(&addr, 0, sizeof(addr));
  addr.sin6_family = AF_INET6;
  memcpy(&addr.sin6_addr, &in6addr_any, sizeof(in6addr_any));
  addr.sin6_port = htons(port);
  rc = bind(listen_sd, (struct sockaddr *)&addr, sizeof(addr));
  if (rc < 0)
  {
    std::cout << "Server: bind() failed" << std::endl;
    close(listen_sd);
    error_flag = true;
    return;
  }

  /*************************************************************/
  /* Set the listen back log                                   */
  /*************************************************************/
  rc = listen(listen_sd, 32);
  if (rc < 0)
  {
    std::cout << "Server: listed() failed" << std::endl;
    close(listen_sd);
    error_flag = true;
    return;
  }

  /*************************************************************/
  /* Initialize the master fd_set                              */
  /*************************************************************/
  FD_ZERO(&master_set);
  max_sd = listen_sd;
  FD_SET(listen_sd, &master_set);

  /*************************************************************/
  /* Initialize the timeval struct to 3 minutes.  If no        */
  /* activity after 3 minutes this program will end.           */
  /*************************************************************/
  timeout.tv_sec  = 2;
  timeout.tv_usec = 0;

  {
    processed = true;
    lk.unlock();
    cv.notify_one();
  }

  /*************************************************************/
  /* Loop waiting for incoming connects or for incoming data   */
  /* on any of the connected sockets.                          */
  /*************************************************************/
  do
  {
    /**********************************************************/
    /* Copy the master fd_set over to the working fd_set.     */
    /**********************************************************/
    memcpy(&working_set, &master_set, sizeof(master_set));

    /**********************************************************/
    /* Call select() and wait 3 minutes for it to complete.   */
    /**********************************************************/
    rc = select(max_sd + 1, &working_set, NULL, NULL, &timeout);

    /**********************************************************/
    /* Check to see if the select call failed.                */
    /**********************************************************/
    if (rc < 0)
    {
      std::cout << "Server: select() failed" << std::endl;
      error_flag = true;
      break;
    }

    /**********************************************************/
    /* Check to see if the 3 minute time out expired.         */
    /**********************************************************/
    if (rc == 0)
    {
      std::cout << "Server: bind() failed" << std::endl;
      error_flag = true;
      break;
    }

    /**********************************************************/
    /* One or more descriptors are readable.  Need to         */
    /* determine which ones they are.                         */
    /**********************************************************/
    desc_ready = rc;
    for (i=0; i <= max_sd  &&  desc_ready > 0; ++i)
    {
      /*******************************************************/
      /* Check to see if this descriptor is ready            */
      /*******************************************************/
      if (FD_ISSET(i, &working_set))
      {
        /****************************************************/
        /* A descriptor was found that was readable - one   */
        /* less has to be looked for.  This is being done   */
        /* so that we can stop looking at the working set   */
        /* once we have found all of the descriptors that   */
        /* were ready.                                      */
        /****************************************************/
        desc_ready -= 1;

        /****************************************************/
        /* Check to see if this is the listening socket     */
        /****************************************************/
        if (i == listen_sd)
        {
          /*************************************************/
          /* Accept all incoming connections that are      */
          /* queued up on the listening socket before we   */
          /* loop back and call select again.              */
          /*************************************************/
          do
          {
            /**********************************************/
            /* Accept each incoming connection.  If       */
            /* accept fails with EWOULDBLOCK, then we     */
            /* have accepted all of them.  Any other      */
            /* failure on accept will cause us to end the */
            /* server.                                    */
            /**********************************************/
            new_sd = accept(listen_sd, NULL, NULL);
            if (new_sd < 0)
            {
              if (errno != EWOULDBLOCK)
              {
                std::cout << "Server: accept() failed" << std::endl;
                error_flag = true;
                end_server = true;
              }
              break;
            }

            /**********************************************/
            /* Add the new incoming connection to the     */
            /* master read set                            */
            /**********************************************/
            FD_SET(new_sd, &master_set);
            if (new_sd > max_sd)
            {
              max_sd = new_sd;
            }

            /**********************************************/
            /* Loop back up and accept another incoming   */
            /* connection                                 */
            /**********************************************/
          } while (new_sd != -1);
        }

        /****************************************************/
        /* This is not the listening socket, therefore an   */
        /* existing connection must be readable             */
        /****************************************************/
        else
        {
          close_conn = false;
          /*************************************************/
          /* Receive all incoming data on this socket      */
          /* before we loop back and call select again.    */
          /*************************************************/
          do
          {
            /**********************************************/
            /* Receive data on this connection until the  */
            /* recv fails with EWOULDBLOCK.  If any other */
            /* failure occurs, we will close the          */
            /* connection.                                */
            /**********************************************/
            rc = recv(i, buffer, sizeof(buffer), 0);
            if (rc < 0)
            {
              if (errno != EWOULDBLOCK)
              {
                std::cout << "Server: recv() failed" << std::endl;
                close_conn = true;
                error_flag = true;
              }
              break;
            }

            /**********************************************/
            /* Check to see if the connection has been    */
            /* closed by the client                       */
            /**********************************************/
            if (rc == 0)
            {
//              std::cout << "Server: Connection closed" << std::endl;
              close_conn = true;
              end_server = true;
              break;
            }

            /**********************************************/
            /* Data was received                          */
            /**********************************************/
            len = rc;

            int received;
            sscanf(buffer, "%d", &received);
//            std::cout << received << " received, " << expected << " expected" << std::endl;

            if (received == expected)
            {
              error_flag = false;
            }
            else
            {
              error_flag = true;
            }

//            close_conn = true;
//            end_server = true;
//            break;
          } while (true);

          /*************************************************/
          /* If the close_conn flag was turned on, we need */
          /* to clean up this active connection.  This     */
          /* clean up process includes removing the        */
          /* descriptor from the master set and            */
          /* determining the new maximum descriptor value  */
          /* based on the bits that are still turned on in */
          /* the master set.                               */
          /*************************************************/
          if (close_conn)
          {
            close(i);
            FD_CLR(i, &master_set);
            if (i == max_sd)
            {
              while (FD_ISSET(max_sd, &master_set) == 0)
              {
                 max_sd -= 1;
              }
            }
          }
        } /* End of existing connection is readable */
      } /* End of if (FD_ISSET(i, &working_set)) */
    } /* End of loop through selectable descriptors */
  } while (end_server == false);

  /*************************************************************/
  /* Clean up all of the sockets that are open                 */
  /*************************************************************/
  for (i=0; i <= max_sd; ++i)
  {
     if (FD_ISSET(i, &master_set))
     {
       close(i);
     }
  }

  close(listen_sd);

  if (error_flag)
  {
    *server_result = false;
  }
  else
  {
    *server_result = true;
  }
}
