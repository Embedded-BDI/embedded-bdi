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
    belief_base = new BeliefBase(0);
    event_base = new EventBase(6);
    plan_base = new PlanBase(4);
    intention_base = new IntentionBase(10, 4);

    //--------------------------------------------------------------------------

    event_base->add_event(EventOperator::GOAL_ADDITION, 0);

    //--------------------------------------------------------------------------

    event_base->add_event(EventOperator::GOAL_ADDITION, 1);

    //--------------------------------------------------------------------------

    event_base->add_event(EventOperator::GOAL_ADDITION, 2);

    //--------------------------------------------------------------------------

    event_base->add_event(EventOperator::GOAL_ADDITION, 3);

    //--------------------------------------------------------------------------

    event_base->add_event(EventOperator::GOAL_ADDITION, 4);

    //--------------------------------------------------------------------------

    event_base->add_event(EventOperator::GOAL_ADDITION, 5);

    //--------------------------------------------------------------------------

    Statement stm_0(0);
    Context * context_0 = new Context(0);
    Body * body_0 = new Body(1);

    Statement stm_0_body_0(6);
    BodyInstruction inst_0_0(BodyType::ACTION, stm_0_body_0, action_action_1);
    body_0->add_instruction(inst_0_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, stm_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Statement stm_1(1);
    Context * context_1 = new Context(0);
    Body * body_1 = new Body(1);

    Statement stm_1_body_0(7);
    BodyInstruction inst_0_1(BodyType::ACTION, stm_1_body_0, action_action_2);
    body_1->add_instruction(inst_0_1);

    Plan plan_1(EventOperator::GOAL_ADDITION, stm_1, context_1, body_1);
    plan_base->add_plan(plan_1);

    //--------------------------------------------------------------------------

    Statement stm_2(2);
    Context * context_2 = new Context(0);
    Body * body_2 = new Body(1);

    Statement stm_2_body_0(8);
    BodyInstruction inst_0_2(BodyType::ACTION, stm_2_body_0, action_action_3);
    body_2->add_instruction(inst_0_2);

    Plan plan_2(EventOperator::GOAL_ADDITION, stm_2, context_2, body_2);
    plan_base->add_plan(plan_2);

    //--------------------------------------------------------------------------

    Statement stm_3(3);
    Context * context_3 = new Context(0);
    Body * body_3 = new Body(1);

    Statement stm_3_body_0(9);
    BodyInstruction inst_0_3(BodyType::ACTION, stm_3_body_0, action_action_4);
    body_3->add_instruction(inst_0_3);

    Plan plan_3(EventOperator::GOAL_ADDITION, stm_3, context_3, body_3);
    plan_base->add_plan(plan_3);
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