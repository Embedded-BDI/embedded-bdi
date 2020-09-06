/*
 * event_base.cpp
 *
 *  Created on: May 31, 2020
 *      Author: Matuzalem Muller
 */

#include "event_base.h"

EventBase::EventBase(int size)
{
  _size = size;
  _pending_events.reserve(size);
}

EventBase::~EventBase() {}

bool EventBase::add_event(EventOperator op, Statement stm)
{
  if (this->is_full())
  {
    return false;
  }

  Event event(op,stm);
  _pending_events.insert(_pending_events.begin(), event);
  return true;
}

Event * EventBase::get_event()
{
  if (this->is_empty())
  {
    return nullptr;
  }

  Event * event = new Event(_pending_events.back());
  _pending_events.pop_back();
  return event;
}

Event * EventBase::last_event()
{
  if (this->is_empty())
  {
    return nullptr;
  }
  else
  {
    return &_pending_events.front();
  }
}

bool EventBase::event_exists(EventID * event_id)
{
  for(
      std::vector<Event>::iterator it = _pending_events.begin();
      it != _pending_events.end();
      ++it
      )
  {
    if (event_id->is_equal(it->get_event_id()))
    {
      return true;
    }
  }
  return false;
}

bool EventBase::is_full()
{
  return (_pending_events.size() == _size);
}

bool EventBase::is_empty()
{
  return (_pending_events.size() == 0);
}
