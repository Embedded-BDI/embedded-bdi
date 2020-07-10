/*
 * plan_base.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "plan_base.h"

PlanBase::PlanBase(int size)
{
  _plan_base = new CircularBuffer<Plan>(size);
}

PlanBase::~PlanBase()
{
  delete _plan_base;
}

bool PlanBase::add_plan(Plan plan)
{
  if (!_plan_base->is_full())
  {
    _plan_base->enqueue(plan);
    return true;
  } else {
    return false;
  }
}

Plan * PlanBase::revise(Event * event, BeliefBase * belief_base)
{
  return NULL;
}
