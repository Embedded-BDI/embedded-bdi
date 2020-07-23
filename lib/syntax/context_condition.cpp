/*
 * context_condition.cpp
 *
 *  Created on: Jul 16, 2020
 *      Author: Matuzalem Muller
 */

#include "context_condition.h"

ContextCondition::ContextCondition() {}

ContextCondition::ContextCondition(Statement stm, bool is_true)
{
  _statement = stm;
  _is_true = is_true;
}

ContextCondition::~ContextCondition() {}
