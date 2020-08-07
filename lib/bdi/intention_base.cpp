/*
 * intention_base.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "intention_base.h"

IntentionBase::IntentionBase(int buffer_size, int stack_size)
{
  _buffer_size = buffer_size;
  _stack_size = stack_size;
  _intention_base.reserve(buffer_size);

}

IntentionBase::~IntentionBase() {}

void IntentionBase::add_intention(Plan * plan)
{
  if (plan == nullptr || (_intention_base.size() == _intention_base.capacity()))
  {
    return;
  }

  Intention * intention = new Intention(plan, _stack_size);
  _intention_base.insert(_intention_base.begin(), *intention);
}

void IntentionBase::run_intention_base(BeliefBase * beliefs, EventBase * events)
{
  if (_intention_base.size() == 0)
  {
    return;
  }

  if (!_intention_base.back().run_intention(beliefs, events))
  {
    _intention_base.pop_back();
  }
  else
  {
    if (_intention_base.back().is_finished())
    {
      _intention_base.pop_back();
    }
    else
    {
      _intention_base.push_back(_intention_base.front());
      _intention_base.erase(_intention_base.begin());
    }
  }
}

bool IntentionBase::is_empty() {
  return (_intention_base.size() == 0);
}
