/*
 * configuration.h
 *
 *  Created on: Sep 17, 2020
 *      Author: Matuzalem Muller
 * 
 * AgentSpeak code:
 *
 * !goal1.
 * !goal2.
 * 
 * +!goal1 <- failed_intention_return_false.
 * -!goal1 <- failed_intention_deletion_1.
 * 
 * +!goal2 <- failed_intention_return_true; !goal3; failed_intention_return_true.
 * 
 * +!goal3 <- failed_intention_return_true; !goal4.
 * 
 * +!goal4 <- failed_intention_return_false.
 * -!goal4 <- failed_intention_deletion_1.
 * -!goal4 <- failed_intention_deletion_2.
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
  Body body_6;
  Context context_6;
  BeliefBase belief_base;
  EventBase event_base;
  PlanBase plan_base;
  IntentionBase intention_base;

public:
  FailedIntention()
  {
    belief_base = BeliefBase(0);
    event_base = EventBase(2);
    plan_base = PlanBase(7);
    intention_base = IntentionBase(2, 4);

    //--------------------------------------------------------------------------

    Event event_0(EventOperator::GOAL_ADDITION, 0);
    event_base.add_event(event_0);

    //--------------------------------------------------------------------------

    Event event_1(EventOperator::GOAL_ADDITION, 1);
    event_base.add_event(event_1);

    //--------------------------------------------------------------------------

    Proposition prop_0(0);
    context_0 = Context(0);
    body_0 = Body(1);

    Proposition prop_0_body_0(2);
    BodyInstruction inst_0_0(BodyType::ACTION, prop_0_body_0, action_failed_intention_return_false);
    body_0.add_instruction(inst_0_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, prop_0, &context_0, &body_0);
    plan_base.add_plan(plan_0);

    //--------------------------------------------------------------------------

    Proposition prop_1(0);
    context_1 = Context(0);
    body_1 = Body(1);

    Proposition prop_1_body_0(3);
    BodyInstruction inst_0_1(BodyType::ACTION, prop_1_body_0, action_failed_intention_deletion_1);
    body_1.add_instruction(inst_0_1);

    Plan plan_1(EventOperator::GOAL_DELETION, prop_1, &context_1, &body_1);
    plan_base.add_plan(plan_1);

    //--------------------------------------------------------------------------

    Proposition prop_2(1);
    context_2 = Context(0);
    body_2 = Body(3);

    Proposition prop_2_body_0(4);
    BodyInstruction inst_0_2(BodyType::ACTION, prop_2_body_0, action_failed_intention_return_true);
    body_2.add_instruction(inst_0_2);

    Proposition prop_2_body_1(5);
    BodyInstruction inst_1_2(BodyType::GOAL, prop_2_body_1, EventOperator::GOAL_ADDITION);
    body_2.add_instruction(inst_1_2);

    Proposition prop_2_body_2(4);
    BodyInstruction inst_2_2(BodyType::ACTION, prop_2_body_2, action_failed_intention_return_true);
    body_2.add_instruction(inst_2_2);

    Plan plan_2(EventOperator::GOAL_ADDITION, prop_2, &context_2, &body_2);
    plan_base.add_plan(plan_2);

    //--------------------------------------------------------------------------

    Proposition prop_3(5);
    context_3 = Context(0);
    body_3 = Body(2);

    Proposition prop_3_body_0(4);
    BodyInstruction inst_0_3(BodyType::ACTION, prop_3_body_0, action_failed_intention_return_true);
    body_3.add_instruction(inst_0_3);

    Proposition prop_3_body_1(6);
    BodyInstruction inst_1_3(BodyType::GOAL, prop_3_body_1, EventOperator::GOAL_ADDITION);
    body_3.add_instruction(inst_1_3);

    Plan plan_3(EventOperator::GOAL_ADDITION, prop_3, &context_3, &body_3);
    plan_base.add_plan(plan_3);

    //--------------------------------------------------------------------------

    Proposition prop_4(6);
    context_4 = Context(0);
    body_4 = Body(1);

    Proposition prop_4_body_0(2);
    BodyInstruction inst_0_4(BodyType::ACTION, prop_4_body_0, action_failed_intention_return_false);
    body_4.add_instruction(inst_0_4);

    Plan plan_4(EventOperator::GOAL_ADDITION, prop_4, &context_4, &body_4);
    plan_base.add_plan(plan_4);

    //--------------------------------------------------------------------------

    Proposition prop_5(6);
    context_5 = Context(0);
    body_5 = Body(1);

    Proposition prop_5_body_0(3);
    BodyInstruction inst_0_5(BodyType::ACTION, prop_5_body_0, action_failed_intention_deletion_1);
    body_5.add_instruction(inst_0_5);

    Plan plan_5(EventOperator::GOAL_DELETION, prop_5, &context_5, &body_5);
    plan_base.add_plan(plan_5);

    //--------------------------------------------------------------------------

    Proposition prop_6(6);
    context_6 = Context(0);
    body_6 = Body(1);

    Proposition prop_6_body_0(7);
    BodyInstruction inst_0_6(BodyType::ACTION, prop_6_body_0, action_failed_intention_deletion_2);
    body_6.add_instruction(inst_0_6);

    Plan plan_6(EventOperator::GOAL_DELETION, prop_6, &context_6, &body_6);
    plan_base.add_plan(plan_6);
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

#endif /* UTEST_AGENT_FAILED_INTENTION_CONFIGURATION_H_ */
