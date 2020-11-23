#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>

bool action_action_1()
{
  std::cout << "Action 1 - Successful" << std::endl;
  return true;
}

bool action_action_2()
{
  std::cout << "Action 2 - Successful" << std::endl;
  return true;
}

bool action_action_3()
{
  std::cout << "Action 3 - Successful" << std::endl;
  return true;
}

bool action_action_4()
{
  std::cout << "Action 4 - Successful" << std::endl;
  return true;
}

bool action_action_5()
{
  std::cout << "Action 5 - Successful" << std::endl;
  return true;
}

bool action_action_6()
{
  std::cout << "Action 6 - Failure" << std::endl;
  return false;
}

bool action_action_7()
{
  std::cout << "Action 7 - Failure handling" << std::endl;
  return true;
}

bool update_belief_1(bool var)
{
  return !var;
}

bool update_belief_2(bool var)
{
  return !var;
}

bool update_belief_3(bool var)
{
  return !var;
}

bool update_belief_4(bool var)
{
  return !var;
}

bool update_belief_5(bool var)
{
  return !var;
}

#endif /* FUNCTIONS_H_ */