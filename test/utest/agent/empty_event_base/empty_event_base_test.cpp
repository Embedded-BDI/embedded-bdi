/*
 * empty_event_base_test.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "agent/agent.h"
#include "configuration.h"

class TEmptyEventBaseSettings : public ::testing::Test
{
protected:
  Agent * agent;
  BeliefBase * beliefs;
  EventBase * events;
  PlanBase * plans;
  IntentionBase * intentions;
  EmptyEventBaseSettings * empty_event_base_config;

public:
  TEmptyEventBaseSettings()
  {
    empty_event_base_config = new EmptyEventBaseSettings();

    beliefs = empty_event_base_config->get_belief_base();
    events = empty_event_base_config->get_event_base();
    plans = empty_event_base_config->get_plan_base();
    intentions = empty_event_base_config->get_intention_base();

    agent = new Agent(beliefs, events, plans, intentions);
  }

  ~TEmptyEventBaseSettings()
  {
    delete this->empty_event_base_config;
    delete this->agent;
  }
};

TEST_F(TEmptyEventBaseSettings, empty_event_base)
{
  EXPECT_TRUE(intentions->is_empty());
  EXPECT_TRUE(events->is_full());
  EXPECT_FALSE(events->is_empty());
  EXPECT_TRUE(intentions->is_empty());
  agent->run();
  EXPECT_TRUE(intentions->is_empty());
  agent->run();
  EXPECT_TRUE(intentions->is_empty());
  agent->run();
  EXPECT_TRUE(intentions->is_empty());
  agent->run();
  EXPECT_TRUE(intentions->is_empty());
  agent->run();
  EXPECT_TRUE(intentions->is_empty());
  EXPECT_FALSE(events->is_full());
  EXPECT_TRUE(events->is_empty());
}
