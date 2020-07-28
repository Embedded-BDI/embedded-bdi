/*
 * test_plan_data.h
 *
 *  Created on: Jul 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_SYNTAX_PLAN_TEST_TEST_PLAN_DATA_H_
#define UTEST_SYNTAX_PLAN_TEST_TEST_PLAN_DATA_H_

#include "bdi/belief_base.h"
#include "syntax/body.h"
#include "syntax/context.h"
#include "../../common_test_functions.h"

class TestPlanData {
private:
  Statement stm;
  BeliefBase * belief_base_empty;
  BeliefBase * belief_base_full;
  EventBase * event_base_empty;
  EventBase * event_base_full;
  Body * body_valid;
  Body * body_action_fails;
  Body * body_belief_fails;
  Body * body_goal_fails;

public:
  TestPlanData(int body_size, int belief_base_size, int event_base_size)
  {
    stm = Statement('a');

    // Creates BeliefBases
    belief_base_empty = new BeliefBase(belief_base_size);
    belief_base_full = new BeliefBase(belief_base_size);
    for (int i = 0; i < belief_base_size; i++)
    {
      Belief belief(stm, NULL);
      belief_base_full->add_belief(belief);
    }

    // Creates EventBases
    event_base_empty = new EventBase(2 * event_base_size);
    event_base_full = new EventBase(event_base_size);
    for (int i = 0; i < event_base_size; i++)
    {
      event_base_full->add_event(EventOperator::GOAL_ADDITION,
                                 stm);
    }

    // Creates valid plan
    BodyInstruction instruction;
    body_valid = new Body(body_size);
    instruction = BodyInstruction(BodyType::ACTION,
                                  stm,
                                  return_true_beliefbase);
    for (int i = 0; i < body_size; i++)
    {
      body_valid->add_instruction(instruction);
    }

    // Creates plan that fails due to failure in action
    body_action_fails = new Body(body_size);
    instruction = BodyInstruction(BodyType::ACTION,
                                  stm,
                                  return_false_beliefbase);
    for (int i = 0; i < body_size; i++)
    {
      body_action_fails->add_instruction(instruction);
    }

    // Creates plan that fails due to full EventBase and belief event cannot be created
    body_belief_fails = new Body(body_size);
    instruction = BodyInstruction(BodyType::BELIEF,
                                  stm,
                                  EventOperator::BELIEF_ADDITION);
    for (int i = 0; i < body_size; i++)
    {
      body_belief_fails->add_instruction(instruction);
    }

    // Creates plan that fails due to full EventBase and goal event cannot be created
    body_goal_fails = new Body(body_size);
    instruction = BodyInstruction(BodyType::GOAL,
                                  stm,
                                  EventOperator::GOAL_ADDITION);
    for (int i = 0; i < body_size; i++)
    {
      body_goal_fails->add_instruction(instruction);
    }
  }

  ~TestPlanData()
  {
    delete belief_base_empty;
    delete belief_base_full;
    delete event_base_empty;
    delete event_base_full;
    delete body_valid;
    delete body_action_fails;
    delete body_belief_fails;
    delete body_goal_fails;
  }

  BeliefBase * get_belief_base_empty()
  {
    return belief_base_empty;
  }

  BeliefBase * get_belief_base_full()
  {
    return belief_base_full;
  }

  EventBase * get_event_base_empty()
  {
    return event_base_empty;
  }

  EventBase * get_event_base_full()
  {
    return event_base_full;
  }

  Body * get_body_action_fails()
  {
    return body_action_fails;
  }

  Body * get_body_belief_fails()
  {
    return body_belief_fails;
  }

  Body * get_body_goal_fails()
  {
    return body_goal_fails;
  }

  Body * get_body_valid()
  {
    return body_valid;
  }

  Statement get_stm()
  {
    return stm;
  }
};

#endif /* UTEST_SYNTAX_PLAN_TEST_TEST_PLAN_DATA_H_ */


