/*
 * functions.h
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_MULTIPLE_INTENTIONS_FUNCTIONS_H_
#define UTEST_AGENT_MULTIPLE_INTENTIONS_FUNCTIONS_H_

int multiple_intentions_shared_var = 0;

bool action_multiple_intentions_action_1()
{
  multiple_intentions_shared_var = 1;
  return true;
}

bool action_multiple_intentions_action_2()
{
  multiple_intentions_shared_var = 2;
  return true;
}

bool action_multiple_intentions_action_3()
{
  multiple_intentions_shared_var = 3;
  return true;
}

bool action_multiple_intentions_action_4()
{
  multiple_intentions_shared_var = 4;
  return true;
}

bool action_multiple_intentions_action_5()
{
  multiple_intentions_shared_var = 5;
  return true;
}

bool action_multiple_intentions_action_6()
{
  multiple_intentions_shared_var = 6;
  return true;
}

#endif /* UTEST_AGENT_MULTIPLE_INTENTIONS_FUNCTIONS_H_ */
