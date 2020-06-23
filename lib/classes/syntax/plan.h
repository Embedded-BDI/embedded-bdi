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
#include "event_operator.h"
#include "statement.h"

class Plan {
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

  Plan clone();

  Body get_body() const {
     return this->_body;
  }

  Context get_context() const {
     return this->_context;
  }

  Statement get_event() const {
     return this->_statement;
  }
};

#endif /* BDI_PLAN_H_ */
