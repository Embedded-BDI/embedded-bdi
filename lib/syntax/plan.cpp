/*
 * plan.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "plan.h"

Plan::Plan() {}

Plan::Plan(EventOperator op, Statement * stm, Context * context, Body * body)
{
  _operator = op;
  _statement = stm;
  _context = context;
  _body = body;
}

Plan::~Plan() {}

BodyReturn Plan::run_body(int index, BeliefBase * beliefs, EventBase * events)
{
  BodyReturn result = _body->run_body(index, beliefs, events);
  return result;
}
