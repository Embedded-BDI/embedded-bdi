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
#include "example/configuration.h"

//#include <iostream>
#include <unistd.h>

//bool compile_test = true;

int main()
{
//  int bb_size = 4;
//  int eb_size = 15;
//  int pb_size = 4;
//  int ib_queue_size = 4;
//  int ib_stack_size = 2;

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
//      std::cout << "Is full: " << events->is_full() << std::endl;
      event_to_process = events->get_event();
//      std::cout << event_to_process->get_statement().get_name() << std::endl;
//      std::cout << "Is empty: " << events->is_empty() << std::endl;
//      std::cout << "--------" << std::endl;
      if(event_to_process)
      {
        plan_to_act = plans->revise(event_to_process, beliefs);
        if (!intentions->stack_plan(plan_to_act, event_to_process))
        {
          if (plan_to_act) {
            intentions->add_intention(plan_to_act);
          }
        }
      }
      delete event_to_process;
      event_to_process = nullptr;
    }

    // Runs intention in case there are any
    if (!intentions->is_empty())
    {
      intentions->run_intention_base(beliefs, events);
    }

    sleep(1);

//    if (compile_test == true)
//    {
//      break;
//    }
  }

  return 0;
}
