/*
 * intention_base.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "intention_base.h"
#include <iostream>

IntentionBase::IntentionBase() {} // @suppress("Class members should be properly initialized")

IntentionBase::IntentionBase(int buffer_size, int stack_size)
{
//  _stack_size = stack_size;
//  _buffer_size = buffer_size;

  _stack_size = stack_size;
  _intention_base = new CircularBuffer<Intention>(buffer_size);

}

IntentionBase::~IntentionBase()
{
  delete _intention_base;
}

//void IntentionBase::add_intention(Intention intention)
//{
//  if (_intention_base.size() <= _buffer_size)
//    _intention_base.push_back(intention);
//}

void IntentionBase::add_intention(Plan * plan)
{
  if (plan == NULL || _intention_base->is_full())
  {
    return;
  }

  Intention * intention = new Intention(plan, _stack_size);
  _intention_base->enqueue(*intention);

//  if ((plan == NULL) || (!_intention_base.size() > _buffer_size))
//  {
//    return;
//  }
//
//  Intention intention(plan, _stack_size);
//  _intention_base.push_back(intention);
}

void IntentionBase::run_intention_base(BeliefBase * beliefs, EventBase * events)
{
  if (_intention_base->is_empty())
  {
    return;
  }

  if (!_intention_base->peek()->run_intention(beliefs, events))
  {
    Intention * intention = _intention_base->peek();
    _intention_base->dequeue();
    delete intention;
  }
  else
  {
    if (_intention_base->peek()->is_finished())
    {
      Intention * intention = _intention_base->peek();
      _intention_base->dequeue();
      delete intention;
    }
    else
    {
      _intention_base->rotate();
    }
  }

//  if (_intention_base.size() == 0)
//  {
//    return;
//  }
//
//  if (!_intention_base.front().run_intention(beliefs, events))
//  {
//    _intention_base.erase(_intention_base.begin());
//  }
//  else
//  {
//    if (_intention_base.front().is_finished())
//    {
//      _intention_base.erase(_intention_base.begin());
//    }
//  }
}

bool IntentionBase::is_empty() {
//  return (_intention_base.size() == 0);
  return _intention_base->is_empty();
}
