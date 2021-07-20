/*
 * stacked_intention.cpp
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
 *
 * AgentSpeak code:
 *
 * !goal1.
 * 
 * +!goal1 <- stacked_intention_action_1; !goal2.
 * +!goal2 <- stacked_intention_action_2; !goal3.
 * +!goal3 <- stacked_intention_action_3.
 */

#include "gtest/gtest.h"
#include "agent/agent.h"
#include "configuration.h"

class TStackedIntention : public ::testing::Test
{
protected:
  Agent * agent;
  BeliefBase * beliefs;
  EventBase * events;
  PlanBase * plans;
  IntentionBase * intentions;
  StackedIntention * stacked_intention;

public:
  TStackedIntention()
  {
    stacked_intention = new StackedIntention();

    beliefs = stacked_intention->get_belief_base();
    events = stacked_intention->get_event_base();
    plans = stacked_intention->get_plan_base();
    intentions = stacked_intention->get_intention_base();

    agent = new Agent(beliefs, events, plans, intentions);
  }

  ~TStackedIntention()
  {
    delete this->stacked_intention;
    delete this->agent;
  }
};

TEST_F(TStackedIntention, run_stacked_intention)
{
  EXPECT_TRUE(intentions->is_empty());
  EXPECT_TRUE(events->is_full());

  agent->run();
  EXPECT_EQ(1, stacked_intention_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_empty());

  agent->run();
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_full());

  agent->run();
  EXPECT_EQ(2, stacked_intention_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_empty());

  agent->run();
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_full());

  agent->run();
  EXPECT_EQ(3, stacked_intention_var);
  EXPECT_TRUE(intentions->is_empty());
  EXPECT_TRUE(events->is_empty());

  agent->run();
  EXPECT_EQ(3, stacked_intention_var);
  EXPECT_TRUE(intentions->is_empty());
  EXPECT_TRUE(events->is_empty());

  agent->run();
  EXPECT_EQ(3, stacked_intention_var);
  EXPECT_TRUE(intentions->is_empty());
  EXPECT_TRUE(events->is_empty());
}
