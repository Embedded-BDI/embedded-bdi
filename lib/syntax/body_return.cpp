/*
 * body_return.cpp
 *
 *  Created on: Jul 17, 2020
 *      Author: Matuzalem Muller
 */

#include "body_return.h"

BodyReturn::BodyReturn() {} // @suppress("Class members should be properly initialized")

BodyReturn::BodyReturn(BodyType type, bool value, EventID * event)
{
  _type = type;
  _value = value;
  _event = event;
}

BodyReturn::~BodyReturn() {}
