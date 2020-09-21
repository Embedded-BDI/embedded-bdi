/*
 * simple_intention_test.cpp
 *
 *  Created on: Sep 13, 2020
 *      Author: Matuzalem Muller
 *
 *
 * AgentSpeak code:
 *
 *   !goal1.
 *
 *   +!goal1 <- action_1_simple_intention; action_2_simple_intention; action_3_simple_intention; action_4_simple_intention; action_5_simple_intention.
 */

#include "common_lib.h"
#include "gtest/gtest.h"
#include "agent/agent.h"
#include "configuration.h"

class TSimpleIntention : public ::testing::Test
{
protected:
  Agent * agent;
  BeliefBase * beliefs;
  EventBase * events;
  PlanBase * plans;
  IntentionBase * intentions;
  SimpleIntention * simple_intention;

public:
  TSimpleIntention()
  {
    simple_intention = new SimpleIntention();

    beliefs = simple_intention->get_belief_base();
    events = simple_intention->get_event_base();
    plans = simple_intention->get_plan_base();
    intentions = simple_intention->get_intention_base();

    agent = new Agent(beliefs, events, plans, intentions);
  }

  ~TSimpleIntention()
  {
    delete this->simple_intention;
    delete this->agent;
  }
};

TEST_F(TSimpleIntention, run_simple_intention)
{
  EXPECT_TRUE(intentions->is_empty());
  EXPECT_TRUE(events->is_full());

  agent->run();
  EXPECT_EQ(1, shared_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_empty());

  agent->run();
  EXPECT_EQ(2, shared_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_empty());

  agent->run();
  EXPECT_EQ(3, shared_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_empty());

  agent->run();
  EXPECT_EQ(4, shared_var);
  EXPECT_TRUE(intentions->is_full());
  EXPECT_TRUE(events->is_empty());

  agent->run();
  EXPECT_EQ(5, shared_var);
  EXPECT_TRUE(intentions->is_empty());
  EXPECT_TRUE(events->is_empty());

  agent->run();
  agent->run();
  agent->run();
  agent->run();
  agent->run();
  EXPECT_EQ(5, shared_var);
  EXPECT_TRUE(intentions->is_empty());
  EXPECT_TRUE(events->is_empty());
}
