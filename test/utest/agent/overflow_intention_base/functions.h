/*
 * functions.h
 *
 *  Created on: Sep 18, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_OVERFLOW_INTENTION_BASE_FUNCTIONS_H_
#define UTEST_AGENT_OVERFLOW_INTENTION_BASE_FUNCTIONS_H_

int ovflw_int_base_var = 0;

bool action_ovflw_int_base_action_1()
{
  ovflw_int_base_var = 1;
  return true;
}

bool action_ovflw_int_base_action_2()
{
  ovflw_int_base_var = 2;
  return true;
}

bool action_ovflw_int_base_action_3()
{
  ovflw_int_base_var = 3;
  return true;
}

bool action_ovflw_int_base_action_4()
{
  ovflw_int_base_var = 4;
  return true;
}

bool action_ovflw_int_base_action_5()
{
  ovflw_int_base_var = 5;
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
