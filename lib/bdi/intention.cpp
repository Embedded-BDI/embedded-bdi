/*
 * intention.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "intention.h"

Intention::Intention() {} // @suppress("Class members should be properly initialized")

Intention::Intention(Plan * plan, int size)
{
  _size = size;
  _plan_index = new Stack<int>(size);
  _plans = new Stack<Plan>(size);
  _plans->push(*plan);
  _suspended = false;
  _suspended_by = NULL;
}

Intention::~Intention()
{
  delete _plans;
  delete _plan_index;
}

bool stack_plan(Plan * plan)
{
  return true;
}

bool Intention::run_intention(BeliefBase * beliefs, EventBase * events)
{
  return true;
}

void Intention::suspend(EventID * event_id)
{
  _suspended = true;
  _suspended_by = event_id;
}

void Intention::unsuspend()
{
  _suspended = false;
  _suspended_by = NULL;
}

bool Intention::is_suspended() const
{
  return _suspended;
}

bool Intention::is_finished() const
{
  return true;
}
