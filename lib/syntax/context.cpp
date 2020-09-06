/*
 * context.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "context.h"

Context::Context(int size)
{
  _size = size;
  _context.reserve(size);
}

Context::~Context() {}

bool Context::add_context(ContextCondition value)
{
  if (_context.size() == _size)
  {
    return false;
  }

  _context.push_back(value);
  return true;
}

bool Context::is_valid(BeliefBase * beliefs)
{
  for (
      std::vector<ContextCondition>::iterator it = _context.begin();
      it != _context.end();
      ++it
      )
  {
    // If any belief has different value than expected, return false
    if ((beliefs->get_belief_state(it->get_statement())) !=
        (it->is_true()))
    {
      return false;
    }
  }
  return true;
}
