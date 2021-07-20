/*
 * configuration.h
 *
 *  Created on: Sep 18, 2020
 *      Author: Matuzalem Muller
 * 
 * AgentSpeak code:
 *
 * +belief_1 <- ovflw_int_base_action_1; ovflw_int_base_action_1; ovflw_int_base_action_1; ovflw_int_base_action_1.
 * +belief_2 <- ovflw_int_base_action_2; ovflw_int_base_action_2; ovflw_int_base_action_2.
 * +belief_3 <- ovflw_int_base_action_3; ovflw_int_base_action_3.
 * +belief_4 <- ovflw_int_base_action_4.
 * +belief_5 <- ovflw_int_base_action_5.
 */

#ifndef UTEST_AGENT_OVERFLOW_INTENTION_BASE_CONFIGURATION_H_
#define UTEST_AGENT_OVERFLOW_INTENTION_BASE_CONFIGURATION_H_

#include "../../lib/bdi/belief_base.h"
#include "../../lib/bdi/event_base.h"
#include "../../lib/bdi/plan_base.h"
#include "../../lib/bdi/intention_base.h"
#include "functions.h"

class OverflowIntentionBase
{
private:
  Body body_0;
  Context context_0;
  Body body_1;
  Context context_1;
  Body body_2;
  Context context_2;
  Body body_3;
  Context context_3;
  Body body_4;
  Context context_4;
  BeliefBase belief_base;
  EventBase event_base;
  PlanBase plan_base;
  IntentionBase intention_base;

public:
  OverflowIntentionBase()
  {
    belief_base = BeliefBase(5);
    event_base = EventBase(5);
    plan_base = PlanBase(5);
    intention_base = IntentionBase(5, 4);

    //--------------------------------------------------------------------------

    Belief belief_belief_1(0, update_belief_1, false);
    belief_base.add_belief(belief_belief_1);

    //--------------------------------------------------------------------------

    Belief belief_belief_2(1, update_belief_2, false);
    belief_base.add_belief(belief_belief_2);

    //--------------------------------------------------------------------------

    Belief belief_belief_3(2, update_belief_3, false);
    belief_base.add_belief(belief_belief_3);

    //--------------------------------------------------------------------------

    Belief belief_belief_4(3, update_belief_4, false);
    belief_base.add_belief(belief_belief_4);

    //--------------------------------------------------------------------------

    Belief belief_belief_5(4, update_belief_5, false);
    belief_base.add_belief(belief_belief_5);

    //--------------------------------------------------------------------------

    Proposition prop_0(0);
    context_0 = Context(0);
    body_0 = Body(4);

    Proposition prop_0_body_0(5);
    BodyInstruction inst_0_0(BodyType::ACTION, prop_0_body_0, action_ovflw_int_base_action_1);
    body_0.add_instruction(inst_0_0);

    Proposition prop_0_body_1(5);
    BodyInstruction inst_1_0(BodyType::ACTION, prop_0_body_1, action_ovflw_int_base_action_1);
    body_0.add_instruction(inst_1_0);

    Proposition prop_0_body_2(5);
    BodyInstruction inst_2_0(BodyType::ACTION, prop_0_body_2, action_ovflw_int_base_action_1);
    body_0.add_instruction(inst_2_0);

    Proposition prop_0_body_3(5);
    BodyInstruction inst_3_0(BodyType::ACTION, prop_0_body_3, action_ovflw_int_base_action_1);
    body_0.add_instruction(inst_3_0);

    Plan plan_0(EventOperator::BELIEF_ADDITION, prop_0, &context_0, &body_0);
    plan_base.add_plan(plan_0);

    //--------------------------------------------------------------------------

    Proposition prop_1(1);
    context_1 = Context(0);
    body_1 = Body(3);

    Proposition prop_1_body_0(6);
    BodyInstruction inst_0_1(BodyType::ACTION, prop_1_body_0, action_ovflw_int_base_action_2);
    body_1.add_instruction(inst_0_1);

    Proposition prop_1_body_1(6);
    BodyInstruction inst_1_1(BodyType::ACTION, prop_1_body_1, action_ovflw_int_base_action_2);
    body_1.add_instruction(inst_1_1);

    Proposition prop_1_body_2(6);
    BodyInstruction inst_2_1(BodyType::ACTION, prop_1_body_2, action_ovflw_int_base_action_2);
    body_1.add_instruction(inst_2_1);

    Plan plan_1(EventOperator::BELIEF_ADDITION, prop_1, &context_1, &body_1);
    plan_base.add_plan(plan_1);

    //--------------------------------------------------------------------------

    Proposition prop_2(2);
    context_2 = Context(0);
    body_2 = Body(2);

    Proposition prop_2_body_0(7);
    BodyInstruction inst_0_2(BodyType::ACTION, prop_2_body_0, action_ovflw_int_base_action_3);
    body_2.add_instruction(inst_0_2);

    Proposition prop_2_body_1(7);
    BodyInstruction inst_1_2(BodyType::ACTION, prop_2_body_1, action_ovflw_int_base_action_3);
    body_2.add_instruction(inst_1_2);

    Plan plan_2(EventOperator::BELIEF_ADDITION, prop_2, &context_2, &body_2);
    plan_base.add_plan(plan_2);

    //--------------------------------------------------------------------------

    Proposition prop_3(3);
    context_3 = Context(0);
    body_3 = Body(1);

    Proposition prop_3_body_0(8);
    BodyInstruction inst_0_3(BodyType::ACTION, prop_3_body_0, action_ovflw_int_base_action_4);
    body_3.add_instruction(inst_0_3);

    Plan plan_3(EventOperator::BELIEF_ADDITION, prop_3, &context_3, &body_3);
    plan_base.add_plan(plan_3);

    //--------------------------------------------------------------------------

    Proposition prop_4(4);
    context_4 = Context(0);
    body_4 = Body(1);

    Proposition prop_4_body_0(9);
    BodyInstruction inst_0_4(BodyType::ACTION, prop_4_body_0, action_ovflw_int_base_action_5);
    body_4.add_instruction(inst_0_4);

    Plan plan_4(EventOperator::BELIEF_ADDITION, prop_4, &context_4, &body_4);
    plan_base.add_plan(plan_4);
  }

  BeliefBase * get_belief_base()
  {
    return &belief_base;
  }

  EventBase * get_event_base()
  {
    return &event_base;
  }

  PlanBase * get_plan_base()
  {
    return &plan_base;
  }

  IntentionBase * get_intention_base()
  {
    return &intention_base;
  }
};

#endif /* UTEST_AGENT_OVERFLOW_INTENTION_BASE_CONFIGURATION_H_ */
