/*
 * agent_loop.cpp
 *
 *  Created on: Jun 28, 2020
 *      Author: Matuzalem Muller
 */

#include <iostream>
#include "bdi/belief_base.h"
#include "bdi/event_base.h"
#include "bdi/plan_base.h"
#include "bdi/intention_base.h"

using namespace std;

bool compile_test = true;

int main() {
  int bb_size = 4;
  int eb_size = 4;
  int pb_size = 4;
  int ib_queue_size = 4;
  int ib_stack_size = 2;

  BeliefBase beliefs(bb_size);
  EventBase events(eb_size);
  PlanBase plans(pb_size, &beliefs);
  IntentionBase intentions(ib_queue_size, ib_stack_size, &beliefs, &events);

  Event * event_to_process;
  Plan * plan_to_act;

  while(true)
  {
    beliefs.update(&events);
    if (!events.is_empty())
    {
      event_to_process = events.get_event();
      if(event_to_process)
      {
        plan_to_act = plans.revise(event_to_process);
        if (plan_to_act) {
          intentions.add_intention(plan_to_act);
        }
      }
    }
    intentions.run_intention_base();

    if (compile_test == true)
    {
      std::cout << "Compilation successful!" << std::endl;
      break;
    }
  }

  return 0;
}



//// ---- Alternate main function using new allocator
//int main() {
//  int bb_size = 4;
//  int eb_size = 4;
//  int pb_size = 4;
//  int ib_queue_size = 4;
//  int ib_stack_size = 2;
//
//  BeliefBase * beliefs = new BeliefBase(bb_size);
//  EventBase * events = new EventBase(eb_size);
//  PlanBase * plans = new PlanBase(pb_size, beliefs);
//  IntentionBase * intentions = new IntentionBase(ib_queue_size, ib_stack_size, beliefs, events);
//
//  Event * event_to_process;
//  Plan * plan_to_act;
//
//  while(true)
//  {
//    beliefs->update(events);
//    if (!events->is_empty())
//    {
//      event_to_process = events->get_event();
//      if(event_to_process)
//      {
//        plan_to_act = plans->revise(event_to_process);
//        if (plan_to_act) {
//          intentions->add_intention(plan_to_act);
//        }
//      }
//    }
//    intentions->run_intention_base();
//
//    if (compile_test == true)
//    {
//      std::cout << "Compilation successful!" << std::endl;
//      break;
//    }
//  }
//
//  return 0;
//}
