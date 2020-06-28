/*
 * event.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_EVENT_H_
#define SYNTAX_EVENT_H_

#include "../syntax/event_operator.h"
#include "../syntax/statement.h"

class Event {
private:
   EventOperator::EventType _operator;
   Statement _statement;

public:
   Event();

   Event(EventOperator::EventType op, Statement stm);

   virtual ~Event();

   const EventOperator::EventType & get_operator() const {
      return this->_operator;
   }

   const Statement & get_statement() const {
      return this->_statement;
   }
};


#endif /* SYNTAX_EVENT_H_ */
