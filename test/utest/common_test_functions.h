/*
 * test_data.h
 *
 *  Created on: Jul 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef COMMON_TEST_FUNCTIONS_H_
#define COMMON_TEST_FUNCTIONS_H_

#include <condition_variable>
#include <iostream>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <errno.h>
#include <unistd.h>

inline bool socket_client(int port, int value_to_send)
{
  int sock = 0;
  struct sockaddr_in serv_addr;
  std::string s = std::to_string(value_to_send);
  char const *hello = s.c_str();

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    printf("\n Socket creation error \n");
    return false;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);

  // Convert IPv4 and IPv6 addresses from text to binary form
  if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
  {
    printf("\nInvalid address/ Address not supported \n");
    return false;
  }

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    printf("\nConnection Failed \n");
    return false;
  }

  send(sock, hello, strlen(hello), 0 );

  close(sock);

  return true;
}

inline bool return_true_beliefbase(bool var)
{
  return true;
}

inline bool return_false_beliefbase(bool var)
{
  return false;
}

inline bool return_true_bool(bool var)
{
  return true;
}

inline bool return_false_bool(bool var)
{
  return false;
}

inline bool action_do_nothing(bool var)
{
  return true;
}

inline bool update_belief_1_revert_state(bool var)
{
  return !var;
}

inline bool update_belief_2_revert_state(bool var)
{
  return !var;
}

inline bool update_belief_3_revert_state(bool var)
{
  return !var;
}

inline bool update_belief_4_revert_state(bool var)
{
  return !var;
}

inline bool update_belief_5_revert_state(bool var)
{
  return !var;
}

inline bool update_belief_6_revert_state(bool var)
{
  return !var;
}

inline bool update_belief_7_revert_state(bool var)
{
  return !var;
}

inline bool update_belief_8_revert_state(bool var)
{
  return !var;
}

#endif

