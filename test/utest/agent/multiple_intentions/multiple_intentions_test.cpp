/*
 * multiple_intentions_test.cpp
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
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
  MultipleIntentions * stacked_intention;

public:
  TMultipleIntentions()
  {
    stacked_intention = new MultipleIntentions();

    beliefs = stacked_intention->get_belief_base();
    events = stacked_intention->get_event_base();
    plans = stacked_intention->get_plan_base();
    intentions = stacked_intention->get_intention_base();

    agent = new Agent(beliefs, events, plans, intentions);
  }

  ~TMultipleIntentions()
  {
    delete this->stacked_intention;
    delete this->agent;
  }
};

TEST_F(TMultipleIntentions, run_multiple_intentions)
{
  EXPECT_EQ(shared_var, 0);
  EXPECT_TRUE(events->is_full());
  EXPECT_TRUE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(shared_var, 1000);
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(shared_var, 1000);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(shared_var, 3000);
  EXPECT_FALSE(events->is_empty());
  EXPECT_TRUE(intentions->is_full());

  agent->run();
  EXPECT_EQ(shared_var, 2000);
  EXPECT_TRUE(events->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(shared_var, 5000);
  EXPECT_TRUE(events->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(shared_var, 5000);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(shared_var, 5000);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(shared_var, 4000);
  EXPECT_TRUE(events->is_empty());
  EXPECT_FALSE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(shared_var, 6000);
  EXPECT_TRUE(events->is_empty());
  EXPECT_TRUE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(shared_var, 6000);
  EXPECT_TRUE(events->is_empty());
  EXPECT_TRUE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(shared_var, 6000);
  EXPECT_TRUE(events->is_empty());
  EXPECT_TRUE(intentions->is_empty());
}
