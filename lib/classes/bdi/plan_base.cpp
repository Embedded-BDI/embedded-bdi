/*
 * plan_base.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "plan_base.h"

PlanBase::PlanBase() {
  // TODO Auto-generated constructor stub

}

PlanBase::~PlanBase() {
  // TODO Auto-generated destructor stub
}

CircularBuffer<Plan> PlanBase::revise(BeliefBase beliefs, Event event){} // @suppress("No return")

Plan PlanBase::select() {}
