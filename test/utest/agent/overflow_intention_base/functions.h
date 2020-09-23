/*
 * functions.h
 *
 *  Created on: Sep 18, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_OVERFLOW_INTENTION_BASE_FUNCTIONS_H_
#define UTEST_AGENT_OVERFLOW_INTENTION_BASE_FUNCTIONS_H_

#include "common_lib.h"

bool action_1(bool var)
{
  shared_var = 1;
  return true;
}

bool action_2(bool var)
{
  shared_var = 2;
  return true;
}

bool action_3(bool var)
{
  shared_var = 3;
  return true;
}

bool action_4(bool var)
{
  shared_var = 4;
  return true;
}

bool action_5(bool var)
{
  shared_var = 5;
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

#endif /* UTEST_AGENT_OVERFLOW_INTENTION_BASE_FUNCTIONS_H_ */
