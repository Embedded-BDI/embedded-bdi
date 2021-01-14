/*
 * functions.h
 *
 *  Created on: Jan 7, 2021
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_NB_SUBGOAL_FAILED_PLAN_FUNCTIONS_H_
#define UTEST_AGENT_NB_SUBGOAL_FAILED_PLAN_FUNCTIONS_H_

#include "common_lib.h"

bool action_update_1()
{
  shared_var = 1;
  return true;
}

bool action_update_2()
{
  shared_var = 2;
  return true;
}

bool action_update_3()
{
  shared_var = 3;
  return true;
}

bool action_update_4()
{
  shared_var = 4;
  return true;
}

bool action_update_5()
{
  shared_var = 5;
  return true;
}

bool action_update_6()
{
  shared_var = 6;
  return true;
}

bool action_update_7()
{
  shared_var = 7;
  return true;
}

bool action_return_false_bool()
{
  return false;
}

#endif /* UTEST_AGENT_NB_SUBGOAL_FAILED_PLAN_FUNCTIONS_H_ */
