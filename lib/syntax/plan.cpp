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
   _operator = op;
   _statement = statement;
   _context = context;
   _body = body;
}

Plan::~Plan() {
  // TODO Auto-generated destructor stub
}

bool Plan::run_body(BeliefBase beliefs, EventBase events) {
  return _body.run_body(beliefs, events);
}
