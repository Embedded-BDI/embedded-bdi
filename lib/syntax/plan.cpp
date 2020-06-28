/*
 * plan.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "plan.h"

Plan::Plan() {
  // TODO Auto-generated constructor stub

}

Plan::Plan(EventOperator op, Statement statement, Context context, Body body){
   this->_operator = op;
   this->_statement = statement;
   this->_context = context;
   this->_body = body;
}

Plan::~Plan() {
  // TODO Auto-generated destructor stub
}

bool Plan::run_body(BeliefBase beliefs, EventBase events) {
  return this->_body.run_body(beliefs, events);
}

Plan Plan::clone() {
  Plan plan(this->_operator, this->_statement, this->_context, this->_body);
  return plan;
}
