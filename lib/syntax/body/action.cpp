/*
 * action.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: Matuzalem Muller
 */

#include "action.h"

Action::Action() {}

Action::Action(Statement statement, bool (*take_action_function)()) {
  this->_statement = statement;
  this->_take_action = take_action_function;
}

Action::~Action() {}

bool Action::run_instruction(BeliefBase belief_base, EventBase event_base) {
  return this->_take_action();
}

IBodyInstruction::BodyType Action::get_BodyType() {
  return this->_type;
}
