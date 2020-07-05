/*
 * intention.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef BDI_INTENTION_H_
#define BDI_INTENTION_H_

#include "belief_base.h"
#include "../lib/stack.h"
#include "../syntax/plan.h"

class Intention
{
private:
  Stack<Plan> * _plans;         // NAP EH UMA STACK NORMAL, EH PRA SER POINTEIROS
  Stack<int> * _plan_index;
  int _size;
  bool _suspended;

public:
  Intention();

  /*
   * Intention constructor
   * @param plan Pointer to plan to be instantiated as intention
   * @param size Size of _plans stack
   */
  Intention(Plan * plan, int size);

  virtual ~Intention();

  /*
   * Stack plan in _plan stack
   * @param plan Plan to be stacked
   * @return true if plan is added, false otherwise. False means that size of
   * _plans stack was exceeded and intention should likely be dropped
   */
  bool stack_plan(Plan * plan);

  /*
   * Run one instruction from plan from the top of _plans stack
   * @param beliefs Agent's BeliefBase
   * @param events Agent's EventBase
   */
  bool run_intention(BeliefBase * beliefs, EventBase * events);

  /*
   * Suspend intention. Intentions should be suspended when the instruction
   * ran on run_intention is added to the EventBase and no further instructions
   * can be run without processing the event first
   */
  void suspend();

  /*
   * Unsuspend intention so instructions can be run
   */
  void unsuspend();

  bool is_suspended() const;

  bool is_finished() const;
};

#endif /* BDI_INTENTION_H_ */
