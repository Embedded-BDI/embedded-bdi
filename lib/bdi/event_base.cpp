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

  if (!_pending_events->is_empty())
  {
    _pending_events->dequeue();
  }

  return event;
}

Event * EventBase::last_event()
{
  return _pending_events->item(_pending_events->size()-1);
}


bool EventBase::event_exists(EventID * event_id)
{
  for (int i = 0; i < _pending_events->size(); i++)
  {
    if (event_id->is_equal(*_pending_events->item(i)->get_event_id()))
    {
      return true;
    }
  }
  return false;
}


bool EventBase::is_full()
{
  return _pending_events->is_full();
}

bool EventBase::is_empty()
{
  return _pending_events->is_empty();
}
