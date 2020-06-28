/*
 * belief_operation.cpp
 *
 *  Created on: Jun 9, 2020
 *      Author: Matuzalem Muller
 */

#include "belief_operation.h"

BeliefOperation::BeliefOperation() {}

BeliefOperation::BeliefOperation(Statement statement, EventOperator::EventType event_type) {
  this->_statement = statement;
  this->_operator = event_type;
}

BeliefOperation::~BeliefOperation() {}

IBodyInstruction::BodyType BeliefOperation::get_BodyType() {
  return this->_type;
}

bool BeliefOperation::run_instruction(BeliefBase belief_base, EventBase event_base) {
  return true;
}
