/*
 * functions.h
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_STACKED_INTENTION_FUNCTIONS_H_
#define UTEST_AGENT_STACKED_INTENTION_FUNCTIONS_H_

int stacked_intention_var = 0;

bool action_stacked_intention_action_1()
{
  stacked_intention_var = 1;
  return true;
}

bool action_stacked_intention_action_2()
{
  stacked_intention_var = 2;
  return true;
}

bool action_stacked_intention_action_3()
{
  stacked_intention_var = 3;
  return true;
}

#endif /* UTEST_AGENT_STACKED_INTENTION_FUNCTIONS_H_ */
