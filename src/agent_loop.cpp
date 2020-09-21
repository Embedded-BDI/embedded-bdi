/*
 * agent_loop.cpp
 *
 *  Created on: Jun 28, 2020
 *      Author: Matuzalem Muller
 */

#include "agent/agent.h"
#include "config/configuration.h"

#include <unistd.h>

int main()
{
  AgentSettings agent_settings;

  BeliefBase * beliefs = agent_settings.get_belief_base();
  EventBase * events = agent_settings.get_event_base();
  PlanBase * plans = agent_settings.get_plan_base();
  IntentionBase * intentions = agent_settings.get_intention_base();

  Agent agent(beliefs, events, plans, intentions);

  while(true)
  {
    agent.run();
    usleep(200000);
  }

  return 0;
}
