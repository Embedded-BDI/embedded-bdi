/*
 * multiple_intentions_test.cpp
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
 *
 *
 * AgentSpeak code:
 *
 *   !goal1.
 *   !goal2.
 *   !goal3.
 *
 *   +!goal1 <- multiple_intentions_action_1; !goal2.
 *   +!goal2 <- multiple_intentions_action_2.
 *   +!goal3 <- multiple_intentions_action_3; !goal4.
 *   +!goal4 <- multiple_intentions_action_4.
 *   +!goal5 <- multiple_intentions_action_5; !goal6.
 *   +!goal6 <- multiple_intentions_action_6.
 */

#include "functions.h"
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
  EXPECT_EQ(multiple_intentions_shared_var, 0);
  EXPECT_TRUE(events->is_full());
  EXPECT_TRUE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(multiple_intentions_shared_var, 1);
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(multiple_intentions_shared_var, 1);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(multiple_intentions_shared_var, 2);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(multiple_intentions_shared_var, 2);
  EXPECT_TRUE(events->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(multiple_intentions_shared_var, 3);
  EXPECT_TRUE(events->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(multiple_intentions_shared_var, 3);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(multiple_intentions_shared_var, 4);
  EXPECT_TRUE(events->is_empty());
  EXPECT_TRUE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(multiple_intentions_shared_var, 4);
  EXPECT_TRUE(events->is_empty());
  EXPECT_TRUE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(multiple_intentions_shared_var, 4);
  EXPECT_TRUE(events->is_empty());
  EXPECT_TRUE(intentions->is_empty());
}
