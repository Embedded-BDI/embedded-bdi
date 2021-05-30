 /* 
  * !goal1.
  * 
  * +belief_1 <- action_1.
  * +belief_2 <- action_2.
  * +belief_3 <- action_3.
  * +belief_4 <- action_4.
  * +belief_5 <- action_5.
  * 
  * +!goal1 : belief_2 & belief_3 <- !goal2.
  * +!goal2 <- action_6.
  * 
  * -!goal1 <- action_7.
  */ 

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "../../lib/bdi/belief_base.h"
#include "../../lib/bdi/event_base.h"
#include "../../lib/bdi/plan_base.h"
#include "../../lib/bdi/intention_base.h"
#include "functions.h"

class AgentSettings
{
private:
  Body * body_0;
  Context * context_0;
  Body * body_1;
  Context * context_1;
  Body * body_2;
  Context * context_2;
  Body * body_3;
  Context * context_3;
  Body * body_4;
  Context * context_4;
  Body * body_5;
  Context * context_5;
  Body * body_6;
  Context * context_6;
  Body * body_7;
  Context * context_7;
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

    Proposition prop_0(0);
    context_0 = new Context(0);
    body_0 = new Body(1);

    Proposition prop_0_body_0(6);
    BodyInstruction inst_0_0(BodyType::ACTION, prop_0_body_0, action_action_1);
    body_0->add_instruction(inst_0_0);

    Plan plan_0(EventOperator::BELIEF_ADDITION, prop_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Proposition prop_1(1);
    context_1 = new Context(0);
    body_1 = new Body(1);

    Proposition prop_1_body_0(7);
    BodyInstruction inst_0_1(BodyType::ACTION, prop_1_body_0, action_action_2);
    body_1->add_instruction(inst_0_1);

    Plan plan_1(EventOperator::BELIEF_ADDITION, prop_1, context_1, body_1);
    plan_base->add_plan(plan_1);

    //--------------------------------------------------------------------------

    Proposition prop_2(2);
    context_2 = new Context(0);
    body_2 = new Body(1);

    Proposition prop_2_body_0(8);
    BodyInstruction inst_0_2(BodyType::ACTION, prop_2_body_0, action_action_3);
    body_2->add_instruction(inst_0_2);

    Plan plan_2(EventOperator::BELIEF_ADDITION, prop_2, context_2, body_2);
    plan_base->add_plan(plan_2);

    //--------------------------------------------------------------------------

    Proposition prop_3(3);
    context_3 = new Context(0);
    body_3 = new Body(1);

    Proposition prop_3_body_0(9);
    BodyInstruction inst_0_3(BodyType::ACTION, prop_3_body_0, action_action_4);
    body_3->add_instruction(inst_0_3);

    Plan plan_3(EventOperator::BELIEF_ADDITION, prop_3, context_3, body_3);
    plan_base->add_plan(plan_3);

    //--------------------------------------------------------------------------

    Proposition prop_4(4);
    context_4 = new Context(0);
    body_4 = new Body(1);

    Proposition prop_4_body_0(10);
    BodyInstruction inst_0_4(BodyType::ACTION, prop_4_body_0, action_action_5);
    body_4->add_instruction(inst_0_4);

    Plan plan_4(EventOperator::BELIEF_ADDITION, prop_4, context_4, body_4);
    plan_base->add_plan(plan_4);

    //--------------------------------------------------------------------------

    Proposition prop_5(5);
    context_5 = new Context(2);
    body_5 = new Body(1);

    Proposition prop_5_belief_2(1);
    ContextCondition cond_5_0(prop_5_belief_2);
    context_5->add_context(cond_5_0);

    Proposition prop_5_belief_3(2);
    ContextCondition cond_5_1(prop_5_belief_3);
    context_5->add_context(cond_5_1);

    Proposition prop_5_body_0(11);
    BodyInstruction inst_0_5(BodyType::GOAL, prop_5_body_0, EventOperator::GOAL_ADDITION);
    body_5->add_instruction(inst_0_5);

    Plan plan_5(EventOperator::GOAL_ADDITION, prop_5, context_5, body_5);
    plan_base->add_plan(plan_5);

    //--------------------------------------------------------------------------

    Proposition prop_6(11);
    context_6 = new Context(0);
    body_6 = new Body(1);

    Proposition prop_6_body_0(12);
    BodyInstruction inst_0_6(BodyType::ACTION, prop_6_body_0, action_action_6);
    body_6->add_instruction(inst_0_6);

    Plan plan_6(EventOperator::GOAL_ADDITION, prop_6, context_6, body_6);
    plan_base->add_plan(plan_6);

    //--------------------------------------------------------------------------

    Proposition prop_7(5);
    context_7 = new Context(0);
    body_7 = new Body(1);

    Proposition prop_7_body_0(13);
    BodyInstruction inst_0_7(BodyType::ACTION, prop_7_body_0, action_action_7);
    body_7->add_instruction(inst_0_7);

    Plan plan_7(EventOperator::GOAL_DELETION, prop_7, context_7, body_7);
    plan_base->add_plan(plan_7);
  }

  ~AgentSettings()
  {
    delete body_0;
    delete context_0;
    delete body_1;
    delete context_1;
    delete body_2;
    delete context_2;
    delete body_3;
    delete context_3;
    delete body_4;
    delete context_4;
    delete body_5;
    delete context_5;
    delete body_6;
    delete context_6;
    delete body_7;
    delete context_7;
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