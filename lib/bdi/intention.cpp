/*
 * intention.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "intention.h"

Intention::Intention(Plan * plan, int size)
{
  _size = size;
  _suspended = false;
  _suspended_by = nullptr;
  _plans.reserve(size);
  InstantiatedPlan inst_plan(plan);
  _plans.push_back(inst_plan);
}

Intention::~Intention() {}

bool Intention::stack_plan(Plan * plan)
{
  if (!plan || (_plans.size() == _size))
  {
    return false;
  }

  InstantiatedPlan inst_plan(plan);
  _plans.push_back(inst_plan);

  this->unsuspend();

  return true;
}

bool Intention::run_intention(BeliefBase * beliefs, EventBase * events)
{
  if (_plans.size() == 0 || this->is_suspended())
  {
    return false;
  }

  BodyReturn value = _plans.back().run_plan(beliefs, events);

  // If instruction execution fails, remove all InstantiatedPlans from the plan
  // stack and return false
  if(!value.get_value())
  {
    while (_plans.size() > 0)
    {
      _plans.pop_back();
    }
    return value.get_value();
  }
  else
  {
    if (value.get_event())
    {
      this->suspend(value.get_event());
    }
    else
    {
      if (_plans.back().is_finished())
      {
        _plans.pop_back();
      }

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
  _suspended_by = nullptr;
}

bool Intention::is_suspended_by(Event * event)
{
  if (!_suspended || !event)
  {
    return false;
  }
  else
  {
    if (this->_suspended_by->is_equal(event->get_event_id()))
    {
      return true;
    }
  }

  return false;
}

bool Intention::is_finished() const
{
  return (_plans.size() == 0);
}

bool Intention::is_suspended()
{
  return _suspended;
}

EventID * Intention::event()
{
  return _suspended_by;
}
