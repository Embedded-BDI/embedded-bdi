/*
 * event_base.cpp
 *
 *  Created on: May 31, 2020
 *      Author: Matuzalem Muller
 */

#include "event_base.h"

EventBase::EventBase(std::uint8_t size)
{
  _size = size;
  _pending_events.init(size);
}

EventBase::~EventBase() {}

bool EventBase::add_event(EventOperator op, Statement stm)
{
  if (this->is_full())
  {
    return false;
  }

  Event event(op,stm);
  _pending_events.add_front(event);
  return true;
}

Event * EventBase::get_event()
{
  if (this->is_empty())
  {
    return nullptr;
  }

  Event * event = new Event(*_pending_events.back());
  _pending_events.remove();
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
    return _pending_events.front();
  }
}

bool EventBase::event_exists(EventID * event_id)
{
  for (std::uint8_t i = 0; i < _pending_events.size(); i++)
  {
    if (event_id->is_equal(_pending_events.item_at(i)->get_event_id()))
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
