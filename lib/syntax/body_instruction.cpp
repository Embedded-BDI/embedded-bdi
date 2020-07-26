/*
 * body_instruction.cpp
 *
 *  Created on: Jul 24, 2020
 *      Author: Matuzalem Muller
 */

#include "body_instruction.h"

BodyInstruction::BodyInstruction() {}; // @suppress("Class members should be properly initialized")

BodyInstruction::BodyInstruction(BodyType type, Statement stm, bool (*take_action)(BeliefBase * belief_base)) // @suppress("Class members should be properly initialized")
{
  _type = type;
  _statement = stm;
  _take_action = take_action;
}

BodyInstruction::BodyInstruction(BodyType type, Statement stm, EventOperator event_operator) // @suppress("Class members should be properly initialized")
{
  _type = type;
  _statement = stm;
  _operator = event_operator;
}

BodyReturn BodyInstruction::run_instruction(BeliefBase * belief_base, EventBase * event_base)
{
  BodyReturn result;
  if (_type == BodyType::ACTION)
  {
    bool value = _take_action(belief_base);
    result = BodyReturn(BodyType::ACTION, value, NULL);

    return result;
  }
  else if (_type == BodyType::BELIEF)
  {
    if (event_base->add_event(_operator, _statement))
    {
      if (_operator == EventOperator::BELIEF_ADDITION)
      {
        belief_base->change_belief_state(_statement, true);
      }
      else
      {
        belief_base->change_belief_state(_statement, false);
      }
      result = BodyReturn(BodyType::BELIEF, true, event_base->last_event()->get_event_id());
      return result;
    }
    else
    {
      result = BodyReturn(BodyType::BELIEF, false, NULL);
      return result;
    }
  }
  else
  {
    if (event_base->add_event(_operator, _statement))
    {
      result = BodyReturn(BodyType::GOAL, true, event_base->last_event()->get_event_id());
      return result;
    }
    else
    {
      result = BodyReturn(BodyType::GOAL, false, NULL);
      return result;
    }
  }
}
