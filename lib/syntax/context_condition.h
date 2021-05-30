/*
 * context_condition.h
 *
 *  Created on: Jul 16, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_CONTEXT_CONDITION_H_
#define SYNTAX_CONTEXT_CONDITION_H_

#include "proposition.h"
#include <cstdint>

/**
 * Represents a literal from the plan's context.
 */
class ContextCondition
{
private:
  Proposition _proposition;

public:
  /**
   * ContextCondition constructor
   * @param prop Proposition to be compared with belief from BeliefBase
   */
  ContextCondition(Proposition prop);

  const Proposition & get_proposition() const
  {
    return _proposition;
  }
};

#endif /* SYNTAX_CONTEXT_CONDITION_H_ */
