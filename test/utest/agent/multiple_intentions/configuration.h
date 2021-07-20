/*
 * configuration.h
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_MULTIPLE_INTENTIONS_CONFIGURATION_H_
#define UTEST_AGENT_MULTIPLE_INTENTIONS_CONFIGURATION_H_

#include "functions.h"
#include "../../lib/bdi/belief_base.h"
#include "../../lib/bdi/event_base.h"
#include "../../lib/bdi/plan_base.h"
#include "../../lib/bdi/intention_base.h"

class MultipleIntentions
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
  Body body_5;
  Context context_5;
  BeliefBase belief_base;
  EventBase event_base;
  PlanBase plan_base;
  IntentionBase intention_base;

public:
  MultipleIntentions()
  {
    belief_base = BeliefBase(0);
    event_base = EventBase(3);
    plan_base = PlanBase(6);
    intention_base = IntentionBase(3, 4);

    //--------------------------------------------------------------------------

    Event event_0(EventOperator::GOAL_ADDITION, 0);
    event_base.add_event(event_0);

    //--------------------------------------------------------------------------

    Event event_1(EventOperator::GOAL_ADDITION, 1);
    event_base.add_event(event_1);

    //--------------------------------------------------------------------------

    Event event_2(EventOperator::GOAL_ADDITION, 2);
    event_base.add_event(event_2);

    //--------------------------------------------------------------------------

    Proposition prop_0(0);
    context_0 = Context(0);
    body_0 = Body(2);

    Proposition prop_0_body_0(3);
    BodyInstruction inst_0_0(BodyType::ACTION, prop_0_body_0, action_multiple_intentions_action_1);
    body_0.add_instruction(inst_0_0);

    Proposition prop_0_body_1(1);
    BodyInstruction inst_1_0(BodyType::GOAL, prop_0_body_1, EventOperator::GOAL_ADDITION);
    body_0.add_instruction(inst_1_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, prop_0, &context_0, &body_0);
    plan_base.add_plan(plan_0);

    //--------------------------------------------------------------------------

    Proposition prop_1(1);
    context_1 = Context(0);
    body_1 = Body(1);

    Proposition prop_1_body_0(4);
    BodyInstruction inst_0_1(BodyType::ACTION, prop_1_body_0, action_multiple_intentions_action_2);
    body_1.add_instruction(inst_0_1);

    Plan plan_1(EventOperator::GOAL_ADDITION, prop_1, &context_1, &body_1);
    plan_base.add_plan(plan_1);

    //--------------------------------------------------------------------------

    Proposition prop_2(2);
    context_2 = Context(0);
    body_2 = Body(2);

    Proposition prop_2_body_0(5);
    BodyInstruction inst_0_2(BodyType::ACTION, prop_2_body_0, action_multiple_intentions_action_3);
    body_2.add_instruction(inst_0_2);

    Proposition prop_2_body_1(6);
    BodyInstruction inst_1_2(BodyType::GOAL, prop_2_body_1, EventOperator::GOAL_ADDITION);
    body_2.add_instruction(inst_1_2);

    Plan plan_2(EventOperator::GOAL_ADDITION, prop_2, &context_2, &body_2);
    plan_base.add_plan(plan_2);

    //--------------------------------------------------------------------------

    Proposition prop_3(6);
    context_3 = Context(0);
    body_3 = Body(1);

    Proposition prop_3_body_0(7);
    BodyInstruction inst_0_3(BodyType::ACTION, prop_3_body_0, action_multiple_intentions_action_4);
    body_3.add_instruction(inst_0_3);

    Plan plan_3(EventOperator::GOAL_ADDITION, prop_3, &context_3, &body_3);
    plan_base.add_plan(plan_3);

    //--------------------------------------------------------------------------

    Proposition prop_4(8);
    context_4 = Context(0);
    body_4 = Body(2);

    Proposition prop_4_body_0(9);
    BodyInstruction inst_0_4(BodyType::ACTION, prop_4_body_0, action_multiple_intentions_action_5);
    body_4.add_instruction(inst_0_4);

    Proposition prop_4_body_1(10);
    BodyInstruction inst_1_4(BodyType::GOAL, prop_4_body_1, EventOperator::GOAL_ADDITION);
    body_4.add_instruction(inst_1_4);

    Plan plan_4(EventOperator::GOAL_ADDITION, prop_4, &context_4, &body_4);
    plan_base.add_plan(plan_4);

    //--------------------------------------------------------------------------

    Proposition prop_5(10);
    context_5 = Context(0);
    body_5 = Body(1);

    Proposition prop_5_body_0(11);
    BodyInstruction inst_0_5(BodyType::ACTION, prop_5_body_0, action_multiple_intentions_action_6);
    body_5.add_instruction(inst_0_5);

    Plan plan_5(EventOperator::GOAL_ADDITION, prop_5, &context_5, &body_5);
    plan_base.add_plan(plan_5);
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

#endif /* UTEST_AGENT_MULTIPLE_INTENTIONS_CONFIGURATION_H_ */
