/*
 * body_test.cpp
 *
 *  Created on: Jul 24, 2020
 *      Author: Matuzalem Muller
 */

#include "common_lib.h"
#include "bdi/belief_base.h"
#include "syntax/body_instruction.h"

class TestBodyData {
private:
  BeliefBase * _belief_base;
  EventBase * _event_base;

public:
  TestBodyData(int size)
  {
    _belief_base = new BeliefBase(size);
    _event_base = new EventBase(size);

    Proposition prop(0);
    Belief belief(prop, nullptr, true);
    for (int i = 0; i < size; i++)
    {
      _belief_base->add_belief(belief);
    }
  }

  ~TestBodyData()
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
    Proposition prop(0);
    BodyInstruction action(BodyType::ACTION, prop, return_true_beliefbase);
    return action;
  }

  BodyInstruction get_action_false()
  {
    Proposition prop(0);
    BodyInstruction action(BodyType::ACTION, prop, return_false_beliefbase);
    return action;
  }

  BodyInstruction get_belief_operation()
  {
    Proposition prop(0);
    BodyInstruction bf(BodyType::BELIEF, prop, EventOperator::BELIEF_ADDITION);
    return bf;
  }

  BodyInstruction get_goal()
  {
    Proposition prop(0);
    BodyInstruction goal(BodyType::GOAL, prop, EventOperator::GOAL_ADDITION);
    return goal;
  }
};
