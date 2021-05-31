/*
 * AgentSpeak code:
 *
 * !start.
 * 
 * +!start <- +happy;
 *            !!hello.
 * 
 * +!hello : happy <- say_hello.
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
  BeliefBase * belief_base;
  EventBase * event_base;
  PlanBase * plan_base;
  IntentionBase * intention_base;

public:
  AgentSettings()
  {
    belief_base = new BeliefBase(1);
    event_base = new EventBase(6);
    plan_base = new PlanBase(2);
    intention_base = new IntentionBase(10, 4);

    //--------------------------------------------------------------------------

    Belief belief_happy(0, nullptr, false);
    belief_base->add_belief(belief_happy);

    //--------------------------------------------------------------------------

    Event event_1(EventOperator::GOAL_ADDITION, 1);
    event_base->add_event(event_1);

    //--------------------------------------------------------------------------

    Proposition prop_0(1);
    context_0 = new Context(0);
    body_0 = new Body(2);

    Proposition prop_0_body_0(0);
    BodyInstruction inst_0_0(BodyType::BELIEF, prop_0_body_0, EventOperator::BELIEF_ADDITION);
    body_0->add_instruction(inst_0_0);

    Proposition prop_0_body_1(2);
    BodyInstruction inst_1_0(BodyType::GOAL, prop_0_body_1, EventOperator::GOAL_ACHIEVE);
    body_0->add_instruction(inst_1_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, prop_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Proposition prop_1(2);
    context_1 = new Context(1);
    body_1 = new Body(1);

    Proposition prop_1_happy(0);
    ContextCondition cond_1_0(prop_1_happy);
    context_1->add_context(cond_1_0);

    Proposition prop_1_body_0(3);
    BodyInstruction inst_0_1(BodyType::ACTION, prop_1_body_0, action_say_hello);
    body_1->add_instruction(inst_0_1);

    Plan plan_1(EventOperator::GOAL_ADDITION, prop_1, context_1, body_1);
    plan_base->add_plan(plan_1);
  }

  ~AgentSettings()
  {
    delete body_0;
    delete context_0;
    delete body_1;
    delete context_1;
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