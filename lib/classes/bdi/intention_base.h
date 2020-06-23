/*
 * intention_base.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef BDI_INTENTION_BASE_H_
#define BDI_INTENTION_BASE_H_

#include "belief_base.h"
#include "event_base.h"
#include "intention.h"
#include "../lib/circular_buffer.h"
#include "../syntax/plan.h"

class IntentionBase {
private:
  CircularBuffer<Intention> _intention_base;
  int _buffer_size;
  int _stack_size;

public:
  IntentionBase();

  IntentionBase(int buffer_size, int stack_size);

  virtual ~IntentionBase();

  void add_intention(Plan plan);

  void run_intention_base(BeliefBase beliefs, EventBase events);
};

#endif /* BDI_INTENTION_BASE_H_ */
