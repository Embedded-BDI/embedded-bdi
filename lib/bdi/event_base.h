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
   * Creates an event using op and stm and adds event to BeliefBase
   * @param event Event to be added to _pending_events buffer
   */
  bool add_event(EventOperator op, Statement stm);

  /*
   * Removes event from EventBase and returns pointer to removed object
   * @return Pointer to first element from _pending_events. If _pending_events
   * has no elements, the return will be a NULL pointer
   */
  Event * get_event();

  /*
   * Returns last event added to EventBase
   * @return Pointer to last event added to _pending_events
   */
  Event * last_event();

  /*
   * Check if event exists in EventBase given event_id
   * @param event_id EventID to be checked
   * @return True if event exists in _pending_events, false otherwise
   */
  bool event_exists(EventID * event_id);

  bool is_full();

  bool is_empty();
};

#endif /* BDI_EVENT_BASE_H_ */
