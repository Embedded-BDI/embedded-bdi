/*
 * nb_subgoal_failed_plan.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: Matuzalem Muller
 *
 *
 * AgentSpeak code:
 *
 *   !plan_1.
 *
 *   +!plan_1 <- action_1; !!plan_2; action_2; action_4.
 *
 *   +!plan_2 <- action_3.
 */

#include "common_lib.h"
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
  EXPECT_EQ(shared_var, 1);

  agent->run();
  EXPECT_EQ(events->is_empty(), false);
  EXPECT_EQ(events->is_full(), true);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(shared_var, 1);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), true);
  EXPECT_EQ(shared_var, 2);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), true);
  EXPECT_EQ(shared_var, 3);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), true);
  EXPECT_EQ(shared_var, 4);

  agent->run();
  EXPECT_EQ(events->is_empty(), false);
  EXPECT_EQ(events->is_full(), true);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(shared_var, 4);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), true);
  EXPECT_EQ(shared_var, 5);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(shared_var, 6);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), true);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(shared_var, 7);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), true);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(shared_var, 7);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), true);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(shared_var, 7);
}
