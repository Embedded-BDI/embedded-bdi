/*
 * plan_example.h
 *
 *  Created on: Aug 7, 2020
 *      Author: Matuzalem Muller
 */

#ifndef PLAN_EXAMPLE_H_
#define PLAN_EXAMPLE_H_

#include "syntax/plan.h"

bool return_true_beliefbase(BeliefBase * beliefs)
{
  return true;
}

class TestPlan {
private:
  BeliefBase * belief_base;
  EventBase * event_base_empty;
  Statement stm;
  Context * context_valid;
  Body * body_action_successful;
  Plan * plan_action_successful;

public:
  TestPlan(int body_size, int bases_size)
  {
    stm = Statement('a');

    context_valid = new Context(0);

    event_base_empty = new EventBase(bases_size);
    belief_base = new BeliefBase(bases_size);

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

  }

  ~TestPlan()
  {
    delete event_base_empty;
    delete belief_base;
    delete context_valid;
    delete body_action_successful;
    delete plan_action_successful;
  }

  Statement get_statement()
  {
    return stm;
  }

  Plan * get_plan_action_successful()
  {
    return plan_action_successful;
  }
};



#endif /* PLAN_EXAMPLE_H_ */
