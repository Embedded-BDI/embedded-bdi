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
#include "../syntax/plan.h"
#include <vector>

class IntentionBase
{
private:
  std::vector<Intention> _intention_base;
  int _buffer_size;
  int _stack_size;

public:
  IntentionBase();

  /*
   * IntentionBase constructor
   * @param buffer_size Size of the buffer where the intentions are stored
   * @param stack_size Size of each intention stack
   * @param Pointer to Agent's BeliefBase
   * @param Pointer to Agent's EventBase
   */
  IntentionBase(int buffer_size, int stack_size);

  virtual ~IntentionBase();

  /*
   * Add new intention to _intention_base buffer
   * @param plan Pointer to plan to be instantiated as intention
   */
  void add_intention(Plan * plan);

//  void add_intention(Intention intention);

  /*
   * Run instruction from the intention stored in the front of _intention_base
   * After instruction is run, the intention is placed at the end of
   * _intention_base if it has not finished
   */
  void run_intention_base(BeliefBase * beliefs, EventBase * events);

  /*
   * Returns if IntentionBase is empty based on _intention_base size
   * @return True if empty, false otherwise
   */
  bool is_empty();
};

#endif /* BDI_INTENTION_BASE_H_ */
