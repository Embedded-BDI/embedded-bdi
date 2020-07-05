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
  IBodyInstruction * instruction = _body->peek();

  bool result = instruction->run_instruction();

  _body->dequeue();

  return result;
}

bool Body::is_finished() {
  return _body->size() == 0;
}
