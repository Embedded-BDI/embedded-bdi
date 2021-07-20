/*
 * functions.h
 *
 *  Created on: Jan 7, 2021
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_NB_SUBGOAL_FAILED_PLAN_FUNCTIONS_H_
#define UTEST_AGENT_NB_SUBGOAL_FAILED_PLAN_FUNCTIONS_H_

int nb_subgoal_var = 0;

bool action_nb_subgoal_true_1()
{
  nb_subgoal_var = 1;
  return true;
}

bool action_nb_subgoal_true_2()
{
  nb_subgoal_var = 2;
  return true;
}

bool action_nb_subgoal_true_3()
{
  nb_subgoal_var = 3;
  return true;
}

bool action_nb_subgoal_true_4()
{
  nb_subgoal_var = 4;
  return true;
}

bool action_nb_subgoal_true_5()
{
  nb_subgoal_var = 5;
  return true;
}

bool action_nb_subgoal_true_6()
{
  nb_subgoal_var = 6;
  return true;
}

bool action_nb_subgoal_true_7()
{
  nb_subgoal_var = 7;
  return true;
}

bool action_nb_subgoal_false()
{
  return false;
}

#endif /* UTEST_AGENT_NB_SUBGOAL_FAILED_PLAN_FUNCTIONS_H_ */
