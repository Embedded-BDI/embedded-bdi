/*
 * nb_subgoal_failed_plan.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: Matuzalem Muller
 *
 * AgentSpeak code:
 *
 * !goal_1.
 * 
 * +!goal_1 <- nb_subgoal_true_1; !!goal_2; nb_subgoal_true_2; nb_subgoal_true_4; nb_subgoal_true_5; nb_subgoal_true_7.
 * 
 * +!goal_2 <- nb_subgoal_true_3; nb_subgoal_false.
 * 
 * -!goal_2 <- nb_subgoal_true_6.
 */

#include "gtest/gtest.h"
#include "agent/agent.h"
#include "configuration.h"

class TNBSubgoalFailedPlan : public ::testing::Test
{
protected:
  Agent * agent;
  BeliefBase * beliefs;
  EventBase * events;
  PlanBase * plans;
  IntentionBase * intentions;
  NBSubgoalFailedPlan * nb_subgoal_failed_plan;

public:
  TNBSubgoalFailedPlan()
  {
    nb_subgoal_failed_plan = new NBSubgoalFailedPlan();

    beliefs = nb_subgoal_failed_plan->get_belief_base();
    events = nb_subgoal_failed_plan->get_event_base();
    plans = nb_subgoal_failed_plan->get_plan_base();
    intentions = nb_subgoal_failed_plan->get_intention_base();

    agent = new Agent(beliefs, events, plans, intentions);
  }

  ~TNBSubgoalFailedPlan()
  {
    delete agent;
    delete nb_subgoal_failed_plan;
  }
};

TEST_F(TNBSubgoalFailedPlan, fail_intention)
{
  EXPECT_EQ(events->is_empty(), false);
  EXPECT_EQ(events->is_full(), true);
  EXPECT_EQ(intentions->is_empty(), true);
  EXPECT_EQ(intentions->is_full(), false);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(nb_subgoal_var, 1);

  agent->run();
  EXPECT_EQ(events->is_empty(), false);
  EXPECT_EQ(events->is_full(), true);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(nb_subgoal_var, 1);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), true);
  EXPECT_EQ(nb_subgoal_var, 2);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), true);
  EXPECT_EQ(nb_subgoal_var, 3);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), true);
  EXPECT_EQ(nb_subgoal_var, 4);

  agent->run();
  EXPECT_EQ(events->is_empty(), false);
  EXPECT_EQ(events->is_full(), true);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(nb_subgoal_var, 4);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), true);
  EXPECT_EQ(nb_subgoal_var, 5);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(nb_subgoal_var, 6);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), true);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(nb_subgoal_var, 7);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), true);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(nb_subgoal_var, 7);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), true);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(nb_subgoal_var, 7);
}
