/*
 * goal.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: Matuzalem Muller
 */

#include "goal.h"

Goal::Goal() {} // @suppress("Class members should be properly initialized")

Goal::Goal(Statement stm, EventOperator event_type, BeliefBase * belief_base, EventBase * event_base)
{
  _operator = event_type;
  _statement = stm;
  _belief_base = belief_base;
  _event_base = event_base;
}

Goal::~Goal() {}

bool Goal::run_instruction()
{
  return _event_base->add_event(_operator, _statement);
}


