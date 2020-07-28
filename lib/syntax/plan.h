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
  Context * _context;
  Body * _body;

public:
  Plan();

  /*
   * Plan constructor
   * @param op Triggering event operator
   * @param stm Triggering event statement/name
   * @param context Context
   * @param body Body with instructions
   */
  Plan(EventOperator op, Statement stm, Context * context, Body * body);

  virtual ~Plan();

  /*
   * Run instruction from plan body at specific position
   * @param index Position in body of instruction to be run
   * @param beliefs Agent's BeliefBase
   * @param events Agent's EventBase
   */
  BodyReturn run_body(int index, BeliefBase * beliefs, EventBase * events);

  const EventOperator & get_operator() const
  {
    return _operator;
  }

  Statement * get_statement()
  {
     return &_statement;
  }

  Context * get_context()
  {
     return _context;
  }

  Body * get_body()
  {
     return _body;
  }
};

#endif /* BDI_PLAN_H_ */
