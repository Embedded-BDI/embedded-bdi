/*
 * plan_base.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef BDI_PLAN_BASE_H_
#define BDI_PLAN_BASE_H_

#include "belief_base.h"
#include "event.h"
#include "../lib/circular_buffer.h"
#include "../syntax/plan.h"

class PlanBase
{
private:
  CircularBuffer<Plan> * _plan_base;

public:
  /*
   * PlanBase constructor
   * @param size Size of _plan_base buffer
   */
  PlanBase(int size);

  virtual ~PlanBase();

  /*
   * Adds plan to plan base
   * @param plan Plan to be added
   * @return true is plan is added, false otherwise
   */
  bool add_plan(Plan plan);

  /*
   * Revise and select applicable plan to treat event
   * @param event Event to be processed
   * @result Pointer to applicable plan, NULL otherwise
   */
  Plan * revise(Event * event, BeliefBase * belief_base);

  int get_size()
  {
    return _plan_base->size();
  }
};

#endif /* BDI_PLAN_BASE_H_ */
