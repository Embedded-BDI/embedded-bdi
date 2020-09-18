/*
 * configuration.h
 *
 *  Created on: Sep 17, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_FAILED_INTENTION_CONFIGURATION_H_
#define UTEST_AGENT_FAILED_INTENTION_CONFIGURATION_H_

#include "../../lib/bdi/belief_base.h"
#include "../../lib/bdi/event_base.h"
#include "../../lib/bdi/plan_base.h"
#include "../../lib/bdi/intention_base.h"
#include "functions.h"

class FailedIntention
{
private:
  BeliefBase * belief_base;
  EventBase * event_base;
  PlanBase * plan_base;
  IntentionBase * intention_base;

public:
  FailedIntention()
  {
    belief_base = new BeliefBase(0);
    event_base = new EventBase(2);
    plan_base = new PlanBase(7);
    intention_base = new IntentionBase(2, 4);

    //--------------------------------------------------------------------------

    event_base->add_event(EventOperator::GOAL_ADDITION, 0);

    //--------------------------------------------------------------------------

    event_base->add_event(EventOperator::GOAL_ADDITION, 1);

    //--------------------------------------------------------------------------

    Statement stm_0(0);
    Context * context_0 = new Context(0);
    Body * body_0 = new Body(1);

    Statement stm_0_body_0(2);
    BodyInstruction inst_0_0(BodyType::ACTION, stm_0_body_0, action_return_false);
    body_0->add_instruction(inst_0_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, stm_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Statement stm_1(0);
    Context * context_1 = new Context(0);
    Body * body_1 = new Body(1);

    Statement stm_1_body_0(3);
    BodyInstruction inst_0_1(BodyType::ACTION, stm_1_body_0, action_deletion_1);
    body_1->add_instruction(inst_0_1);

    Plan plan_1(EventOperator::GOAL_DELETION, stm_1, context_1, body_1);
    plan_base->add_plan(plan_1);

    //--------------------------------------------------------------------------

    Statement stm_2(1);
    Context * context_2 = new Context(0);
    Body * body_2 = new Body(3);

    Statement stm_2_body_0(4);
    BodyInstruction inst_0_2(BodyType::ACTION, stm_2_body_0, action_return_true);
    body_2->add_instruction(inst_0_2);

    Statement stm_2_body_1(5);
    BodyInstruction inst_1_2(BodyType::GOAL, stm_2_body_1, EventOperator::GOAL_ADDITION);
    body_2->add_instruction(inst_1_2);

    Statement stm_2_body_2(4);
    BodyInstruction inst_2_2(BodyType::ACTION, stm_2_body_2, action_return_true);
    body_2->add_instruction(inst_2_2);

    Plan plan_2(EventOperator::GOAL_ADDITION, stm_2, context_2, body_2);
    plan_base->add_plan(plan_2);

    //--------------------------------------------------------------------------

    Statement stm_3(5);
    Context * context_3 = new Context(0);
    Body * body_3 = new Body(2);

    Statement stm_3_body_0(4);
    BodyInstruction inst_0_3(BodyType::ACTION, stm_3_body_0, action_return_true);
    body_3->add_instruction(inst_0_3);

    Statement stm_3_body_1(6);
    BodyInstruction inst_1_3(BodyType::GOAL, stm_3_body_1, EventOperator::GOAL_ADDITION);
    body_3->add_instruction(inst_1_3);

    Plan plan_3(EventOperator::GOAL_ADDITION, stm_3, context_3, body_3);
    plan_base->add_plan(plan_3);

    //--------------------------------------------------------------------------

    Statement stm_4(6);
    Context * context_4 = new Context(0);
    Body * body_4 = new Body(1);

    Statement stm_4_body_0(2);
    BodyInstruction inst_0_4(BodyType::ACTION, stm_4_body_0, action_return_false);
    body_4->add_instruction(inst_0_4);

    Plan plan_4(EventOperator::GOAL_ADDITION, stm_4, context_4, body_4);
    plan_base->add_plan(plan_4);

    //--------------------------------------------------------------------------

    Statement stm_5(6);
    Context * context_5 = new Context(0);
    Body * body_5 = new Body(1);

    Statement stm_5_body_0(3);
    BodyInstruction inst_0_5(BodyType::ACTION, stm_5_body_0, action_deletion_1);
    body_5->add_instruction(inst_0_5);

    Plan plan_5(EventOperator::GOAL_DELETION, stm_5, context_5, body_5);
    plan_base->add_plan(plan_5);

    //--------------------------------------------------------------------------

    Statement stm_6(6);
    Context * context_6 = new Context(0);
    Body * body_6 = new Body(1);

    Statement stm_6_body_0(7);
    BodyInstruction inst_0_6(BodyType::ACTION, stm_6_body_0, action_deletion_2);
    body_6->add_instruction(inst_0_6);

    Plan plan_6(EventOperator::GOAL_DELETION, stm_6, context_6, body_6);
    plan_base->add_plan(plan_6);
  }

  ~FailedIntention()
  {
    delete belief_base;
    delete event_base;
    delete plan_base;
    delete intention_base;
  }

  BeliefBase *  get_belief_base()
  {
    return belief_base;
  }

  EventBase * get_event_base()
  {
    return event_base;
  }

  PlanBase * get_plan_base()
  {
    return plan_base;
  }

  IntentionBase * get_intention_base()
  {
    return intention_base;
  }
};

#endif /* UTEST_AGENT_FAILED_INTENTION_CONFIGURATION_H_ */
