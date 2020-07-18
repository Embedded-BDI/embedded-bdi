/*
 * context_condition.h
 *
 *  Created on: Jul 16, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_CONTEXT_CONDITION_H_
#define SYNTAX_CONTEXT_CONDITION_H_

#include "statement.h"

class ContextCondition
{
private:
  Statement _statement;
  bool _negation;

public:
  ContextCondition();

  ContextCondition(Statement stm, bool negation);

  virtual ~ContextCondition();

  bool get_value();

  bool is_negation() const
  {
    return _negation;
  }

  const Statement & get_statement() const
  {
    return _statement;
  }
};

#endif /* SYNTAX_CONTEXT_CONDITION_H_ */
