/*
 * event.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "event.h"

Event::Event() {} // @suppress("Class members should be properly initialized")

Event::Event(EventOperator op, Statement stm){
   _operator = op;
   _statement = stm;
}

Event::~Event() {}
