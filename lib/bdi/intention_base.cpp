/*
 * intention_base.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "intention_base.h"

IntentionBase::IntentionBase() {} // @suppress("Class members should be properly initialized")

IntentionBase::IntentionBase(int buffer_size, int stack_size, BeliefBase * beliefs, EventBase * events)
{
  _buffer_size = buffer_size;
  _stack_size = stack_size;
  _belief_base = beliefs;
  _event_base = events;
  _intention_base = new CircularBuffer<Intention>(_buffer_size);
}

IntentionBase::~IntentionBase() {}

void IntentionBase::add_intention(Plan * plan)
{
  if (plan && !_intention_base->is_full())
  {
    Intention intention(plan, _stack_size);
    _intention_base->enqueue(intention);
  }
}

void IntentionBase::run_intention_base()
{
  if (!_intention_base->is_empty())
  {
    Intention * intention = _intention_base->peek();
    intention->run_intention(_belief_base, _event_base);

    _intention_base->dequeue();

    if (!intention->is_finished())
    {
      _intention_base->enqueue(*intention);
    }
  }
}

bool IntentionBase::is_empty() {
  return _intention_base->is_empty();
}
