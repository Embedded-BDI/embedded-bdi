/*
 * failed_intention_test.cpp
 *
 *  Created on: Sep 17, 2020
 *      Author: Matuzalem Muller
 *
 * AgentSpeak code:
 *
 * !goal1.
 * !goal2.
 * 
 * +!goal1 <- failed_intention_return_false.
 * -!goal1 <- failed_intention_deletion_1.
 * 
 * +!goal2 <- failed_intention_return_true; !goal3; failed_intention_return_true.
 * 
 * +!goal3 <- failed_intention_return_true; !goal4.
 * 
 * +!goal4 <- failed_intention_return_false.
 * -!goal4 <- failed_intention_deletion_1.
 * -!goal4 <- failed_intention_deletion_2.
 */ 

#include "gtest/gtest.h"
#include "agent/agent.h"
#include "configuration.h"

class TFailedIntention : public ::testing::Test
{
protected:
  Agent * agent;
  BeliefBase * beliefs;
  EventBase * events;
  PlanBase * plans;
  IntentionBase * intentions;
  FailedIntention * failed_intention;

public:
  TFailedIntention()
  {
    failed_intention = new FailedIntention();

    beliefs = failed_intention->get_belief_base();
    events = failed_intention->get_event_base();
    plans = failed_intention->get_plan_base();
    intentions = failed_intention->get_intention_base();

    agent = new Agent(beliefs, events, plans, intentions);
  }

  ~TFailedIntention()
  {
    delete agent;
    delete failed_intention;
  }
};

TEST_F(TFailedIntention, run_failed_intention)
{
  EXPECT_TRUE(events->is_full());
  EXPECT_TRUE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(2, failed_intention_shared_var);
  EXPECT_TRUE(events->is_full());
  EXPECT_TRUE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(1, failed_intention_shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(1, failed_intention_shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_TRUE(intentions->is_full());

  agent->run();
  EXPECT_EQ(-100, failed_intention_shared_var);
  EXPECT_TRUE(events->is_empty());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(1, failed_intention_shared_var);
  EXPECT_TRUE(events->is_empty());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(1, failed_intention_shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_FALSE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(2, failed_intention_shared_var);
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_TRUE(intentions->is_empty());
  EXPECT_FALSE(intentions->is_full());

  agent->run();
  EXPECT_EQ(-100, failed_intention_shared_var);
  EXPECT_TRUE(events->is_empty());
  EXPECT_TRUE(intentions->is_empty());

  agent->run();
  EXPECT_EQ(-100, failed_intention_shared_var);
  EXPECT_TRUE(events->is_empty());
  EXPECT_TRUE(intentions->is_empty());
}
