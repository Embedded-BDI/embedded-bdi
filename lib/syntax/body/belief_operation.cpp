/*
 * belief_operation.cpp
 *
 *  Created on: Jun 9, 2020
 *      Author: Matuzalem Muller
 */

#include "belief_operation.h"

BeliefOperation::BeliefOperation() {}

BeliefOperation::BeliefOperation(Statement stm, EventOperator event_type, BeliefBase * belief_base, EventBase * event_base)
{
  _statement = stm;
  _operator = event_type;
  _belief_base = belief_base;
  _event_base = event_base;
}

BeliefOperation::~BeliefOperation() {}

bool BeliefOperation::run_instruction()
{
  return _event_base->add_event(_operator, _statement);
}
