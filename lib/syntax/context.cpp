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
  _context = new CircularBuffer<ContextCondition>(size);
}

Context::~Context()
{
  delete _context;
}

bool Context::add_belief(ContextCondition value)
{
  return _context->enqueue(value);
}

bool Context::is_valid(BeliefBase * beliefs)
{
  for (int i = 0; i < _context->size(); i++)
  {
    // If any belief has different value than expected, return false
    if((beliefs->get_belief_state(_context->item(i)->get_statement())) !=
       (_context->item(i)->is_true()))
    {
      return false;
    }
  }
  return true;
}
