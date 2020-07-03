/*
 * intention_base.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "intention_base.h"

IntentionBase::IntentionBase() {} // @suppress("Class members should be properly initialized")

IntentionBase::IntentionBase(int buffer_size, int stack_size) {
  _buffer_size = buffer_size;
  _stack_size = stack_size;
}

IntentionBase::~IntentionBase() {}

void IntentionBase::add_intention(Plan plan) {
  if (!_intention_base.is_full())
  {
    Intention intention(plan, _stack_size);
    _intention_base.enqueue(intention);
  }
}

void IntentionBase::run_intention_base(BeliefBase beliefs, EventBase events) {}
