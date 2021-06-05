/*
 * AgentSpeak code:
 *
 * !start.
 * 
 * +!start <- +sunny.
 * +sunny <- +happy.
 * +happy : sunny & money <- buy_ice_cream.
 */ 

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "bdi/belief_base.h"
#include "bdi/event_base.h"
#include "bdi/plan_base.h"
#include "bdi/intention_base.h"
#include "../../data/functions.h"

class AgentSettings
{
private:
  Body * body_0;
  Context * context_0;
  Body * body_1;
  Context * context_1;
  Body * body_2;
  Context * context_2;
  BeliefBase * belief_base;
  EventBase * event_base;
  PlanBase * plan_base;
  IntentionBase * intention_base;

public:
  AgentSettings()
  {
    belief_base = new BeliefBase(3);
    event_base = new EventBase(6);
    plan_base = new PlanBase(3);
    intention_base = new IntentionBase(10, 4);

    //--------------------------------------------------------------------------

    Belief belief_happy(0, nullptr, false);
    belief_base->add_belief(belief_happy);

    //--------------------------------------------------------------------------

    Belief belief_money(1, update_money, false);
    belief_base->add_belief(belief_money);

    //--------------------------------------------------------------------------

    Belief belief_sunny(2, nullptr, false);
    belief_base->add_belief(belief_sunny);

    //--------------------------------------------------------------------------

    Event event_3(EventOperator::GOAL_ADDITION, 3);
    event_base->add_event(event_3);

    //--------------------------------------------------------------------------

    Proposition prop_0(3);
    context_0 = new Context(0);
    body_0 = new Body(1);

    Proposition prop_0_body_0(2);
    BodyInstruction inst_0_0(BodyType::BELIEF, prop_0_body_0, EventOperator::BELIEF_ADDITION);
    body_0->add_instruction(inst_0_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, prop_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Proposition prop_1(2);
    context_1 = new Context(0);
    body_1 = new Body(1);

    Proposition prop_1_body_0(0);
    BodyInstruction inst_0_1(BodyType::BELIEF, prop_1_body_0, EventOperator::BELIEF_ADDITION);
    body_1->add_instruction(inst_0_1);

    Plan plan_1(EventOperator::BELIEF_ADDITION, prop_1, context_1, body_1);
    plan_base->add_plan(plan_1);

    //--------------------------------------------------------------------------

    Proposition prop_2(0);
    context_2 = new Context(2);
    body_2 = new Body(1);

    Proposition prop_2_sunny(2);
    ContextCondition cond_2_0(prop_2_sunny);
    context_2->add_context(cond_2_0);

    Proposition prop_2_money(1);
    ContextCondition cond_2_1(prop_2_money);
    context_2->add_context(cond_2_1);

    Proposition prop_2_body_0(4);
    BodyInstruction inst_0_2(BodyType::ACTION, prop_2_body_0, action_buy_ice_cream);
    body_2->add_instruction(inst_0_2);

    Plan plan_2(EventOperator::BELIEF_ADDITION, prop_2, context_2, body_2);
    plan_base->add_plan(plan_2);
  }

  ~AgentSettings()
  {
    delete body_0;
    delete context_0;
    delete body_1;
    delete context_1;
    delete body_2;
    delete context_2;
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