/*
 * context.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_CONTEXT_H_
#define SYNTAX_CONTEXT_H_

#include "../bdi/belief_base.h"
#include "../lib/circular_buffer.h"

class Context {
//  CircularBuffer<ILiteral> _context;

public:
  Context();

//  Context(CircularBuffer<ILiteral> ctx);

  virtual ~Context();

  bool is_valid (BeliefBase beliefs);
};

#endif /* SYNTAX_CONTEXT_H_ */
