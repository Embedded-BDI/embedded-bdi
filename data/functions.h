#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <ctime>

//-----------------------------------------------------------------------------

int my_number = 11;           // number out of range so it is not sorted before
                              // the agent grabs a number
bool joined_auction = false;

//------------------------- Action functions ----------------------------------

bool action_join_lottery()
{
  joined_auction = true;
  std::cout << "I'm joining the lottery!" << std::endl;
  return true;
}

bool action_grab_number()
{
  srand(time(0));

  my_number = rand() % 10;
  std::cout << "My number is: " << my_number << std::endl;

  return true;
}

bool action_cheer_and_leave()
{
  std::cout << "I won! My number was sorted: " << my_number << std::endl;
  exit(0);
  return true;
}

//-------------------------- Belief update functions --------------------------

bool update_my_number(bool var)
{
  if (joined_auction)
  {
    int number_sorted = rand() % 10;
    std::cout << "Number sorted was: " << number_sorted << std::endl;
    
    return (my_number == number_sorted);
  }
  else
  {
    return false;
  }
}

#endif /* FUNCTIONS_H_ */