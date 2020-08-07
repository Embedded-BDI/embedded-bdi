/*
 * context.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "context.h"

Context::Context() {}

Context::Context(int size)
{
  _context.reserve(size);
}

Context::~Context() {}

bool Context::add_belief(ContextCondition value)
{
  if (_context.size() == _context.capacity())
  {
    return false;
  }

  _context.push_back(value);
  return true;
}

bool Context::is_valid(BeliefBase * beliefs)
{
  for (int i = 0; i < _context.size(); i++)
  {
    // If any belief has different value than expected, return false
    if((beliefs->get_belief_state(_context.at(i).get_statement())) !=
       (_context.at(i).is_true()))
    {
      return false;
    }
  }
  return true;
}
