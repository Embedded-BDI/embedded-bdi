/*
 * functions.h
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_STACKED_INTENTION_FUNCTIONS_H_
#define UTEST_AGENT_STACKED_INTENTION_FUNCTIONS_H_

#include "common_lib.h"

bool action_1_stacked_intention(bool var)
{
  shared_var = 1;
  return true;
}

bool action_2_stacked_intention(bool var)
{
  shared_var = 2;
  return true;
}

bool action_3_stacked_intention(bool var)
{
  shared_var = 3;
  return true;
}

#endif /* UTEST_AGENT_STACKED_INTENTION_FUNCTIONS_H_ */
