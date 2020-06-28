/*
 * event.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "event.h"

Event::Event() {} // @suppress("Class members should be properly initialized")

Event::Event(EventOperator::EventType op, Statement stm){
   this->_operator = op;
   this->_statement = stm;
}

Event::~Event() {}
