/*
 * functions.h
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_SIMPLE_INTENTION_FUNCTIONS_H_
#define UTEST_AGENT_SIMPLE_INTENTION_FUNCTIONS_H_

int simple_intention_var = 0;

bool action_simple_intention_action_1()
{
  simple_intention_var = 1;
  return true;
}

bool action_simple_intention_action_2()
{
  simple_intention_var = 2;
  return true;
}

bool action_simple_intention_action_3()
{
  simple_intention_var = 3;
  return true;
}

bool action_simple_intention_action_4()
{
  simple_intention_var = 4;
  return true;
}

bool action_simple_intention_action_5()
{
  simple_intention_var = 5;
  return true;
}

#endif /* UTEST_AGENT_SIMPLE_INTENTION_FUNCTIONS_H_ */
