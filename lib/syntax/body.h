/*
 * body.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_BODY_H_
#define SYNTAX_BODY_H_

#include "body_instruction.h"
#include "../bdi/belief_base.h"
#include "../bdi/event_base.h"
#include <vector>

class Body
{
  std::vector <BodyInstruction> _body;

public:
  /*
   * Body constructor
   * @param size Size of _body
   */
  Body(int size);

  virtual ~Body();

  /*
   * Run instruction from body at specific position
   * @param index Position in body of instruction to be run
   * @param beliefs Agent's BeliefBase
   * @param events Agent's EventBase
   */
  BodyReturn run_body(int index, BeliefBase * beliefs, EventBase * events);

  /*
   * Adds instruction to body
   * @param instruction Instruction to add
   */
  bool add_instruction(BodyInstruction instruction);

  int size();
};

#endif /* SYNTAX_BODY_H_ */
