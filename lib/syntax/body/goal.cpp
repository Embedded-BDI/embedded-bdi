/*
 * goal.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: Matuzalem Muller
 */

#include "goal.h"

Goal::Goal() {} // @suppress("Class members should be properly initialized")

Goal::Goal(EventOperator::EventType op, Statement stm) {
  this->_operator = op;
  this->_statement = stm;
}

Goal::~Goal() {}

bool Goal::run_instruction(BeliefBase belief_base, EventBase event_base) {
  return event_base.add_event(this->_operator, this->_statement);
}

IBodyInstruction::BodyType Goal::get_BodyType() {
  return this->_type;
}
