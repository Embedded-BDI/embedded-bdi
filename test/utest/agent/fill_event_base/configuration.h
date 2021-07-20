/*
 * configuration.h
 *
 *  Created on: Sep 12, 2020
 *      Author: Matuzalem Muller
 *
 * AgentSpeak code:
 *
 * +belief_belief_1_do_nothing_fill_event_base_config <- fill_event_base_do_nothing.
 * +belief_belief_2_do_nothing_fill_event_base_config <- fill_event_base_do_nothing.
 * +belief_belief_3_do_nothing_fill_event_base_config <- fill_event_base_do_nothing.
 * +belief_belief_4_do_nothing_fill_event_base_config <- !goal.
 * +belief_belief_5_do_nothing_fill_event_base_config <- fill_event_base_do_nothing.
 * +belief_belief_6_do_nothing_fill_event_base_config <- fill_event_base_do_nothing.
 * +belief_belief_7_do_nothing_fill_event_base_config <- fill_event_base_do_nothing.
 * +belief_belief_8_do_nothing_fill_event_base_config <- fill_event_base_do_nothing.
 * +!goal <- do_nothing.

 */

#ifndef UTEST_AGENT_FILL_EVENT_BASE_CONFIGURATION_H_
#define UTEST_AGENT_FILL_EVENT_BASE_CONFIGURATION_H_

#include "functions.h"
#include "../../lib/bdi/belief_base.h"
#include "../../lib/bdi/event_base.h"
#include "../../lib/bdi/plan_base.h"
#include "../../lib/bdi/intention_base.h"

