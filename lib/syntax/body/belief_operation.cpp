/*
 * belief_operation.cpp
 *
 *  Created on: Jun 9, 2020
 *      Author: Matuzalem Muller
 */

#include "belief_operation.h"

BeliefOperation::BeliefOperation() {}

BeliefOperation::BeliefOperation(Statement stm, EventOperator event_type)
{
  _statement = stm;
  _operator = event_type;
}

BeliefOperation::~BeliefOperation() {}

bool BeliefOperation::run_instruction(BeliefBase * belief_base, EventBase * event_base)
{
  return event_base->add_event(_operator, _statement);
}
