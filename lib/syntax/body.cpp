/*
 * body.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "body.h"

Body::Body() {}

Body::~Body() {}

bool Body::run_body(BeliefBase beliefs, EventBase events) {
  IBodyInstruction instruction = this->_body.peek();
  bool result = instruction.run_instruction(beliefs, events);

  this->_body.dequeue();

  return result;
}

bool Body::is_finished() {
  return this->_body.size() == 0;
}
