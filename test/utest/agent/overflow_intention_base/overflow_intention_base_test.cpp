/*
 * overflow_intention_base_test.cpp
 *
 *  Created on: Sep 18, 2020
 *      Author: Matuzalem Muller
 *
 *
 * AgentSpeak code:
 *
 *   +belief_1 <- action_1; action_1; action_1; action_1.
 *   +belief_2 <- action_2; action_2; action_2.
 *   +belief_3 <- action_3; action_3.
 *   +belief_4 <- action_4.
 *   +belief_5 <- action_5.
 */

#include "common_lib.h"
#include "gtest/gtest.h"
#include "agent/agent.h"
#include "configuration.h"

class TOverflowIntentionBase : public ::testing::Test
{
protected:
  Agent * agent;
  BeliefBase * beliefs;
  EventBase * events;
  PlanBase * plans;
  IntentionBase * intentions;
  OverflowIntentionBase * overflow_intention_base;

public:
  TOverflowIntentionBase()
  {
    overflow_intention_base = new OverflowIntentionBase();

    beliefs = overflow_intention_base->get_belief_base();
    events = overflow_intention_base->get_event_base();
    plans = overflow_intention_base->get_plan_base();
    intentions = overflow_intention_base->get_intention_base();

    agent = new Agent(beliefs, events, plans, intentions);
  }

  ~TOverflowIntentionBase()
  {
    delete this->overflow_intention_base;
    delete this->agent;
  }
};

TEST_F(TOverflowIntentionBase, overflow_intention_base)
{
  EXPECT_EQ(0, shared_var);
  EXPECT_TRUE(events->is_empty());
  EXPECT_TRUE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(1, shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(1, shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(2, shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(1, shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(3, shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_TRUE(intentions->is_full());

  agent->run();
  EXPECT_EQ(2, shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_TRUE(intentions->is_full());

  agent->run();
  EXPECT_EQ(4, shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(1, shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(5, shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(3, shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(2, shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(1, shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(1, shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(1, shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());
}
