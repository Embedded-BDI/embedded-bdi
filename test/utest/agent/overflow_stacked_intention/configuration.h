/*
 * configuration.h
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_OVERFLOW_STACKED_INTENTION_CONFIGURATION_H_
#define UTEST_AGENT_OVERFLOW_STACKED_INTENTION_CONFIGURATION_H_

#include "../../lib/bdi/belief_base.h"
#include "../../lib/bdi/event_base.h"
#include "../../lib/bdi/plan_base.h"
#include "../../lib/bdi/intention_base.h"
#include "functions.h"

class OverflowStackedIntention
{
private:
  BeliefBase * belief_base;
  EventBase * event_base;
  PlanBase * plan_base;
  IntentionBase * intention_base;

public:
  OverflowStackedIntention()
  {
    belief_base = new BeliefBase(0);
    event_base = new EventBase(1);
    plan_base = new PlanBase(5);
    intention_base = new IntentionBase(1, 3);

    //--------------------------------------------------------------------------

    event_base->add_event(EventOperator::GOAL_ADDITION, 0);

    //--------------------------------------------------------------------------

    Statement stm_0(0);
    Context * context_0 = new Context(0);
    Body * body_0 = new Body(3);

    Statement stm_0_body_0(1);
    BodyInstruction inst_0_0(BodyType::ACTION, stm_0_body_0, action_1_1_overflow_stacked_intention);
    body_0->add_instruction(inst_0_0);

    Statement stm_0_body_1(2);
    BodyInstruction inst_1_0(BodyType::GOAL, stm_0_body_1, EventOperator::GOAL_ADDITION);
    body_0->add_instruction(inst_1_0);

    Statement stm_0_body_2(1);
    BodyInstruction inst_2_0(BodyType::ACTION, stm_0_body_2, action_1_2_overflow_stacked_intention);
    body_0->add_instruction(inst_2_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, stm_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Statement stm_1(2);
    Context * context_1 = new Context(0);
    Body * body_1 = new Body(3);

    Statement stm_1_body_0(3);
    BodyInstruction inst_0_1(BodyType::ACTION, stm_1_body_0, action_2_1_overflow_stacked_intention);
    body_1->add_instruction(inst_0_1);

    Statement stm_1_body_1(4);
    BodyInstruction inst_1_1(BodyType::GOAL, stm_1_body_1, EventOperator::GOAL_ADDITION);
    body_1->add_instruction(inst_1_1);

    Statement stm_1_body_2(3);
    BodyInstruction inst_2_1(BodyType::ACTION, stm_1_body_2, action_2_2_overflow_stacked_intention);
    body_1->add_instruction(inst_2_1);

    Plan plan_1(EventOperator::GOAL_ADDITION, stm_1, context_1, body_1);
    plan_base->add_plan(plan_1);

    //--------------------------------------------------------------------------

    Statement stm_2(4);
    Context * context_2 = new Context(0);
    Body * body_2 = new Body(3);

    Statement stm_2_body_0(5);
    BodyInstruction inst_0_2(BodyType::ACTION, stm_2_body_0, action_3_1_overflow_stacked_intention);
    body_2->add_instruction(inst_0_2);

    Statement stm_2_body_1(6);
    BodyInstruction inst_1_2(BodyType::GOAL, stm_2_body_1, EventOperator::GOAL_ADDITION);
    body_2->add_instruction(inst_1_2);

    Statement stm_2_body_2(5);
    BodyInstruction inst_2_2(BodyType::ACTION, stm_2_body_2, action_3_2_overflow_stacked_intention);
    body_2->add_instruction(inst_2_2);

    Plan plan_2(EventOperator::GOAL_ADDITION, stm_2, context_2, body_2);
    plan_base->add_plan(plan_2);

    //--------------------------------------------------------------------------

    Statement stm_3(6);
    Context * context_3 = new Context(0);
    Body * body_3 = new Body(3);

    Statement stm_3_body_0(7);
    BodyInstruction inst_0_3(BodyType::ACTION, stm_3_body_0, action_4_1_overflow_stacked_intention);
    body_3->add_instruction(inst_0_3);

    Statement stm_3_body_1(8);
    BodyInstruction inst_1_3(BodyType::GOAL, stm_3_body_1, EventOperator::GOAL_ADDITION);
    body_3->add_instruction(inst_1_3);

    Statement stm_3_body_2(7);
    BodyInstruction inst_2_3(BodyType::ACTION, stm_3_body_2, action_4_2_overflow_stacked_intention);
    body_3->add_instruction(inst_2_3);

    Plan plan_3(EventOperator::GOAL_ADDITION, stm_3, context_3, body_3);
    plan_base->add_plan(plan_3);

    //--------------------------------------------------------------------------

    Statement stm_4(8);
    Context * context_4 = new Context(0);
    Body * body_4 = new Body(1);

    Statement stm_4_body_0(9);
    BodyInstruction inst_0_4(BodyType::ACTION, stm_4_body_0, action_5_1_overflow_stacked_intention);
    body_4->add_instruction(inst_0_4);

    Plan plan_4(EventOperator::GOAL_ADDITION, stm_4, context_4, body_4);
    plan_base->add_plan(plan_4);
  }

  ~OverflowStackedIntention()
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

#endif /* UTEST_AGENT_OVERFLOW_STACKED_INTENTION_CONFIGURATION_H_ */
