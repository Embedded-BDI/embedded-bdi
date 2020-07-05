/*
 * plan.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef BDI_PLAN_H_
#define BDI_PLAN_H_

#include "../bdi/event_base.h"
#include "body.h"
#include "context.h"

class Plan
{
private:
  EventOperator _operator;
  Statement _statement;
  Context _context;
  Body _body;

public:
  Plan();

  Plan(EventOperator op, Statement statement, Context context, Body body);

  virtual ~Plan();

  bool run_body(BeliefBase beliefs, EventBase events);

  Body get_body() const
  {
     return _body;
  }

  Context get_context() const
  {
     return _context;
  }

  Statement get_event() const
  {
     return _statement;
  }
};

#endif /* BDI_PLAN_H_ */