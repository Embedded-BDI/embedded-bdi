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
#include <vector>

class Context
{
  /// Vector of ContextConditions
  std::vector <ContextCondition> _context;
  /// Max size of _context vector
  int _size;

public:
  Context(int size);

  virtual ~Context();

  /**
   * Adds belief to _context buffer
   * @param value ContextCondition to be added
   * @return true if value is added to buffer, false otherwise
   */
  bool add_context(ContextCondition value);

  /**
   * Checks if context is valid
   * @param beliefs Checks if statements from vector of ContextConditions have
   * the expected values given the BeliefBase
   */
  bool is_valid (BeliefBase * beliefs);
};

#endif /* SYNTAX_CONTEXT_H_ */
