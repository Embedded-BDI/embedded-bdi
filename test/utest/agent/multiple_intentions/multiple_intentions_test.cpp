/*
 * multiple_intentions_test.cpp
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
 *
 *
 * AgentSpeak code:
 *
 *   goal1.
 *   goal2.
 *   goal3.
 *
 *   +!goal1 <- action_1_multiple_intentions; !goal2.
 *   +!goal2 <- action_2_multiple_intentions.
 *   +!goal3 <- action_3_multiple_intentions; !goal4.
 *   +!goal4 <- action_4_multiple_intentions.
 *   +!goal5 <- action_5_multiple_intentions; !goal6.
 *   +!goal6 <- action_6_multiple_intentions.
 */

#include "common_lib.h"
#include "gtest/gtest.h"
#include "agent/agent.h"
#include "configuration.h"

class TMultipleIntentions : public ::testing::Test
{
protected:
  Agent * agent;
  BeliefBase * beliefs;
  EventBase * events;
  PlanBase * plans;
  IntentionBase * intentions;
  MultipleIntentions * multiple_intentions;

public:
  TMultipleIntentions()
  {
    multiple_intentions = new MultipleIntentions();

    beliefs = multiple_intentions->get_belief_base();
    events = multiple_intentions->get_event_base();
    plans = multiple_intentions->get_plan_base();
    intentions = multiple_intentions->get_intention_base();

    agent = new Agent(beliefs, events, plans, intentions);
  }

  ~TMultipleIntentions()
  {
    delete this->multiple_intentions;
    delete this->agent;
  }
};

TEST_F(TMultipleIntentions, run_multiple_intentions)
{
  EXPECT_EQ(shared_var, 0);
  EXPECT_TRUE(events->is_full());
  EXPECT_TRUE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(shared_var, 1);
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(shared_var, 1);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(shared_var, 3);
  EXPECT_FALSE(events->is_empty());
  EXPECT_TRUE(intentions->is_full());

  agent->run();
  EXPECT_EQ(shared_var, 2);
  EXPECT_TRUE(events->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(shared_var, 5);
  EXPECT_TRUE(events->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(shared_var, 5);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(shared_var, 5);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(shared_var, 4);
  EXPECT_TRUE(events->is_empty());
  EXPECT_FALSE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(shared_var, 6);
  EXPECT_TRUE(events->is_empty());
  EXPECT_TRUE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(shared_var, 6);
  EXPECT_TRUE(events->is_empty());
  EXPECT_TRUE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(shared_var, 6);
  EXPECT_TRUE(events->is_empty());
  EXPECT_TRUE(intentions->is_empty());
}
