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

  Plan(EventOperator op, Statement stm, Context context, Body body);

  virtual ~Plan();

  BodyReturn run_body(int index, BeliefBase * beliefs, EventBase * events);

  EventOperator * get_operator ()
  {
    return &_operator;
  }

  Statement * get_statement()
  {
     return &_statement;
  }

  Context * get_context()
  {
     return &_context;
  }

  Body * get_body()
  {
     return &_body;
  }
};

#endif /* BDI_PLAN_H_ */
