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
  _body.reserve(size);
}

Body::~Body() {}

BodyReturn Body::run_body(int index, BeliefBase * beliefs, EventBase * events)
{
  BodyReturn result;

  if (index >= _body.size())
  {
    result = BodyReturn(BodyType::ACTION, false, NULL);
  }
  else
  {
    result = _body.at(index).run_instruction(beliefs, events);
  }

  return result;
}

bool Body::add_instruction(BodyInstruction instruction)
{
  if (_body.size() == _body.capacity())
  {
    return false;
  }

  _body.push_back(instruction);
  return true;
}

int Body::size()
{
  return _body.size();
}
