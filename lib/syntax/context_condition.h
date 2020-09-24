/*
 * context_condition.h
 *
 *  Created on: Jul 16, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_CONTEXT_CONDITION_H_
#define SYNTAX_CONTEXT_CONDITION_H_

#include "statement.h"
#include <cstdint>

/**
 * Represents a literal from the plan's context.
 */
class ContextCondition
{
private:
  Statement _statement;

public:
  /**
   * ContextCondition constructor
   * @param stm Statement to be compared with belief from BeliefBase
   */
  ContextCondition(Statement stm);

  const Statement & get_statement() const
  {
    return _statement;
  }
};

#endif /* SYNTAX_CONTEXT_CONDITION_H_ */
