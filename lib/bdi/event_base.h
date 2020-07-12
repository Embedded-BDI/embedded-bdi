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

class EventBase
{
private:
  CircularBuffer<Event> * _pending_events;

public:
  /*
   * EventBase's constructor
   * @param size Size of EventBase buffer
   */
  EventBase(int size);

  virtual ~EventBase();

  /*
   * Adds event to _pending_events buffer
   * @param event Event to be added
   * @return Returns true if event is added or false otherwise
   */
  bool add_event(Event event);

  /*
   * Creates an event using op and stm and adds event to _pending_events buffer
   * @param event Event to be added
   */
  bool add_event(EventOperator op, Statement stm);

  /*
   * Removes event from _pending_events and returns pointer to removed object
   * @return Pointer to first element from _pending_events. If _pending_events
   * has no elements, the return will be a NULL pointer
   */
  Event * get_event();

  /*
   * Check if event exists in EventBase given event_ud
   * @param event_id EventID to be checked
   * @return true if event with event_id exists in EventBase, false otherwise
   */
  bool event_exists(EventID * event_id);

  bool is_full();

  bool is_empty();
};

#endif /* BDI_EVENT_BASE_H_ */
