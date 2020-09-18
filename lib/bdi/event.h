/*
 * event.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_EVENT_H_
#define SYNTAX_EVENT_H_

#include "../syntax/statement.h"
#include "../syntax/event_operator.h"
#include "../lib/event_id.h"
#include <cstdint>

/**
 * Represents events for belief updates and plan adoption/drop.
 */
class Event
{
private:
  EventOperator _operator;
  Statement _statement;
  /// Event identifier
  EventID _id;

public:
  /**
   * Event constructor
   * @param op Event's EventOperator
   * @param stm Event's Statement
   */
  Event(EventOperator op, Statement stm);

  const EventOperator & get_operator() const
  {
    return _operator;
  }

  const Statement & get_statement() const
  {
    return _statement;
  }

  /**
   * Unique ID given to Event
   * @return returns pointer to EventID
   */
  EventID * get_event_id()
  {
    return &_id;
  }
};


#endif /* SYNTAX_EVENT_H_ */
