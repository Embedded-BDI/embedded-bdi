/*
 * event_base.cpp
 *
 *  Created on: May 31, 2020
 *      Author: Matuzalem Muller
 */

#include "event_base.h"

EventBase::EventBase(int size)
{
  _pending_events = new CircularBuffer<Event>(size);
}

EventBase::~EventBase()
{
  delete _pending_events;
}

bool EventBase::add_event(Event event)
{
  if (!_pending_events->is_full())
  {
    _pending_events->enqueue(event);
    return true;
  } else {
    return false;
  }
}

bool EventBase::add_event(EventOperator op, Statement stm)
{
  if (!_pending_events->is_full())
  {
    Event event(op,stm);
    _pending_events->enqueue(event);
    return true;
  } else {
    return false;
  }
}

Event * EventBase::get_event()
{
  Event * event = _pending_events->peek();
  _pending_events->dequeue();

  return event;
}

bool EventBase::is_full()
{
  return _pending_events->is_full();
}

bool EventBase::is_empty()
{
  return _pending_events->is_empty();
}
