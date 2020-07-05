/*
 * event_base.h
 *
 *  Created on: May 31, 2020
 *      Author: Matuzalem Muller
 */

#ifndef BDI_EVENT_BASE_H_
#define BDI_EVENT_BASE_H_

#include "event.h"
#include "../lib/circular_buffer.h"

class EventBase {
private:
  CircularBuffer<Event> * _pending_events;

public:
  EventBase(int size);

  virtual ~EventBase();

  bool add_event(Event event);

  bool add_event(EventOperator op, Statement stm);

  Event * get_event();

  bool is_full();

  bool is_empty();
};

#endif /* BDI_EVENT_BASE_H_ */
