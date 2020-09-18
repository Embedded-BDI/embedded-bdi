/*
 * overflow_stacked_intention.cpp
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
 *
 *
 * AgentSpeak code:
 *
 *   goal1.
 *
 *   +!goal1 <- action_1_1_overflow_stacked_intention; !goal2; action_1_2_overflow_stacked_intention.
 *   +!goal2 <- action_2_1_overflow_stacked_intention; !goal3; action_2_2_overflow_stacked_intention.
 *   +!goal3 <- action_3_1_overflow_stacked_intention; !goal4; action_3_2_overflow_stacked_intention.
 *   +!goal4 <- action_4_1_overflow_stacked_intention; !goal5; action_4_2_overflow_stacked_intention.
 *   +!goal5 <- action_5_1_overflow_stacked_intention.
 */

#include "common_lib.h"
#include "gtest/gtest.h"
#include "agent/agent.h"
#include "configuration.h"

class TOverflowStackedIntention : public ::testing::Test
{
protected:
  Agent * agent;
  BeliefBase * beliefs;
  EventBase * events;
  PlanBase * plans;
  IntentionBase * intentions;
  OverflowStackedIntention * overflow_stacked_intention;

public:
  TOverflowStackedIntention()
  {
    overflow_stacked_intention = new OverflowStackedIntention();

    beliefs = overflow_stacked_intention->get_belief_base();
    events = overflow_stacked_intention->get_event_base();
    plans = overflow_stacked_intention->get_plan_base();
    intentions = overflow_stacked_intention->get_intention_base();

    agent = new Agent(beliefs, events, plans, intentions);
  }

  ~TOverflowStackedIntention()
  {
    delete this->overflow_stacked_intention;
    delete this->agent;
  }
};

TEST_F(TOverflowStackedIntention, run_overflow_stacked_intention)
{
  EXPECT_TRUE(intentions->is_empty());
  EXPECT_TRUE(events->is_full());

  agent->run();
  EXPECT_EQ(100, shared_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_empty());

  agent->run();
  EXPECT_EQ(100, shared_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_full());

  agent->run();
  EXPECT_EQ(200, shared_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_empty());

  agent->run();
  EXPECT_EQ(200, shared_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_full());

  agent->run();
  EXPECT_EQ(300, shared_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_empty());

  agent->run();
  EXPECT_EQ(300, shared_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_full());

  agent->run();
  EXPECT_EQ(300, shared_var);
  EXPECT_TRUE(intentions->is_empty());
  EXPECT_TRUE(events->is_empty());
}
