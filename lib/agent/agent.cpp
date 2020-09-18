/*
 * agent.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: Matuzalem Muller
 */

#include "agent.h"

Agent::Agent(BeliefBase * beliefs,
             EventBase * events,
             PlanBase * plans,
             IntentionBase * intentions)
{
  this->beliefs = beliefs;
  this->events = events;
  this->plans = plans;
  this->intentions = intentions;
  this->event_to_process = nullptr;
  this->plan_to_act = nullptr;
}

Agent::~Agent()
{
  delete event_to_process;
}

void Agent::run()
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

  // Runs intention in case there are any
  if (!intentions->is_empty())
  {
    intentions->run_intention_base(beliefs, events, plans);
  }

}
