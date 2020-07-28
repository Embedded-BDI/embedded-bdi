/*
 * context.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_CONTEXT_H_
#define SYNTAX_CONTEXT_H_

#include "context_condition.h"
#include "../bdi/belief_base.h"
#include "../lib/circular_buffer.h"

class Context
{
  CircularBuffer<ContextCondition> * _context;

public:
  Context();

  Context(int size);

  virtual ~Context();

  /*
   * Adds belief to _context buffer
   * @param value ContextCondition to be added
   * @return true if value is added to buffer, false otherwise
   */
  bool add_belief(ContextCondition value);

  /*
   * Checks if context is valid
   */
  bool is_valid (BeliefBase * beliefs);
};

#endif /* SYNTAX_CONTEXT_H_ */
