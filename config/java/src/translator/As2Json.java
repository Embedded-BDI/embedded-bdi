package translator;

import java.util.ArrayList;
import java.util.HashMap;
import java.io.FileInputStream;

import jason.asSemantics.Agent;
import jason.asSyntax.Literal;
import jason.asSyntax.Plan;
import jason.asSyntax.PlanBody;
import jason.asSyntax.Term;
import jason.asSyntax.parser.as2j;
import jason.util.Config;

public class As2Json
{
  public static void main(String[] args)
  {
    new As2Json().run("config/java/agentspeak.asl");     // for VS Code 
    // new As2Json().run("agentspeak.asl");
  }

  void run(String file)
  {
    try
    {
      Config.get().setProperty(Config.START_WEB_MI,"false");

      as2j parser = new as2j(new FileInputStream(file));
      Agent ag = new Agent();
      ag.initAg();
      parser.agent(ag);

      HashMap<String, Boolean> beliefs = this.getBeliefs(ag);
      HashMap<String, EventOperatorType> events = this.getEvents(ag);
      ArrayList<PlanSkeleton> plans = this.getPlans(ag);

      HeaderCreator write_to_file = new HeaderCreator(beliefs, events, plans, 10, 10, 4);
      write_to_file.write_header();
    }
    catch (Exception e)
    {
      e.printStackTrace();
    }
  }

  // Capture all beliefs from code file and create corresponding HashMap
  private HashMap<String, Boolean> getBeliefs(Agent ag)
  {
    HashMap<String, Boolean> beliefs = new HashMap<String, Boolean>();
    
    // Capture all initial beliefs
    for (Literal lit : ag.getInitialBels())
    {
      beliefs.put(lit.toString(), true);
    }

    for (Plan plan : ag.getPL())
    {
      // Capture all plans that have belief changes as triggers
      if (
          plan.getTrigger().getOperator().toString() == "+" ||
          plan.getTrigger().getOperator().toString() == "-"
          )
      {
        if (plan.getTrigger().getType().toString() == "")
        {
          if (!beliefs.containsKey(plan.getTrigger().getLiteral().toString()))
          {
            beliefs.put(plan.getTrigger().getLiteral().toString(), false);
          }
        }
      }

      // Capture beliefs from contexts
      try
      {
        String s_context = plan.getContext().toString().replaceAll("[()&]", "");
        String[] context_list = s_context.split("\\s+");
        for (int i = 0; i < context_list.length; i++)
        {
          if (!beliefs.containsKey(context_list[i]))
          {
            beliefs.put(context_list[i], false);
          }
        }
      } catch (Exception e) {
        // System.out.println("No Context for Plan: " + p.getTrigger().toString());
      }

      // Capture belief triggers in plan body
      PlanBody plan_body = plan.getBody();
      for (int i = 0; i < plan.getBody().getPlanSize(); i++)
      {
        PlanBody.BodyType body_type = plan_body.getBodyType();

        if (
            body_type == PlanBody.BodyType.addBel ||
            body_type == PlanBody.BodyType.delBel
            )
        {
          Term body_term = plan_body.getBodyTerm();
          if (!beliefs.containsKey(body_term.toString()))
          {
            beliefs.put(body_term.toString(), false);
          }
        }

        plan_body = plan_body.getBodyNext();
      }
    }

    for (String belief: beliefs.keySet())
    {
      System.out.println("\n---\n\nBELIEF:\nName:\n\t" + belief);
      System.out.println("Value:\n\t" + beliefs.get(belief));
    }

    return beliefs;
  }

  // Capture all initial events
  private HashMap<String, EventOperatorType> getEvents(Agent ag)
  {
    HashMap<String, EventOperatorType> events = new HashMap<String, EventOperatorType>();
    
    for (Literal lit : ag.getInitialGoals())
    {
      events.put(lit.toString(), EventOperatorType.GOAL_ADDITION);
    }

    for (String event: events.keySet())
    {
      System.out.println("\n---\n\nEVENT:\nName:\n\t" + event);
      System.out.println("Value:\n\t" + events.get(event));
    }

    return events;
  }

