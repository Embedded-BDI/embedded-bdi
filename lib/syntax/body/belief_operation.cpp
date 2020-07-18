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

BodyReturn BeliefOperation::run_instruction(BeliefBase * belief_base, EventBase * event_base)
{
  if (event_base->add_event(_operator, _statement))
  {
    BodyReturn result(_type, true, event_base->last_event()->get_event_id());
    return result;
  } else {
    BodyReturn result(_type, false, NULL);
    return result;
  }
}
