/*
 * body.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_BODY_H_
#define SYNTAX_BODY_H_

#include "body_instruction.h"
#include "../bdi/belief_base.h"
#include "../bdi/event_base.h"
#include "../lib/circular_buffer.h"

class Body
{
  CircularBuffer<IBodyInstruction> * _body;

public:
  Body();
  virtual ~Body();

  bool run_body(BeliefBase beliefs, EventBase events);

  bool is_finished();
};

#endif /* SYNTAX_BODY_H_ */
