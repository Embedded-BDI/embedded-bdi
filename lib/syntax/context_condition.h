/*
 * context_condition.h
 *
 *  Created on: Jul 16, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_CONTEXT_CONDITION_H_
#define SYNTAX_CONTEXT_CONDITION_H_

#include "statement.h"

/*
 * Represents a literal from the plan's context
 */
class ContextCondition
{
private:
  Statement _statement;
  bool _is_true;

public:
  ContextCondition();

  /*
   * ContextCondition constructor
   * @param stm Statement to be compared with belief from BeliefBase
   * @para negation Whether the statement should be considered true or false
   */
  ContextCondition(Statement stm, bool negation);

  virtual ~ContextCondition();

  bool is_true() const
  {
    return _is_true;
  }

  const Statement & get_statement() const
  {
    return _statement;
  }
};

#endif /* SYNTAX_CONTEXT_CONDITION_H_ */
