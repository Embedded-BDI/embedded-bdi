/*
 * plan_base.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "plan_base.h"

PlanBase::PlanBase(int size, BeliefBase * beliefs)
{
  _belief_base = beliefs;
  _plan_base = new CircularBuffer<Plan>(size);
}

PlanBase::~PlanBase()
{
  delete _plan_base;
}

Plan * PlanBase::revise(Event * event)
{
  return NULL;
}
