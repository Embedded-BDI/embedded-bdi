/*
 * body.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "body.h"

Body::Body() {}

Body::Body(int size)
{
  _body = new CircularBuffer<BodyInstruction>(size);
}

Body::~Body()
{
  delete _body;
}

BodyReturn Body::run_body(int index, BeliefBase * beliefs, EventBase * events)
{
  if (index >= _body->size())
  {
    BodyReturn result(BodyType::ACTION, false, NULL);
    return result;
  }

  BodyReturn result = _body->item(index)->run_instruction(beliefs, events);
  return result;
}

bool Body::add_instruction(BodyInstruction instruction)
{
  return _body->enqueue(instruction);
}

int Body::size()
{
  return _body->size();
}
