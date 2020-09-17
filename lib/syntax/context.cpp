/*
 * context.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "context.h"

Context::Context(std::uint8_t size)
{
  _size = size;
  _context.init(size);
}

Context::~Context() {}

bool Context::add_context(ContextCondition value)
{
  if (_context.size() == _size)
  {
    return false;
  }

//  _context.push_back(value);
  _context.add_front(value);
  return true;
}

bool Context::is_valid(BeliefBase * beliefs)
{
  for (std::uint8_t i = 0; i < _context.size(); i++)
  {
    // If any belief has different value than expected, return false
    if ((beliefs->get_belief_state(_context.item_at(i)->get_statement())) !=
        (_context.item_at(i)->is_true()))
    {
      return false;
    }
  }

  return true;
}
