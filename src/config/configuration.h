/*
 * AgentSpeak code:
 *
 * !start.
 * 
 * +!start <- join_lottery;
 *            grab_number;
 *            !!wait_for_number.
 * 
 * +!wait_for_number : my_number <- cheer_and_leave.
 * +!wait_for_number <- !!wait_for_number.
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
    belief_base = new BeliefBase(1);
    event_base = new EventBase(6);
    plan_base = new PlanBase(3);
    intention_base = new IntentionBase(10, 4);

    //--------------------------------------------------------------------------

    Belief belief_my_number(0, update_my_number, false);
    belief_base->add_belief(belief_my_number);

    //--------------------------------------------------------------------------

    Event event_1(EventOperator::GOAL_ADDITION, 1);
    event_base->add_event(event_1);

    //--------------------------------------------------------------------------

    Statement stm_0(1);
    context_0 = new Context(0);
    body_0 = new Body(3);

    Statement stm_0_body_0(2);
    BodyInstruction inst_0_0(BodyType::ACTION, stm_0_body_0, action_join_lottery);
    body_0->add_instruction(inst_0_0);

    Statement stm_0_body_1(3);
    BodyInstruction inst_1_0(BodyType::ACTION, stm_0_body_1, action_grab_number);
    body_0->add_instruction(inst_1_0);

    Statement stm_0_body_2(4);
    BodyInstruction inst_2_0(BodyType::GOAL, stm_0_body_2, EventOperator::GOAL_ACHIEVE);
    body_0->add_instruction(inst_2_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, stm_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Statement stm_1(4);
    context_1 = new Context(1);
    body_1 = new Body(1);

    Statement stm_1_my_number(0);
    ContextCondition cond_1_0(stm_1_my_number);
    context_1->add_context(cond_1_0);

    Statement stm_1_body_0(5);
    BodyInstruction inst_0_1(BodyType::ACTION, stm_1_body_0, action_cheer_and_leave);
    body_1->add_instruction(inst_0_1);

    Plan plan_1(EventOperator::GOAL_ADDITION, stm_1, context_1, body_1);
    plan_base->add_plan(plan_1);

    //--------------------------------------------------------------------------

    Statement stm_2(4);
    context_2 = new Context(0);
    body_2 = new Body(1);

    Statement stm_2_body_0(4);
    BodyInstruction inst_0_2(BodyType::GOAL, stm_2_body_0, EventOperator::GOAL_ACHIEVE);
    body_2->add_instruction(inst_0_2);

    Plan plan_2(EventOperator::GOAL_ADDITION, stm_2, context_2, body_2);
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