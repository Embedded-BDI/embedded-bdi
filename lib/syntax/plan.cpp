/*
 * plan.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "plan.h"

Plan::Plan(EventOperator op, Statement stm, Context * context, Body * body)
{
  _operator = op;
  _statement = stm;
  _context = context;
  _body = body;
}

Plan::~Plan() {}

BodyReturn Plan::run_body(std::uint8_t index, BeliefBase * beliefs, EventBase * events)
{
  return _body->run_body(index, beliefs, events);;
}
