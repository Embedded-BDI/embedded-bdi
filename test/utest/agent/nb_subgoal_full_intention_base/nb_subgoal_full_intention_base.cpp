/*
 * nb_subgoal_full_intention_base.cpp
 *
 *  Created on: Jan 6, 2021
 *      Author: Matuzalem Muller
 *
 * AgentSpeak code:
 *
 * !plan_1.
 * 
 * +!plan_1 <- nb_full_intention_base_1; !!plan_2; nb_full_intention_base_2; nb_full_intention_base_3.
 * 
 * +!plan_2 <- nb_full_intention_base_1.
 */

#include "gtest/gtest.h"
#include "agent/agent.h"
#include "configuration.h"

class TNBSubgoalFullIntentionBase : public ::testing::Test
{
protected:
  Agent * agent;
  BeliefBase * beliefs;
  EventBase * events;
  PlanBase * plans;
  IntentionBase * intentions;
  NBSubgoalFullIntentionBase * nb_subgoal_full_int_base;

public:
  TNBSubgoalFullIntentionBase()
  {
    nb_subgoal_full_int_base = new NBSubgoalFullIntentionBase();

    beliefs = nb_subgoal_full_int_base->get_belief_base();
    events = nb_subgoal_full_int_base->get_event_base();
    plans = nb_subgoal_full_int_base->get_plan_base();
    intentions = nb_subgoal_full_int_base->get_intention_base();

    agent = new Agent(beliefs, events, plans, intentions);
  }

  ~TNBSubgoalFullIntentionBase()
  {
    delete agent;
    delete nb_subgoal_full_int_base;
  }
};

TEST_F(TNBSubgoalFullIntentionBase, drop_event)
{
  EXPECT_EQ(events->is_empty(), false);
  EXPECT_EQ(events->is_full(), true);
  EXPECT_EQ(intentions->is_empty(), true);
  EXPECT_EQ(intentions->is_full(), false);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), true);
  EXPECT_EQ(nb_full_intention_base_var, 1);

  agent->run();
  EXPECT_EQ(events->is_empty(), false);
  EXPECT_EQ(events->is_full(), true);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), true);
  EXPECT_EQ(nb_full_intention_base_var, 1);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), false);
  EXPECT_EQ(intentions->is_full(), true);
  EXPECT_EQ(nb_full_intention_base_var, 2);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), true);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(nb_full_intention_base_var, 3);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), true);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(nb_full_intention_base_var, 3);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), true);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(nb_full_intention_base_var, 3);

  agent->run();
  EXPECT_EQ(events->is_empty(), true);
  EXPECT_EQ(events->is_full(), false);
  EXPECT_EQ(intentions->is_empty(), true);
  EXPECT_EQ(intentions->is_full(), false);
  EXPECT_EQ(nb_full_intention_base_var, 3);
}
