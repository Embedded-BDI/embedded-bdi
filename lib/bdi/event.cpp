/*
 * event.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "event.h"

Event::Event(EventOperator op, Statement stm)
{
   _operator = op;
   _statement = stm;
}
