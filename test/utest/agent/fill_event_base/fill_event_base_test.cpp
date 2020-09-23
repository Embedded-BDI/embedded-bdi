/*
 * fill_event_base_test.cpp
 *
 *  Created on: Sep 12, 2020
 *      Author: Matuzalem Muller
 * 
 * 
 * AgentSpeak code:
 * 
 *   +belief_belief_1_do_nothing_fill_event_base_config <- action_do_nothing.
 *   +belief_belief_2_do_nothing_fill_event_base_config <- action_do_nothing.
 *   +belief_belief_3_do_nothing_fill_event_base_config <- action_do_nothing.
 *   +belief_belief_4_do_nothing_fill_event_base_config <- !goal.
 *   +belief_belief_5_do_nothing_fill_event_base_config <- action_do_nothing.
 *   +belief_belief_6_do_nothing_fill_event_base_config <- action_do_nothing.
 *   +belief_belief_7_do_nothing_fill_event_base_config <- action_do_nothing.
 *   +belief_belief_8_do_nothing_fill_event_base_config <- action_do_nothing.
 *   !+goal <- action_do_nothing.
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

TEST_F(TFillEventBaseSettings, run_fill_event_base)
{
  EXPECT_TRUE(events->is_empty());
  EXPECT_FALSE(events->is_full());
  agent->run();
  EXPECT_FALSE(events->is_empty());
  EXPECT_TRUE(events->is_full());

  for (int i = 8; i > 0; i--)
  {
    Event * event = events->get_event();
    EXPECT_EQ(EventID::get_control_id() - i, event->get_event_id()->get_id());
  }
}