  // Parse all plan to individual objects that can be easily parsed to C++ code
  private ArrayList<PlanSkeleton> getPlans(Agent ag)
  {
    ArrayList<PlanSkeleton> plans = new ArrayList<PlanSkeleton>();

    for (Plan plan : ag.getPL())
    {
      PlanSkeleton plan_s = new PlanSkeleton();

      // Parse plan operator
      String operator = plan.getTrigger().getOperator().toString();
      operator += plan.getTrigger().getType().toString();
      
      switch (operator)
      {
        case "+":
          plan_s.setOperator(EventOperatorType.BELIEF_ADDITION);
          break;
        case "-":
          plan_s.setOperator(EventOperatorType.BELIEF_DELETION);
          break;
        case "+!":
          plan_s.setOperator(EventOperatorType.GOAL_ADDITION);
          break;
        case "-!":
          plan_s.setOperator(EventOperatorType.GOAL_DELETION);
          break;
        case "+?":
          plan_s.setOperator(EventOperatorType.TEST_GOAL_ADDITION);
          break;
        case "-?":
          plan_s.setOperator(EventOperatorType.TEST_GOAL_DELETION);
          break;
      }

      // Parse plan statement
      plan_s.setStatement(plan.getTrigger().getLiteral().toString());

      // Parse plan context
      try
      {
        String s_context = plan.getContext().toString().replaceAll("[()&]", "");
        String[] context_list = s_context.split("\\s+");
        for (int i = 0; i < context_list.length; i++) {
          plan_s.addContext(context_list[i]);
        }
      }
      catch (Exception e)
      {
        // System.out.println("No Context for Plan: " + p.getTrigger().toString());
      }

      // Parse plan body
      PlanBody plan_body = plan.getBody();
      for (int i = 0; i < plan.getBody().getPlanSize(); i++)
      {
        PlanBody.BodyType body_type = plan_body.getBodyType();
        Term body_term = plan_body.getBodyTerm();

        BodyInstruction instruction = new BodyInstruction();
        switch (body_type)
        {
          case addBel:
            instruction.setType(BodyInstruction.BodyType.BELIEF);
            instruction.setOperator(EventOperatorType.BELIEF_ADDITION);
            break;
          case delBel:
            instruction.setType(BodyInstruction.BodyType.BELIEF);
            instruction.setOperator(EventOperatorType.BELIEF_DELETION);
            break;
          case achieve:
            instruction.setType(BodyInstruction.BodyType.GOAL);
            instruction.setOperator(EventOperatorType.GOAL_ADDITION);
            break;
          case achieveNF:
            instruction.setType(BodyInstruction.BodyType.GOAL);
            instruction.setOperator(EventOperatorType.GOAL_DELETION);
            break;
          case action:
            instruction.setType(BodyInstruction.BodyType.ACTION);
            break;
          default:
            break;
        }
        instruction.setStatement(body_term.toString());
        plan_s.addBodyInstruction(instruction);

        plan_body = plan_body.getBodyNext();
      }

      plans.add(plan_s);
    }

    for (PlanSkeleton plan : plans)
    {
      System.out.println("\n---\n\nPLAN:");
      System.out.println("Operator:\n\t" + plan.getOperator());
      System.out.println("Statement:\n\t" + plan.getStatement());
      System.out.println("Context:");
      for (String ctx : plan.getContext())
      {
        System.out.println("\t" + ctx);
      }
      System.out.println("Body:");
      for (BodyInstruction body : plan.getBodyInstruction())
      {
        System.out.println("\t[" + body.getType() + ", " + body.getStatement() +
                           ", " + body.getOperator() + "]");
      }
    }

    return plans;
  }
}