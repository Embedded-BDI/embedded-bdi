/*
 * body.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "body.h"

Body::Body(uint8_t size)
{
  _size = size;
  _body.reserve(size);
}

Body::~Body() {}

BodyReturn Body::run_body(uint8_t index, BeliefBase * beliefs, EventBase * events)
{
  BodyReturn result;

  if (index >= _body.size())
  {
    result = BodyReturn(BodyType::ACTION, false, nullptr);
  }
  else
  {
    result = _body.at(index).run_instruction(beliefs, events);
  }

  return result;
}

bool Body::add_instruction(BodyInstruction instruction)
{
  if (_body.size() == _size)
  {
    return false;
  }

  _body.push_back(instruction);
  return true;
}

uint8_t Body::get_size()
{
  return _body.size();
}
