/*
 * configuration.h
 *
 *  Created on: Sep 12, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_FILL_EVENT_BASE_CONFIGURATION_H_
#define UTEST_AGENT_FILL_EVENT_BASE_CONFIGURATION_H_

#include "common_lib.h"
#include "../../lib/bdi/belief_base.h"
#include "../../lib/bdi/event_base.h"
#include "../../lib/bdi/plan_base.h"
#include "../../lib/bdi/intention_base.h"

class FillEventBaseSettings
{
private:
  BeliefBase * belief_base;
  EventBase * event_base;
  PlanBase * plan_base;
  IntentionBase * intention_base;

public:
  FillEventBaseSettings()
  {
    belief_base = new BeliefBase(8);
    event_base = new EventBase(8);
    plan_base = new PlanBase(9);
    intention_base = new IntentionBase(10, 4);

    //--------------------------------------------------------------------------

    Belief belief_belief_4_do_nothing_fill_event_base_config(0, update_belief_4_revert_state, false);
    belief_base->add_belief(belief_belief_4_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Belief belief_belief_6_do_nothing_fill_event_base_config(1, update_belief_6_revert_state, false);
    belief_base->add_belief(belief_belief_6_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Belief belief_belief_2_do_nothing_fill_event_base_config(2, update_belief_2_revert_state, false);
    belief_base->add_belief(belief_belief_2_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Belief belief_belief_3_do_nothing_fill_event_base_config(3, update_belief_3_revert_state, false);
    belief_base->add_belief(belief_belief_3_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Belief belief_belief_5_do_nothing_fill_event_base_config(4, update_belief_5_revert_state, false);
    belief_base->add_belief(belief_belief_5_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Belief belief_belief_7_do_nothing_fill_event_base_config(5, update_belief_7_revert_state, false);
    belief_base->add_belief(belief_belief_7_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Belief belief_belief_1_do_nothing_fill_event_base_config(6, update_belief_1_revert_state, false);
    belief_base->add_belief(belief_belief_1_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Belief belief_belief_8_do_nothing_fill_event_base_config(7, update_belief_8_revert_state, false);
    belief_base->add_belief(belief_belief_8_do_nothing_fill_event_base_config);

    //--------------------------------------------------------------------------

    Statement stm_0(6);
    Context * context_0 = new Context(0);
    Body * body_0 = new Body(1);

    Statement stm_0_body_0(8);
    BodyInstruction inst_0_0(BodyType::ACTION, stm_0_body_0, action_do_nothing);
    body_0->add_instruction(inst_0_0);

    Plan plan_0(EventOperator::BELIEF_ADDITION, stm_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Statement stm_1(2);
    Context * context_1 = new Context(0);
    Body * body_1 = new Body(1);

    Statement stm_1_body_0(8);
    BodyInstruction inst_0_1(BodyType::ACTION, stm_1_body_0, action_do_nothing);
    body_1->add_instruction(inst_0_1);

    Plan plan_1(EventOperator::BELIEF_ADDITION, stm_1, context_1, body_1);
    plan_base->add_plan(plan_1);

    //--------------------------------------------------------------------------

    Statement stm_2(3);
    Context * context_2 = new Context(0);
    Body * body_2 = new Body(1);

    Statement stm_2_body_0(8);
    BodyInstruction inst_0_2(BodyType::ACTION, stm_2_body_0, action_do_nothing);
    body_2->add_instruction(inst_0_2);

    Plan plan_2(EventOperator::BELIEF_ADDITION, stm_2, context_2, body_2);
    plan_base->add_plan(plan_2);

    //--------------------------------------------------------------------------

    Statement stm_3(0);
    Context * context_3 = new Context(0);
    Body * body_3 = new Body(1);

    Statement stm_3_body_0(9);
    BodyInstruction inst_0_3(BodyType::GOAL, stm_3_body_0, EventOperator::GOAL_ADDITION);
    body_3->add_instruction(inst_0_3);

    Plan plan_3(EventOperator::BELIEF_ADDITION, stm_3, context_3, body_3);
    plan_base->add_plan(plan_3);

    //--------------------------------------------------------------------------

    Statement stm_4(4);
    Context * context_4 = new Context(0);
    Body * body_4 = new Body(1);

    Statement stm_4_body_0(8);
    BodyInstruction inst_0_4(BodyType::ACTION, stm_4_body_0, action_do_nothing);
    body_4->add_instruction(inst_0_4);

    Plan plan_4(EventOperator::BELIEF_ADDITION, stm_4, context_4, body_4);
    plan_base->add_plan(plan_4);

    //--------------------------------------------------------------------------

    Statement stm_5(1);
    Context * context_5 = new Context(0);
    Body * body_5 = new Body(1);

    Statement stm_5_body_0(8);
    BodyInstruction inst_0_5(BodyType::ACTION, stm_5_body_0, action_do_nothing);
    body_5->add_instruction(inst_0_5);

    Plan plan_5(EventOperator::BELIEF_ADDITION, stm_5, context_5, body_5);
    plan_base->add_plan(plan_5);

    //--------------------------------------------------------------------------

    Statement stm_6(5);
    Context * context_6 = new Context(0);
    Body * body_6 = new Body(1);

    Statement stm_6_body_0(8);
    BodyInstruction inst_0_6(BodyType::ACTION, stm_6_body_0, action_do_nothing);
    body_6->add_instruction(inst_0_6);

    Plan plan_6(EventOperator::BELIEF_ADDITION, stm_6, context_6, body_6);
    plan_base->add_plan(plan_6);

    //--------------------------------------------------------------------------

    Statement stm_7(7);
    Context * context_7 = new Context(0);
    Body * body_7 = new Body(1);

    Statement stm_7_body_0(8);
    BodyInstruction inst_0_7(BodyType::ACTION, stm_7_body_0, action_do_nothing);
    body_7->add_instruction(inst_0_7);

    Plan plan_7(EventOperator::BELIEF_ADDITION, stm_7, context_7, body_7);
    plan_base->add_plan(plan_7);

    //--------------------------------------------------------------------------

    Statement stm_8(9);
    Context * context_8 = new Context(0);
    Body * body_8 = new Body(1);

    Statement stm_8_body_0(8);
    BodyInstruction inst_0_8(BodyType::ACTION, stm_8_body_0, action_do_nothing);
    body_8->add_instruction(inst_0_8);

    Plan plan_8(EventOperator::GOAL_ADDITION, stm_8, context_8, body_8);
    plan_base->add_plan(plan_8);
  }

  ~FillEventBaseSettings()
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

#endif /* UTEST_AGENT_FILL_EVENT_BASE_CONFIGURATION_H_ */
