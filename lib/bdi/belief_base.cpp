/*
 * belief_base.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "belief_base.h"

//BeliefBase::BeliefBase() {}

BeliefBase::BeliefBase(int size) {
  _belief_base = new CircularBuffer<Belief>();
  _belief_base->init(size);
}

BeliefBase::~BeliefBase() {
  delete _belief_base;
}

void BeliefBase::add_belief(Belief belief) {
  if (!_belief_base->is_full())
  {
    _belief_base->enqueue(belief);
  }
}

void BeliefBase::update(EventBase * event_base) {
  for (int i=0; i < _belief_base->size(); i++)
  {
    if (_belief_base->item(i)->update_belief())
    {
      if (!event_base->is_full())
      {
        event_base->add_event(EventOperator::BELIEF_ADDITION, _belief_base->item(i)->get_statement());
      }
    }
  }
}

void BeliefBase::change_belief_state(Statement stm, bool state) {
  for (int i=0; i < _belief_base->size(); i++)
  {
    if (_belief_base->item(i)->get_statement().is_equal_to(stm.get_name()))
    {
      _belief_base->item(i)->change_state(state);
      break;
    }
  }
}
