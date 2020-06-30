/*
 * event_base.cpp
 *
 *  Created on: May 31, 2020
 *      Author: Matuzalem Muller
 */

#include "event_base.h"

//EventBase::EventBase() {}

EventBase::EventBase(int size){
  this->_pending_events.init(size);
  this->_size = size;
}

EventBase::~EventBase() {}

bool EventBase::add_event(Event event){
  if (!this->_pending_events.is_full())
  {
    this->_pending_events.enqueue(event);
    return true;
  } else {
    return false;
  }
}

bool EventBase::add_event(EventOperator::EventType op, Statement stm){
  if (!this->_pending_events.is_full())
  {
    Event event(op,stm);
    this->_pending_events.enqueue(event);
    return true;
  } else {
    return false;
  }
}

Event EventBase::get_event(){
  Event * event = this->_pending_events.peek();
  this->_pending_events.dequeue();

  return *event;
}

bool EventBase::is_full() {
  return this->_pending_events.is_full();
}

bool EventBase::is_empty() {
  return this->_pending_events.is_empty();
}
