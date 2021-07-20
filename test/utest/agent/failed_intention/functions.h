/*
 * functions.h
 *
 *  Created on: Sep 17, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_FAILED_INTENTION_FUNCTIONS_H_
#define UTEST_AGENT_FAILED_INTENTION_FUNCTIONS_H_

int failed_intention_shared_var;

bool action_failed_intention_return_true()
{
  failed_intention_shared_var = 1;
  return true;
}

bool action_failed_intention_return_false()
{
  failed_intention_shared_var = 2;
  return false;
}

bool action_failed_intention_deletion_1()
{
  failed_intention_shared_var = -100;
  return true;
}

bool action_failed_intention_deletion_2()
{
  failed_intention_shared_var = -200;
  return true;
}

#endif /* UTEST_AGENT_FAILED_INTENTION_FUNCTIONS_H_ */
