/*
 * belief_base.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "belief_base.h"

//BeliefBase::BeliefBase() {}

BeliefBase::BeliefBase(int size) {
  this->_belief_base.init(size);
  this->_size = size;
}

BeliefBase::~BeliefBase() {}

void BeliefBase::update(EventBase event_base){
  for (int i=0; i < this->_size; i++)
  {
    if (this->_belief_base.item(i)->update_belief())
    {
      if (!event_base.is_full())
      {
        event_base.add_event(EventOperator::BELIEF_ADDITION, this->_belief_base.item(i)->get_statement());
      }
    }
  }
}

void BeliefBase::change_belief_state(Statement stm, bool state) {
  for (int i=0; i < this->_size; i++)
  {
    if (this->_belief_base.item(i)->get_statement().is_equal_to(stm.get_name()))
    {
      this->_belief_base.item(i)->change_state(state);
      break;
    }
  }
}
