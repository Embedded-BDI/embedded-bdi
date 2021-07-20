/*
 * functions.h
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_action_overflow_STACKED_INTENTION_FUNCTIONS_H_
#define UTEST_AGENT_action_overflow_STACKED_INTENTION_FUNCTIONS_H_

int ovflw_stacked_intention_var = 0;

bool action_overflow_stacked_intention_1_1()
{
  ovflw_stacked_intention_var = 100;
  return true;
}

bool action_overflow_stacked_intention_1_2()
{
  ovflw_stacked_intention_var = 101;
  return true;
}

bool action_overflow_stacked_intention_2_1()
{
  ovflw_stacked_intention_var = 200;
  return true;
}

bool action_overflow_stacked_intention_2_2()
{
  ovflw_stacked_intention_var = 201;
  return true;
}

bool action_overflow_stacked_intention_3_1()
{
  ovflw_stacked_intention_var = 300;
  return true;
}

bool action_overflow_stacked_intention_3_2()
{
  ovflw_stacked_intention_var = 301;
  return true;
}

bool action_overflow_stacked_intention_4_1()
{
  ovflw_stacked_intention_var = 400;
  return true;
}

bool action_overflow_stacked_intention_4_2()
{
  ovflw_stacked_intention_var = 401;
  return true;
}

bool action_overflow_stacked_intention_5_1()
{
  ovflw_stacked_intention_var = 500;
  return true;
}

bool action_overflow_stacked_intention_5_2()
{
  ovflw_stacked_intention_var = 501;
  return true;
}

#endif /* UTEST_AGENT_action_overflow_STACKED_INTENTION_FUNCTIONS_H_ */
