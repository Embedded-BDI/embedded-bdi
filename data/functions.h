#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>

bool action_1(bool var)
{
  std::cout << "A" << std::endl;
  return true;
}

bool action_2(bool var)
{
  std::cout << "B" << std::endl;
  return true;
}

bool action_3(bool var)
{
  std::cout << "C" << std::endl;
  return true;
}

bool action_4(bool var)
{
  std::cout << "D" << std::endl;
  return true;
}

bool action_5(bool var)
{
  std::cout << "E" << std::endl;
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
