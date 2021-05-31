#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>

//------------------------- Action functions ----------------------------------

bool action_say_hello()
{
  std::cout << "Hello!\nI am an agent and I will keep running until I am "
            << "terminated" << std::endl;
  return true;
}

#endif /* FUNCTIONS_H_ */