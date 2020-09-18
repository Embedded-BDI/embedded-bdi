/*
 * test_intention_data.h
 *
 *  Created on: Jul 29, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_BDI_INTENTION_TEST_TEST_INTENTION_DATA_H_
#define UTEST_BDI_INTENTION_TEST_TEST_INTENTION_DATA_H_

#include "common_lib.h"
#include "syntax/plan.h"


class TestIntentionData {
private:
  BeliefBase * belief_base;
  EventBase * event_base_empty;
  PlanBase * plan_base;
  Statement stm;
  Context * context_valid;
  Body * body_action_successful;
  Body * body_action_fails;
  Body * body_belief;
  Plan * plan_action_successful;
  Plan * plan_action_fails;
  Plan * plan_action_fails_handling;
  Plan * plan_belief;

public:
  TestIntentionData(int body_size, int bases_size)
  {
    stm = Statement('a');

    context_valid = new Context(0);

    event_base_empty = new EventBase(bases_size);
    belief_base = new BeliefBase(bases_size);
    plan_base = new PlanBase(bases_size);

    Belief belief(stm, nullptr);

    belief_base->add_belief(belief);

    /*
     * Creates successful plan with successful actions
     */
    BodyInstruction instruction(BodyType::ACTION,
                                stm,
                                return_true_beliefbase);

    body_action_successful = new Body(body_size);
    for (int i = 0; i < body_size; i++)
    {
      body_action_successful->add_instruction(instruction);
    }

    plan_action_successful = new Plan(EventOperator::BELIEF_ADDITION,
                                      stm,
                                      context_valid,
                                      body_action_successful);

    /*
     * Creates plan that fails due to failure in action
     */
    body_action_fails = new Body(body_size);
    instruction = BodyInstruction(BodyType::ACTION,
                                  stm,
                                  return_false_beliefbase);
    for (int i = 0; i < body_size; i++)
    {
      body_action_fails->add_instruction(instruction);
    }

    plan_action_fails = new Plan(EventOperator::BELIEF_ADDITION,
                                 stm,
                                 context_valid,
                                 body_action_fails);

    /*
     * Creates plan to handle plan failure (-!)
     */
    plan_action_fails_handling = new Plan(EventOperator::GOAL_DELETION,
                                          stm,
                                          context_valid,
                                          body_action_successful);

    /*
     * Creates plan full of belief events
     */
    body_belief = new Body(body_size);
    instruction = BodyInstruction(BodyType::BELIEF,
                                  stm,
                                  EventOperator::BELIEF_ADDITION);
    for (int i = 0; i < body_size; i++)
    {
    	body_belief->add_instruction(instruction);
    }

    plan_belief = new Plan(EventOperator::BELIEF_ADDITION,
                           stm,
                           context_valid,
                           body_belief);
  }

  ~TestIntentionData()
  {
    delete event_base_empty;
    delete belief_base;
    delete plan_base;
    delete body_action_successful;
    delete body_action_fails;
    delete body_belief;
    delete plan_action_successful;
    delete plan_action_fails;
    delete plan_action_fails_handling;
    delete plan_belief;
  }

  BeliefBase * get_belief_base()
  {
    return belief_base;
  }

  EventBase * get_event_base_empty()
  {
    return event_base_empty;
  }

  PlanBase * get_plan_base()
  {
    return plan_base;
  }

  Statement get_statement()
  {
    return stm;
  }

  Plan * get_plan_action_successful()
  {
    return plan_action_successful;
  }

  Plan * get_plan_action_fails()
  {
    return plan_action_fails;
  }

  Plan * get_plan_action_fails_handling()
  {
    return plan_action_fails_handling;
  }

  Plan * get_plan_belief()
  {
    return plan_belief;
  }
};

#endif /* UTEST_BDI_INTENTION_TEST_TEST_INTENTION_DATA_H_ */
