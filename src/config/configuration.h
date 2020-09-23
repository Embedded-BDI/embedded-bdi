#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "../../lib/bdi/belief_base.h"
#include "../../lib/bdi/event_base.h"
#include "../../lib/bdi/plan_base.h"
#include "../../lib/bdi/intention_base.h"
#include "../../data/functions.h"

class AgentSettings
{
private:
  BeliefBase * belief_base;
  EventBase * event_base;
  PlanBase * plan_base;
  IntentionBase * intention_base;

public:
  AgentSettings()
  {
    belief_base = new BeliefBase(5);
    event_base = new EventBase(6);
    plan_base = new PlanBase(8);
    intention_base = new IntentionBase(10, 4);

    //--------------------------------------------------------------------------

    Belief belief_belief_1(0, update_belief_1, false);
    belief_base->add_belief(belief_belief_1);

    //--------------------------------------------------------------------------

    Belief belief_belief_2(1, update_belief_2, false);
    belief_base->add_belief(belief_belief_2);

    //--------------------------------------------------------------------------

    Belief belief_belief_3(2, update_belief_3, false);
    belief_base->add_belief(belief_belief_3);

    //--------------------------------------------------------------------------

    Belief belief_belief_4(3, update_belief_4, false);
    belief_base->add_belief(belief_belief_4);

    //--------------------------------------------------------------------------

    Belief belief_belief_5(4, update_belief_5, false);
    belief_base->add_belief(belief_belief_5);

    //--------------------------------------------------------------------------

    Event event_5(EventOperator::GOAL_ADDITION, 5);
    event_base->add_event(event_5);

    //--------------------------------------------------------------------------

    Statement stm_0(0);
    Context * context_0 = new Context(0);
    Body * body_0 = new Body(1);

    Statement stm_0_body_0(6);
    BodyInstruction inst_0_0(BodyType::ACTION, stm_0_body_0, action_action_1);
    body_0->add_instruction(inst_0_0);

    Plan plan_0(EventOperator::BELIEF_ADDITION, stm_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Statement stm_1(1);
    Context * context_1 = new Context(0);
    Body * body_1 = new Body(1);

    Statement stm_1_body_0(7);
    BodyInstruction inst_0_1(BodyType::ACTION, stm_1_body_0, action_action_2);
    body_1->add_instruction(inst_0_1);

    Plan plan_1(EventOperator::BELIEF_ADDITION, stm_1, context_1, body_1);
    plan_base->add_plan(plan_1);

    //--------------------------------------------------------------------------

    Statement stm_2(2);
    Context * context_2 = new Context(0);
    Body * body_2 = new Body(1);

    Statement stm_2_body_0(8);
    BodyInstruction inst_0_2(BodyType::ACTION, stm_2_body_0, action_action_3);
    body_2->add_instruction(inst_0_2);

    Plan plan_2(EventOperator::BELIEF_ADDITION, stm_2, context_2, body_2);
    plan_base->add_plan(plan_2);

    //--------------------------------------------------------------------------

    Statement stm_3(3);
    Context * context_3 = new Context(0);
    Body * body_3 = new Body(1);

    Statement stm_3_body_0(9);
    BodyInstruction inst_0_3(BodyType::ACTION, stm_3_body_0, action_action_4);
    body_3->add_instruction(inst_0_3);

    Plan plan_3(EventOperator::BELIEF_ADDITION, stm_3, context_3, body_3);
    plan_base->add_plan(plan_3);

    //--------------------------------------------------------------------------

    Statement stm_4(4);
    Context * context_4 = new Context(0);
    Body * body_4 = new Body(1);

    Statement stm_4_body_0(10);
    BodyInstruction inst_0_4(BodyType::ACTION, stm_4_body_0, action_action_5);
    body_4->add_instruction(inst_0_4);

    Plan plan_4(EventOperator::BELIEF_ADDITION, stm_4, context_4, body_4);
    plan_base->add_plan(plan_4);

    //--------------------------------------------------------------------------

    Statement stm_5(5);
    Context * context_5 = new Context(2);
    Body * body_5 = new Body(1);

    Statement stm_5_belief_2(1);
    ContextCondition cond_5_0(stm_5_belief_2, true);
    context_5->add_context(cond_5_0);

    Statement stm_5_belief_3(2);
    ContextCondition cond_5_1(stm_5_belief_3, true);
    context_5->add_context(cond_5_1);

    Statement stm_5_body_0(11);
    BodyInstruction inst_0_5(BodyType::GOAL, stm_5_body_0, EventOperator::GOAL_ADDITION);
    body_5->add_instruction(inst_0_5);

    Plan plan_5(EventOperator::GOAL_ADDITION, stm_5, context_5, body_5);
    plan_base->add_plan(plan_5);

    //--------------------------------------------------------------------------

    Statement stm_6(11);
    Context * context_6 = new Context(0);
    Body * body_6 = new Body(1);

    Statement stm_6_body_0(12);
    BodyInstruction inst_0_6(BodyType::ACTION, stm_6_body_0, action_action_6);
    body_6->add_instruction(inst_0_6);

    Plan plan_6(EventOperator::GOAL_ADDITION, stm_6, context_6, body_6);
    plan_base->add_plan(plan_6);

    //--------------------------------------------------------------------------

    Statement stm_7(5);
    Context * context_7 = new Context(0);
    Body * body_7 = new Body(1);

    Statement stm_7_body_0(13);
    BodyInstruction inst_0_7(BodyType::ACTION, stm_7_body_0, action_action_7);
    body_7->add_instruction(inst_0_7);

    Plan plan_7(EventOperator::GOAL_DELETION, stm_7, context_7, body_7);
    plan_base->add_plan(plan_7);
  }

  ~AgentSettings()
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

#endif /*CONFIGURATION_H_ */