/*
 * nb_subgoal_empty_intention_base.cpp
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

class TNBSubgoalEmptyIntentionBase : public ::testing::Test
{
protected:
  Agent * agent;
  BeliefBase * beliefs;
  EventBase * events;
  PlanBase * plans;
  IntentionBase * intentions;
  NBSubgoalEmptyIntentionBase * nb_subgoal_empty_int_base;

public:
  TNBSubgoalEmptyIntentionBase()
  {
    nb_subgoal_empty_int_base = new NBSubgoalEmptyIntentionBase();

    beliefs = nb_subgoal_empty_int_base->get_belief_base();
    events = nb_subgoal_empty_int_base->get_event_base();
    plans = nb_subgoal_empty_int_base->get_plan_base();
    intentions = nb_subgoal_empty_int_base->get_intention_base();

    agent = new Agent(beliefs, events, plans, intentions);
  }

  ~TNBSubgoalEmptyIntentionBase()
  {
    delete agent;
    delete nb_subgoal_empty_int_base;
  }
};

TEST_F(TNBSubgoalEmptyIntentionBase, run_intention)
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
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(shared_var, 3);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), true);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(shared_var, 4);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), true);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(shared_var, 4);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), true);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(shared_var, 4);
}
