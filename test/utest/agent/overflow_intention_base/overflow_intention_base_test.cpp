/*
 * overflow_intention_base_test.cpp
 *
 *  Created on: Sep 18, 2020
 *      Author: Matuzalem Muller
 *
 * AgentSpeak code:
 *
 * +belief_1 <- ovflw_int_base_action_1; ovflw_int_base_action_1; ovflw_int_base_action_1; ovflw_int_base_action_1.
 * +belief_2 <- ovflw_int_base_action_2; ovflw_int_base_action_2; ovflw_int_base_action_2.
 * +belief_3 <- ovflw_int_base_action_3; ovflw_int_base_action_3.
 * +belief_4 <- ovflw_int_base_action_4.
 * +belief_5 <- ovflw_int_base_action_5.
 */

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
  EXPECT_EQ(0, ovflw_int_base_var);
  EXPECT_TRUE(events->is_empty());
  EXPECT_TRUE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(1, ovflw_int_base_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(1, ovflw_int_base_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(2, ovflw_int_base_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(1, ovflw_int_base_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(3, ovflw_int_base_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_TRUE(intentions->is_full());

  agent->run();
  EXPECT_EQ(2, ovflw_int_base_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_TRUE(intentions->is_full());

  agent->run();
  EXPECT_EQ(4, ovflw_int_base_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(1, ovflw_int_base_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(5, ovflw_int_base_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(3, ovflw_int_base_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(2, ovflw_int_base_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(1, ovflw_int_base_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(1, ovflw_int_base_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(1, ovflw_int_base_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());
}
