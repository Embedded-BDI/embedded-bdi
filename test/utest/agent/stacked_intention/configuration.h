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
 * +!goal1 <- stacked_intention_action_1; !goal2.
 * +!goal2 <- stacked_intention_action_2; !goal3.
 * +!goal3 <- stacked_intention_action_3.
 */

#ifndef UTEST_AGENT_STACKED_INTENTION_CONFIGURATION_H_
#define UTEST_AGENT_STACKED_INTENTION_CONFIGURATION_H_

#include "../../lib/bdi/belief_base.h"
#include "../../lib/bdi/event_base.h"
#include "../../lib/bdi/plan_base.h"
#include "../../lib/bdi/intention_base.h"
#include "functions.h"

class StackedIntention
{
private:
  Body body_0;
  Context context_0;
  Body body_1;
  Context context_1;
  Body body_2;
  Context context_2;
  BeliefBase belief_base;
  EventBase event_base;
  PlanBase plan_base;
  IntentionBase intention_base;

public:
  StackedIntention()
  {
    belief_base = BeliefBase(0);
    event_base = EventBase(1);
    plan_base = PlanBase(3);
    intention_base = IntentionBase(1, 3);

    //--------------------------------------------------------------------------

    Event event_0(EventOperator::GOAL_ADDITION, 0);
    event_base.add_event(event_0);

    //--------------------------------------------------------------------------

    Proposition prop_0(0);
    context_0 = Context(0);
    body_0 = Body(2);

    Proposition prop_0_body_0(1);
    BodyInstruction inst_0_0(BodyType::ACTION, prop_0_body_0, action_stacked_intention_action_1);
    body_0.add_instruction(inst_0_0);

    Proposition prop_0_body_1(2);
    BodyInstruction inst_1_0(BodyType::GOAL, prop_0_body_1, EventOperator::GOAL_ADDITION);
    body_0.add_instruction(inst_1_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, prop_0, &context_0, &body_0);
    plan_base.add_plan(plan_0);

    //--------------------------------------------------------------------------

    Proposition prop_1(2);
    context_1 = Context(0);
    body_1 = Body(2);

    Proposition prop_1_body_0(3);
    BodyInstruction inst_0_1(BodyType::ACTION, prop_1_body_0, action_stacked_intention_action_2);
    body_1.add_instruction(inst_0_1);

    Proposition prop_1_body_1(4);
    BodyInstruction inst_1_1(BodyType::GOAL, prop_1_body_1, EventOperator::GOAL_ADDITION);
    body_1.add_instruction(inst_1_1);

    Plan plan_1(EventOperator::GOAL_ADDITION, prop_1, &context_1, &body_1);
    plan_base.add_plan(plan_1);

    //--------------------------------------------------------------------------

    Proposition prop_2(4);
    context_2 = Context(0);
    body_2 = Body(1);

    Proposition prop_2_body_0(5);
    BodyInstruction inst_0_2(BodyType::ACTION, prop_2_body_0, action_stacked_intention_action_3);
    body_2.add_instruction(inst_0_2);

    Plan plan_2(EventOperator::GOAL_ADDITION, prop_2, &context_2, &body_2);
    plan_base.add_plan(plan_2);
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

#endif /* UTEST_AGENT_STACKED_INTENTION_CONFIGURATION_H_ */
