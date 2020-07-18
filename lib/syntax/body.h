/*
 * body.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_BODY_H_
#define SYNTAX_BODY_H_

#include "body/body_instruction.h"
#include "../bdi/belief_base.h"
#include "../bdi/event_base.h"
#include "../lib/circular_buffer.h"

class Body
{
  CircularBuffer<IBodyInstruction> * _body;

public:
  Body();

  virtual ~Body();

  BodyReturn run_body(int index, BeliefBase * beliefs, EventBase * events);

  bool add_instruction(IBodyInstruction instruction);

  int size();
};

#endif /* SYNTAX_BODY_H_ */
