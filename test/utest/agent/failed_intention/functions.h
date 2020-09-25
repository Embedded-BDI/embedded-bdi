/*
 * functions.h
 *
 *  Created on: Sep 17, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_FAILED_INTENTION_FUNCTIONS_H_
#define UTEST_AGENT_FAILED_INTENTION_FUNCTIONS_H_

#include "common_lib.h"

bool action_return_true()
{
  shared_var = 1;
  return true;
}

bool action_return_false()
{
  shared_var = 2;
  return false;
}

bool action_deletion_1()
{
  shared_var = -100;
  return true;
}

bool action_deletion_2()
{
  shared_var = -200;
  return true;
}

#endif /* UTEST_AGENT_FAILED_INTENTION_FUNCTIONS_H_ */
