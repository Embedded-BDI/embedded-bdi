/*
 * fill_event_base_test.cpp
 *
 *  Created on: Sep 12, 2020
 *      Author: Matuzalem Muller
 *
 *
 * AgentSpeak code:
 *
 *   +!goal1 <- action_do_nothing.
 *   +!goal2 <- action_do_nothing.
 *   +!goal3 <- action_do_nothing.
 *   +!goal4 <- action_do_nothing.
 *   +!goal5 <- action_do_nothing.
 *   +!goal6 <- action_do_nothing.
 *   +!goal7 <- action_do_nothing.
 *   +!goal8 <- action_do_nothing.
 */

#include "gtest/gtest.h"
#include "agent/agent.h"
#include "configuration.h"

class TFillEventBaseSettings : public ::testing::Test
{
protected:
  Agent * agent;
  BeliefBase * beliefs;
  EventBase * events;
  PlanBase * plans;
  IntentionBase * intentions;
  FillEventBaseSettings * fill_event_base_config;

public:
  TFillEventBaseSettings()
  {
    fill_event_base_config = new FillEventBaseSettings();

    beliefs = fill_event_base_config->get_belief_base();
    events = fill_event_base_config->get_event_base();
    plans = fill_event_base_config->get_plan_base();
    intentions = fill_event_base_config->get_intention_base();

    agent = new Agent(beliefs, events, plans, intentions);
  }

  ~TFillEventBaseSettings()
  {
    delete this->fill_event_base_config;
    delete this->agent;
  }
};

TEST_F(TFillEventBaseSettings, fill_event_base)
{
  EXPECT_TRUE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  agent->run();
  EXPECT_FALSE(events->is_empty());
  EXPECT_FALSE(events->is_full());

  Statement stm(1);
  events->add_event(EventOperator::GOAL_ADDITION, stm);
  EXPECT_TRUE(events->is_full());

  for (int i = 8; i > 0; i--)
  {
    Event * event = events->get_event();
    EXPECT_EQ(EventID::get_control_id() - i, event->get_event_id()->get_id());
  }
}
