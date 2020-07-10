/*
 * event.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_EVENT_H_
#define SYNTAX_EVENT_H_

#include "../lib/event_id.h"
#include "../syntax/statement.h"
#include "../syntax/event_operator.h"

class Event
{
private:
   EventOperator _operator;
   Statement _statement;
   EventID _id;

public:
   Event();

   Event(EventOperator op, Statement stm);

   virtual ~Event();

   const EventOperator & get_operator() const
   {
      return _operator;
   }

   const Statement & get_statement() const
   {
      return _statement;
   }
};


#endif /* SYNTAX_EVENT_H_ */
