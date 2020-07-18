/*
 * goal.h
 *
 *  Created on: Jun 3, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_GOAL_H_
#define SYNTAX_GOAL_H_

#include "body_instruction.h"
#include "../statement.h"

class Goal : IBodyInstruction
{
private:
  EventOperator _operator;
  Statement _statement;
  BodyType _type = BodyType::GOAL;

public:
  Goal();

  /*
   * Goal constructor
   * @param stm Statement
   * @param event_type Type of event
   */
  Goal(Statement stm, EventOperator event_type);

  virtual ~Goal();

  /*
   * Create event for operation
   * @param belief_base Agent's BeliefBase
   * @param event_base Agent's EventBase
   * @return Based on return from add_event method. If event is added
   * successfully, return is true. Otherwise, return is false and intention
   * should likely be dropped
   */
  BodyReturn run_instruction(BeliefBase * belief_base, EventBase * event_base) override;

  BodyType get_BodyType() override
  {
    return _type;
  }

  const EventOperator & get_operator() const
  {
     return _operator;
  }

  const Statement & get_statement() const
  {
     return _statement;
  }
};

#endif /* SYNTAX_GOAL_H_ */
