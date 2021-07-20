/*
 * overflow_stacked_intention.cpp
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
 *
 *
 * AgentSpeak code:
 *
 * !goal1.
 * 
 * +!goal1 <- overflow_stacked_intention_1_1; !goal2; overflow_stacked_intention_1_2.
 * +!goal2 <- overflow_stacked_intention_2_1; !goal3; overflow_stacked_intention_2_2.
 * +!goal3 <- overflow_stacked_intention_3_1; !goal4; overflow_stacked_intention_3_2.
 * +!goal4 <- overflow_stacked_intention_4_1; !goal5; overflow_stacked_intention_4_2.
 * +!goal5 <- overflow_stacked_intention_5_1.
 */

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
  EXPECT_EQ(100, ovflw_stacked_intention_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_empty());

  agent->run();
  EXPECT_EQ(100, ovflw_stacked_intention_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_full());

  agent->run();
  EXPECT_EQ(200, ovflw_stacked_intention_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_empty());

  agent->run();
  EXPECT_EQ(200, ovflw_stacked_intention_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_full());

  agent->run();
  EXPECT_EQ(300, ovflw_stacked_intention_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_empty());

  agent->run();
  EXPECT_EQ(300, ovflw_stacked_intention_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_full());

  agent->run();
  EXPECT_EQ(300, ovflw_stacked_intention_var);
  EXPECT_TRUE(intentions->is_empty());
  EXPECT_TRUE(events->is_empty());
}
