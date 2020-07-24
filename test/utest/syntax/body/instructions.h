/*
 * body_test.cpp
 *
 *  Created on: Jul 24, 2020
 *      Author: Matuzalem Muller
 */

#include "bdi/belief_base.h"

bool function_action_true(BeliefBase * beliefs)
{
  return true;
}

bool function_action_false(BeliefBase * beliefs)
{
  return false;
}

class InstructionExample {
private:
  BeliefBase * _belief_base;
  EventBase * _event_base;
  char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f',
                       'g', 'h', 'i', 'j', 'k', 'l',
                       'm', 'n', 'o', 'p', 'q', 'r',
                       's', 't', 'u', 'v', 'w', 'x',
                       'y', 'z'};

public:
  InstructionExample(int size)
  {
    _belief_base = new BeliefBase(size);
    _event_base = new EventBase(size);

    for (int i = 0; i < size; i++)
    {
      Statement stm(alphabet[i]);
      Belief belief(stm, NULL, true);
      _belief_base->add_belief(belief);
    }
  }

  virtual ~InstructionExample()
  {
    delete _belief_base;
    delete _event_base;
  }

  BeliefBase * get_belief_base()
  {
    return _belief_base;
  }

  EventBase * get_event_base()
  {
    return _event_base;
  }

  BodyInstruction get_action_true()
  {
    Statement stm('a');
    BodyInstruction action(BodyType::ACTION, stm, function_action_true);
    return action;
  }

  BodyInstruction get_action_false()
  {
    Statement stm('a');
    BodyInstruction action(BodyType::ACTION, stm, function_action_false);
    return action;
  }

  BodyInstruction get_belief_operation()
  {
    Statement stm('a');
    BodyInstruction belief(BodyType::BELIEF, stm, EventOperator::BELIEF_ADDITION);
    return belief;
  }

  BodyInstruction get_goal()
  {
    Statement stm('a');
    BodyInstruction goal(BodyType::GOAL, stm, EventOperator::GOAL_ADDITION);
    return goal;
  }
};