class FillEventBaseSettings
{
private:
  BeliefBase belief_base;
  EventBase event_base;
  PlanBase plan_base;
  IntentionBase intention_base;

public:
  FillEventBaseSettings()
  {
    belief_base = BeliefBase(8);
    event_base = EventBase(8);
    plan_base = PlanBase(9);
    intention_base = IntentionBase(10, 4);

    //--------------------------------------------------------------------------

    Belief belief_belief_belief_1_do_nothing_fill_event_base_config(0, update_belief_belief_1_do_nothing_fill_event_base_config, false);
    belief_base.add_belief(belief_belief_belief_1_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Belief belief_belief_belief_2_do_nothing_fill_event_base_config(1, update_belief_belief_2_do_nothing_fill_event_base_config, false);
    belief_base.add_belief(belief_belief_belief_2_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Belief belief_belief_belief_3_do_nothing_fill_event_base_config(2, update_belief_belief_3_do_nothing_fill_event_base_config, false);
    belief_base.add_belief(belief_belief_belief_3_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Belief belief_belief_belief_4_do_nothing_fill_event_base_config(3, update_belief_belief_4_do_nothing_fill_event_base_config, false);
    belief_base.add_belief(belief_belief_belief_4_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Belief belief_belief_belief_5_do_nothing_fill_event_base_config(4, update_belief_belief_5_do_nothing_fill_event_base_config, false);
    belief_base.add_belief(belief_belief_belief_5_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Belief belief_belief_belief_6_do_nothing_fill_event_base_config(5, update_belief_belief_6_do_nothing_fill_event_base_config, false);
    belief_base.add_belief(belief_belief_belief_6_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Belief belief_belief_belief_7_do_nothing_fill_event_base_config(6, update_belief_belief_7_do_nothing_fill_event_base_config, false);
    belief_base.add_belief(belief_belief_belief_7_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Belief belief_belief_belief_8_do_nothing_fill_event_base_config(7, update_belief_belief_8_do_nothing_fill_event_base_config, false);
    belief_base.add_belief(belief_belief_belief_8_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Proposition prop_0(6);
    Context context_0 = Context(0);
    Body body_0 = Body(1);

    Proposition prop_0_body_0(8);
    BodyInstruction inst_0_0(BodyType::ACTION, prop_0_body_0, action_fill_event_base_do_nothing);
    body_0.add_instruction(inst_0_0);

    Plan plan_0(EventOperator::BELIEF_ADDITION, prop_0, &context_0, &body_0);
    plan_base.add_plan(plan_0);

    //--------------------------------------------------------------------------

    Proposition prop_1(2);
    Context context_1 = Context(0);
    Body body_1 = Body(1);

    Proposition prop_1_body_0(8);
    BodyInstruction inst_0_1(BodyType::ACTION, prop_1_body_0, action_fill_event_base_do_nothing);
    body_1.add_instruction(inst_0_1);

    Plan plan_1(EventOperator::BELIEF_ADDITION, prop_1, &context_1, &body_1);
    plan_base.add_plan(plan_1);

    //--------------------------------------------------------------------------

    Proposition prop_2(3);
    Context context_2 = Context(0);
    Body body_2 = Body(1);

    Proposition prop_2_body_0(8);
    BodyInstruction inst_0_2(BodyType::ACTION, prop_2_body_0, action_fill_event_base_do_nothing);
    body_2.add_instruction(inst_0_2);

    Plan plan_2(EventOperator::BELIEF_ADDITION, prop_2, &context_2, &body_2);
    plan_base.add_plan(plan_2);

    //--------------------------------------------------------------------------

    Proposition prop_3(0);
    Context context_3 = Context(0);
    Body body_3 = Body(1);

    Proposition prop_3_body_0(9);
    BodyInstruction inst_0_3(BodyType::GOAL, prop_3_body_0, EventOperator::GOAL_ADDITION);
    body_3.add_instruction(inst_0_3);

    Plan plan_3(EventOperator::BELIEF_ADDITION, prop_3, &context_3, &body_3);
    plan_base.add_plan(plan_3);

    //--------------------------------------------------------------------------

    Proposition prop_4(4);
    Context context_4 = Context(0);
    Body body_4 = Body(1);

    Proposition prop_4_body_0(8);
    BodyInstruction inst_0_4(BodyType::ACTION, prop_4_body_0, action_fill_event_base_do_nothing);
    body_4.add_instruction(inst_0_4);

    Plan plan_4(EventOperator::BELIEF_ADDITION, prop_4, &context_4, &body_4);
    plan_base.add_plan(plan_4);

    //--------------------------------------------------------------------------

    Proposition prop_5(1);
    Context context_5 = Context(0);
    Body body_5 = Body(1);

    Proposition prop_5_body_0(8);
    BodyInstruction inst_0_5(BodyType::ACTION, prop_5_body_0, action_fill_event_base_do_nothing);
    body_5.add_instruction(inst_0_5);

    Plan plan_5(EventOperator::BELIEF_ADDITION, prop_5, &context_5, &body_5);
    plan_base.add_plan(plan_5);

    //--------------------------------------------------------------------------

    Proposition prop_6(5);
    Context context_6 = Context(0);
    Body body_6 = Body(1);

    Proposition prop_6_body_0(8);
    BodyInstruction inst_0_6(BodyType::ACTION, prop_6_body_0, action_fill_event_base_do_nothing);
    body_6.add_instruction(inst_0_6);

    Plan plan_6(EventOperator::BELIEF_ADDITION, prop_6, &context_6, &body_6);
    plan_base.add_plan(plan_6);

    //--------------------------------------------------------------------------

    Proposition prop_7(7);
    Context context_7 = Context(0);
    Body body_7 = Body(1);

    Proposition prop_7_body_0(8);
    BodyInstruction inst_0_7(BodyType::ACTION, prop_7_body_0, action_fill_event_base_do_nothing);
    body_7.add_instruction(inst_0_7);

    Plan plan_7(EventOperator::BELIEF_ADDITION, prop_7, &context_7, &body_7);
    plan_base.add_plan(plan_7);

    //--------------------------------------------------------------------------

    Proposition prop_8(9);
    Context context_8 = Context(0);
    Body body_8 = Body(1);

    Proposition prop_8_body_0(8);
    BodyInstruction inst_0_8(BodyType::ACTION, prop_8_body_0, action_fill_event_base_do_nothing);
    body_8.add_instruction(inst_0_8);

    Plan plan_8(EventOperator::GOAL_ADDITION, prop_8, &context_8, &body_8);
    plan_base.add_plan(plan_8);
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

#endif /* UTEST_AGENT_FILL_EVENT_BASE_CONFIGURATION_H_ */
