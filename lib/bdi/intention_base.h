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

class IntentionBase
{
private:
  CircularBuffer<Intention> * _intention_base;
  BeliefBase * _belief_base;
  EventBase * _event_base;
  int _buffer_size;

public:
  IntentionBase();

  /*
   * IntentionBase constructor
   * @param buffer_size Size of the buffer where the intentions are stored
   * @param stack_size Size of each intention stack
   * @param Pointer to Agent's BeliefBase
   * @param Pointer to Agent's EventBase
   */
  IntentionBase(int buffer_size, int stack_size, BeliefBase * beliefs, EventBase * events);

  virtual ~IntentionBase();

  /*
   * Add new intention to _intention_base buffer
   * @param plan Pointer to plan to be instantiated as intention
   */
  void add_intention(Plan * plan);

  /*
   * Run an instruction from first intention stored in _intention_base
   */
  void run_intention_base();

  bool is_empty();
};

#endif /* BDI_INTENTION_BASE_H_ */
