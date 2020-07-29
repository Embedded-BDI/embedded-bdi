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
  _suspended = false;
  _suspended_by = NULL;
  _plans = new Stack<InstantiatedPlan>(size);
  InstantiatedPlan inst_plan(plan, &_id);
  _plans->push(inst_plan);
}

Intention::~Intention()
{
  delete _plans;
}

bool stack_plan(Plan * plan)
{
  return true;
}

bool Intention::run_intention(BeliefBase * beliefs, EventBase * events)
{
  BodyReturn value = _plans->peek()->run_plan(beliefs, events);
  if (value.get_value() && _plans->peek()->is_finished())
  {
    _plans->pop();

    if (value.get_event())
    {
      _suspended_by = value.get_event();
      _suspended = true;
    }
  }
  return value.get_value();
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

bool Intention::is_suspended(EventBase * events)
{
  if (_suspended)
  {
    if (events->event_exists(_suspended_by))
    {
      return true;
    } else {
      unsuspend();
      return false;
    }
  }
  return false;
}

bool Intention::is_finished() const
{
  return _plans->is_empty();
}
