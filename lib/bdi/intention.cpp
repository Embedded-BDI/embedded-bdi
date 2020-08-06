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
  InstantiatedPlan inst_plan(plan);
  _plans->push(inst_plan);
}

Intention::~Intention()
{
  delete _plans;
}

bool Intention::stack_plan(Plan * plan)
{
  if (!plan)
  {
    return false;
  }

  InstantiatedPlan inst_plan(plan);
  return _plans->push(inst_plan);
}

bool Intention::run_intention(BeliefBase * beliefs, EventBase * events)
{
  if (!_plans->peek())
  {
    return false;
  }

  BodyReturn value = _plans->peek()->run_plan(beliefs, events);

  if(!value.get_value())
  {
    while (!_plans->is_empty())
    {
      _plans->pop();
    }
    return value.get_value();
  }

  if (value.get_value())
  {
    _suspended_by = value.get_event();
    _suspended = true;
  }

  if(_plans->peek()->is_finished())
  {
    _plans->pop();
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
  if (_suspended && events)
  {
    if (events->event_exists(_suspended_by))
    {
      return true;
    }
    else
    {
      this->unsuspend();
      return false;
    }
  }

  return false;
}

bool Intention::is_finished() const
{
  return _plans->is_empty();
}
