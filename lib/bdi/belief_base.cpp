/*
 * belief_base.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "belief_base.h"

BeliefBase::BeliefBase(int size)
{
  _belief_base = new CircularBuffer<Belief>(size);
}

BeliefBase::~BeliefBase()
{
  delete _belief_base;
}

bool BeliefBase::add_belief(Belief belief)
{
  if (!_belief_base->is_full())
  {
    _belief_base->enqueue(belief);
    return true;
  } else {
    return false;
  }
}

void BeliefBase::update(EventBase * event_base)
{
  for (int i=0; i < _belief_base->size(); i++)
  {
    if (_belief_base->item(i)->update_belief())
    {
      if (!event_base->is_full())
      {
        if (_belief_base->item(i)->get_state())
        {
          // Add Event for BELIEF_ADDITION if belief is changed to true
          event_base->add_event(
            EventOperator::BELIEF_ADDITION, _belief_base->item(i)->get_statement()
          );
        } else {
          // Add Event for BELIEF_DELETION if belief is changed to false
          event_base->add_event(
            EventOperator::BELIEF_DELETION, _belief_base->item(i)->get_statement()
          );
        }
      }
    }
  }
}

bool BeliefBase::change_belief_state(Statement stm, bool state)
{
  for (int i=0; i < _belief_base->size(); i++)
  {
    if (_belief_base->item(i)->get_statement().is_equal_to(stm.get_name()))
    {
      _belief_base->item(i)->change_state(state);
      return true;
    }
  }
  return false;
}
