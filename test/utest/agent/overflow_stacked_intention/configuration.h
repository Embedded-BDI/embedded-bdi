/*
 * configuration.h
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
 * 
 * AgentSpeak code:
 *
 * !goal1.
 * 
 * +!goal1 <- overflow_stacked_intention_1_1; !goal2; overflow_stacked_intention_1_2.
 * +!goal2 <- overflow_stacked_intention_2_1; !goal3; overflow_stacked_intention_2_2.
 * +!goal3 <- overflow_stacked_intention_3_1; !goal4; overflow_stacked_intention_3_2.
 * +!goal4 <- overflow_stacked_intention_4_1; !goal5; overflow_stacked_intention_4_2.
 * +!goal5 <- overflow_stacked_intention_5_1.
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
  OverflowStackedIntention()
  {
    belief_base = BeliefBase(0);
    event_base = EventBase(1);
    plan_base = PlanBase(5);
    intention_base = IntentionBase(1, 3);

    //--------------------------------------------------------------------------

    Event event_0(EventOperator::GOAL_ADDITION, 0);
    event_base.add_event(event_0);

    //--------------------------------------------------------------------------

    Proposition prop_0(0);
    context_0 = Context(0);
    body_0 = Body(3);

    Proposition prop_0_body_0(1);
    BodyInstruction inst_0_0(BodyType::ACTION, prop_0_body_0, action_overflow_stacked_intention_1_1);
    body_0.add_instruction(inst_0_0);

    Proposition prop_0_body_1(2);
    BodyInstruction inst_1_0(BodyType::GOAL, prop_0_body_1, EventOperator::GOAL_ADDITION);
    body_0.add_instruction(inst_1_0);

    Proposition prop_0_body_2(3);
    BodyInstruction inst_2_0(BodyType::ACTION, prop_0_body_2, action_overflow_stacked_intention_1_2);
    body_0.add_instruction(inst_2_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, prop_0, &context_0, &body_0);
    plan_base.add_plan(plan_0);

    //--------------------------------------------------------------------------

    Proposition prop_1(2);
    context_1 = Context(0);
    body_1 = Body(3);

    Proposition prop_1_body_0(4);
    BodyInstruction inst_0_1(BodyType::ACTION, prop_1_body_0, action_overflow_stacked_intention_2_1);
    body_1.add_instruction(inst_0_1);

    Proposition prop_1_body_1(5);
    BodyInstruction inst_1_1(BodyType::GOAL, prop_1_body_1, EventOperator::GOAL_ADDITION);
    body_1.add_instruction(inst_1_1);

    Proposition prop_1_body_2(6);
    BodyInstruction inst_2_1(BodyType::ACTION, prop_1_body_2, action_overflow_stacked_intention_2_2);
    body_1.add_instruction(inst_2_1);

    Plan plan_1(EventOperator::GOAL_ADDITION, prop_1, &context_1, &body_1);
    plan_base.add_plan(plan_1);

    //--------------------------------------------------------------------------

    Proposition prop_2(5);
    context_2 = Context(0);
    body_2 = Body(3);

    Proposition prop_2_body_0(7);
    BodyInstruction inst_0_2(BodyType::ACTION, prop_2_body_0, action_overflow_stacked_intention_3_1);
    body_2.add_instruction(inst_0_2);

    Proposition prop_2_body_1(8);
    BodyInstruction inst_1_2(BodyType::GOAL, prop_2_body_1, EventOperator::GOAL_ADDITION);
    body_2.add_instruction(inst_1_2);

    Proposition prop_2_body_2(9);
    BodyInstruction inst_2_2(BodyType::ACTION, prop_2_body_2, action_overflow_stacked_intention_3_2);
    body_2.add_instruction(inst_2_2);

    Plan plan_2(EventOperator::GOAL_ADDITION, prop_2, &context_2, &body_2);
    plan_base.add_plan(plan_2);

    //--------------------------------------------------------------------------

    Proposition prop_3(8);
    context_3 = Context(0);
    body_3 = Body(3);

    Proposition prop_3_body_0(10);
    BodyInstruction inst_0_3(BodyType::ACTION, prop_3_body_0, action_overflow_stacked_intention_4_1);
    body_3.add_instruction(inst_0_3);

    Proposition prop_3_body_1(11);
    BodyInstruction inst_1_3(BodyType::GOAL, prop_3_body_1, EventOperator::GOAL_ADDITION);
    body_3.add_instruction(inst_1_3);

    Proposition prop_3_body_2(12);
    BodyInstruction inst_2_3(BodyType::ACTION, prop_3_body_2, action_overflow_stacked_intention_4_2);
    body_3.add_instruction(inst_2_3);

    Plan plan_3(EventOperator::GOAL_ADDITION, prop_3, &context_3, &body_3);
    plan_base.add_plan(plan_3);

    //--------------------------------------------------------------------------

    Proposition prop_4(11);
    context_4 = Context(0);
    body_4 = Body(1);

    Proposition prop_4_body_0(13);
    BodyInstruction inst_0_4(BodyType::ACTION, prop_4_body_0, action_overflow_stacked_intention_5_1);
    body_4.add_instruction(inst_0_4);

    Plan plan_4(EventOperator::GOAL_ADDITION, prop_4, &context_4, &body_4);
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

#endif /* UTEST_AGENT_OVERFLOW_STACKED_INTENTION_CONFIGURATION_H_ */
