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
  BeliefBase * _belief_base;

public:
  /*
   * PlanBase constructor
   * @param size Size of _plan_base buffer
   * @param beliefs Agent's BeliefBase
   */
  PlanBase(int size, BeliefBase * beliefs);

  virtual ~PlanBase();

  /*
   * Revise and select applicable plan to treat event
   * @param event Event to be processed
   * @result Pointer to applicable plan, NULL otherwise
   */
  Plan * revise(Event * event);
};

#endif /* BDI_PLAN_BASE_H_ */
