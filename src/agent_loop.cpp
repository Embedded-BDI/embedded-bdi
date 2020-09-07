/*
 * agent_loop.cpp
 *
 *  Created on: Jun 28, 2020
 *      Author: Matuzalem Muller
 */

#include "../lib/bdi/belief_base.h"
#include "../lib/bdi/event_base.h"
#include "../lib/bdi/plan_base.h"
#include "../lib/bdi/intention_base.h"
#include "config/configuration.h"

#include <unistd.h>

int main()
{
  AgentSettings agent;

  BeliefBase * beliefs = agent.get_belief_base();
  EventBase * events = agent.get_event_base();
  PlanBase * plans = agent.get_plan_base();
  IntentionBase * intentions = agent.get_intention_base();

  Event * event_to_process;
  Plan * plan_to_act;

  while(true)
  {
    // Update beliefs
    beliefs->update(events);

    // Checks if there are events to be processed
    if (!events->is_empty())
    {
      event_to_process = events->get_event();
      if(event_to_process)
      {
        plan_to_act = plans->revise(event_to_process, beliefs);
        if (plan_to_act) {
          intentions->add_intention(plan_to_act, event_to_process);
        }
      }
      delete event_to_process;
      event_to_process = nullptr;
    }

    // Create scheduler class
    // Create class for queue
    // - push_back
    // - push_front
    // - rotate

    // Runs intention in case there are any
    if (!intentions->is_empty())
    {
      intentions->run_intention_base(beliefs, events, plans);
    }

    sleep(1);
  }

  return 0;
}
