/*
 * context_condition.cpp
 *
 *  Created on: Jul 16, 2020
 *      Author: Matuzalem Muller
 */

#include "context_condition.h"

ContextCondition::ContextCondition() {}

ContextCondition::ContextCondition(Statement stm, bool negation)
{
  _statement = stm;
  _negation = negation;
}

ContextCondition::~ContextCondition() {}

bool ContextCondition::get_value()
{
  return !_negation;
}
