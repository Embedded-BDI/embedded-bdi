/*
 * functions.h
 *
 *  Created on: Jan 6, 2021
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_NB_SUBGOAL_FULL_INTENTION_BASE_FUNCTIONS_H_
#define UTEST_AGENT_NB_SUBGOAL_FULL_INTENTION_BASE_FUNCTIONS_H_

int nb_full_intention_base_var = 0;

bool action_nb_full_intention_base_1()
{
  nb_full_intention_base_var = 1;
  return true;
}

bool action_nb_full_intention_base_2()
{
  nb_full_intention_base_var = 2;
  return true;
}

bool action_nb_full_intention_base_3()
{
  nb_full_intention_base_var = 3;
  return true;
}

bool action_nb_full_intention_base_4()
{
  nb_full_intention_base_var = 4;
  return true;
}

#endif /* UTEST_AGENT_NB_SUBGOAL_FULL_INTENTION_BASE_FUNCTIONS_H_ */
