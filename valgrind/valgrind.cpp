/*
 * valgrind.cpp
 *
 *  Created on: Sep 24, 2020
 *      Author: Matuzalem Muller
 */

#include "agent/agent.h"
#include "config/configuration.h"

#define MAX_ITERATION 100

int main()
{
  AgentSettings agent_settings;

  BeliefBase * beliefs = agent_settings.get_belief_base();
  EventBase * events = agent_settings.get_event_base();
  PlanBase * plans = agent_settings.get_plan_base();
  IntentionBase * intentions = agent_settings.get_intention_base();

  Agent agent(beliefs, events, plans, intentions);

  for (int i = 0; i < MAX_ITERATION; i++)
  {
    agent.run();
  }

  return 0;
}
