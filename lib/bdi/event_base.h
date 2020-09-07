/*
 * event_base.h
 *
 *  Created on: May 31, 2020
 *      Author: Matuzalem Muller
 */

#ifndef BDI_EVENT_BASE_H_
#define BDI_EVENT_BASE_H_

#include "event.h"
#include <vector>
#include <cstdint>

class EventBase
{
private:
  /// Vector of Events
  std::vector <Event> _pending_events;
  /// Max size of _belief_base vector
  std::uint8_t _size;

public:
  /**
   * EventBase's constructor
   * @param size Size of EventBase buffer
   */
  EventBase(std::uint8_t size);

  virtual ~EventBase();

  /**
   * Creates an Event using op and stm and adds Event _pending_events
   * @param op EventOperator of Event to be added to _pending_events
   * @param stm Statement of Event to be added to _pending_events
   */
  bool add_event(EventOperator op, Statement stm);

  /**
   * Removes Event from _pending_events and returns pointer to removed Event
   * @return Pointer to first element from _pending_events. If _pending_events
   * has no elements, return is nullptr
   */
  Event * get_event();

  /**
   * Returns last Event added to EventBase
   * @return Pointer to last Event added to _pending_events
   */
  Event * last_event();

  /**
   * Check if Event exists in EventBase given event_id
   * @param event_id EventID to be checked
   * @return True if Event exists in _pending_events, false otherwise
   */
  bool event_exists(EventID * event_id);

  /**
   * Returns if EventBase is full based on _pending_events size
   * @return true if EventBase is full, false otherwise
   */
  bool is_full();

  /**
   * Returns if EventBase is empty based on _pending_events size
   * @return true if EventBase is empty, false otherwise
   */
  bool is_empty();
};

#endif /* BDI_EVENT_BASE_H_ */
