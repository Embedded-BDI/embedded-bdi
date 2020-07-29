/*
 * test_intention_data.h
 *
 *  Created on: Jul 29, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_BDI_INTENTION_TEST_TEST_INTENTION_DATA_H_
#define UTEST_BDI_INTENTION_TEST_TEST_INTENTION_DATA_H_

#include "syntax/plan.h"
#include "../../common_test_functions.h"

class TestIntentionData {
private:
  EventBase * event_base_full;
  Statement stm;
  Context * context_valid;
  Body * body_successful;
  Body * body_fails;
  Plan * plan_successful;
  Plan * plan_fails;


public:
  TestIntentionData(int body_size, int bases_size)
  {
    event_base_full = new EventBase(bases_size);

    stm = Statement('a');

    context_valid = new Context(0);

    // Creates valid plan
    BodyInstruction instruction(BodyType::ACTION,
                                stm,
                                return_true_beliefbase);

    body_successful = new Body(body_size);
    for (int i = 0; i < body_size; i++)
    {
      body_successful->add_instruction(instruction);
    }

    plan_successful = new Plan(EventOperator::BELIEF_ADDITION,
                               stm,
                               context_valid,
                               body_successful);

    // Creates plan that fails due to failure in action
    body_fails = new Body(body_size);
    instruction = BodyInstruction(BodyType::ACTION,
                                  stm,
                                  return_false_beliefbase);
    for (int i = 0; i < body_size; i++)
    {
      body_fails->add_instruction(instruction);
    }

    plan_fails = new Plan(EventOperator::BELIEF_ADDITION,
                          stm,
                          context_valid,
                          body_fails);
  }

  ~TestIntentionData()
  {
    delete event_base_full;
    delete body_successful;
    delete body_fails;
    delete plan_successful;
    delete plan_fails;
  }

  Plan * get_plan_successfull()
  {
    return plan_successful;
  }

  Plan * get_plan_fails()
  {
    return plan_fails;
  }
};

#endif /* UTEST_BDI_INTENTION_TEST_TEST_INTENTION_DATA_H_ */
