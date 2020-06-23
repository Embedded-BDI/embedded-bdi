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

class PlanBase {
private:
  CircularBuffer<Plan> _plans;

public:
  PlanBase();

  virtual ~PlanBase();

  CircularBuffer<Plan> revise(BeliefBase beliefs, Event event);

  Plan select();
};

#endif /* BDI_PLAN_BASE_H_ */
