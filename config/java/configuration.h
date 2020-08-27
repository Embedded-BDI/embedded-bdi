#include "../../lib/bdi/belief_base.h"
#include "../../lib/bdi/event_base.h"
#include "../../lib/bdi/plan_base.h"
#include "../../lib/bdi/intention_base.h"
#include "functions.h"

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
    belief_base = new BeliefBase(7);
    event_base = new EventBase(10);
    plan_base = new PlanBase(2);
    intention_base = new IntentionBase(10, 4);

    //--------------------------------------------------------------------------

    Belief belief_context_1(0, nullptr, false);
    belief_base->add_belief(belief_context_1);

    //--------------------------------------------------------------------------

    Belief belief_context_2(1, nullptr, false);
    belief_base->add_belief(belief_context_2);

    //--------------------------------------------------------------------------

    Belief belief_belief_plan(2, nullptr, false);
    belief_base->add_belief(belief_belief_plan);

    //--------------------------------------------------------------------------

    Belief belief_add_belief_1(3, nullptr, false);
    belief_base->add_belief(belief_add_belief_1);

    //--------------------------------------------------------------------------

    Belief belief_belief_1(4, update_belief_1, true);
    belief_base->add_belief(belief_belief_1);

    //--------------------------------------------------------------------------

    Belief belief_delete_belief_1(5, nullptr, false);
    belief_base->add_belief(belief_delete_belief_1);

    //--------------------------------------------------------------------------

    Belief belief_belief_2(6, nullptr, true);
    belief_base->add_belief(belief_belief_2);

    //--------------------------------------------------------------------------

    event_base->add_event(EventOperator::GOAL_ADDITION, 7);

    //--------------------------------------------------------------------------

    event_base->add_event(EventOperator::GOAL_ADDITION, 8);

    //--------------------------------------------------------------------------

    Statement stm_0(2);
    Context * context_0 = new Context(0);
    Body * body_0 = new Body(4);

    Statement stm_0_body_0(9);
    BodyInstruction inst_0_0(BodyType::ACTION, stm_0_body_0, action_action_1);
    body_0->add_instruction(inst_0_0);

    Statement stm_0_body_1(3);
    BodyInstruction inst_1_0(BodyType::BELIEF, stm_0_body_1, EventOperator::BELIEF_ADDITION);
    body_0->add_instruction(inst_1_0);

    Statement stm_0_body_2(5);
    BodyInstruction inst_2_0(BodyType::BELIEF, stm_0_body_2, EventOperator::BELIEF_DELETION);
    body_0->add_instruction(inst_2_0);

    Statement stm_0_body_3(10);
    BodyInstruction inst_3_0(BodyType::GOAL, stm_0_body_3, EventOperator::GOAL_ADDITION);
    body_0->add_instruction(inst_3_0);

    Plan plan_0(EventOperator::BELIEF_ADDITION, stm_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Statement stm_1(11);
    Context * context_1 = new Context(2);
    Body * body_1 = new Body(1);

    Statement stm_1_context_1(0);
    ContextCondition cond_1_0(stm_1_context_1, true);
    context_1->add_context(cond_1_0);

    Statement stm_1_context_2(1);
    ContextCondition cond_1_1(stm_1_context_2, true);
    context_1->add_context(cond_1_1);

    Statement stm_1_body_0(12);
    BodyInstruction inst_0_1(BodyType::ACTION, stm_1_body_0, action_action_2);
    body_1->add_instruction(inst_0_1);

    Plan plan_1(EventOperator::GOAL_ADDITION, stm_1, context_1, body_1);
    plan_base->add_plan(plan_1);
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