package translator;

import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.FileReader;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.TreeMap;

public class HeaderCreator
{
  private TreeMap<String, Boolean> beliefs;
  private ArrayList<String> events;
  private ArrayList<PlanSkeleton> plans;
  private int event_base_size;
  private int intention_base_size;
  private int intention_stack_size;
  private final int STM_MAX_SIZE = 256;
  private HashMap <String, Integer> prop_map;
  private ArrayList<String> belief_functions;
  private ArrayList<String> action_functions;
  private String output_file;
  private String function_file;
  private String agent_file;

  public HeaderCreator (
                        TreeMap<String, Boolean> beliefs,
                        ArrayList<String> events,
                        ArrayList<PlanSkeleton> plans,
                        int event_base_size,
                        int intention_base_size,
                        int intention_stack_size,
                        String function_file,
                        String output_file,
                        String agent_file
                        )
  {
    this.beliefs = beliefs;
    this.events = events;
    this.plans = plans;
    this.event_base_size = event_base_size;
    this.intention_base_size = intention_base_size;
    this.intention_stack_size = intention_stack_size;
    this.prop_map = new HashMap <String, Integer>();
    this.belief_functions = new ArrayList<String>();
    this.action_functions = new ArrayList<String>();
    this.output_file = output_file;
    this.function_file = function_file;
    this.agent_file = agent_file;
  }

  private void load_functions()
  {
    try
    {
      // Load functions file and parse action and belief function names
      String funcs = new String(Files.readAllBytes(Paths.get(function_file)));

      funcs = funcs.replace(" ", "");
      funcs = funcs.replace("\n", "");

      for (String belief : beliefs.keySet())
      {
        if (funcs.indexOf("boolupdate_"+ belief + "(boolvar)") != -1) {
          belief_functions.add(belief);
        }
      }

      for (PlanSkeleton plan : plans)
      {
        for (BodyInstruction body : plan.getBodyInstruction())
        {
          if (body.getType() == BodyInstruction.BodyType.ACTION)
          {
            if (funcs.indexOf("boolaction_" + body.getProposition() + "()") != -1) {
              action_functions.add("action_" + body.getProposition());
            }
            else
            {
              System.out.println("Missing function for action");
              System.exit(-2);
            }
          }
        }
      }
    }
    catch (Exception e)
    {
      e.printStackTrace();
    }
  }

  private void define_propositions()
  {    
    for (String belief : beliefs.keySet())
    {
      prop_map.put(belief, prop_map.size());
    }

    for (String event : events)
    {
      if (!prop_map.containsKey(event))
      {
        prop_map.put(event, prop_map.size());
      }
    }

    for (PlanSkeleton plan : plans)
    {
      if (!prop_map.containsKey(plan.getProposition()))
      {
        prop_map.put(plan.getProposition(), prop_map.size());
      }

      for (String context : plan.getContext())
      {
        if (!prop_map.containsKey(context))
        {
          prop_map.put(context, prop_map.size());
        }
      }

      for (BodyInstruction body_instruction : plan.getBodyInstruction())
      {
        if(!prop_map.containsKey(body_instruction.getProposition()))
        {
          prop_map.put(body_instruction.getProposition(), prop_map.size());
        }
      }
    }

    if (prop_map.size() > this.STM_MAX_SIZE)
    {
      System.out.println("There are more than 256 propositions in the program.");
      System.exit(-1);
    }
    return;
  }

  public void write_header()
  {
    try
    {
      this.load_functions();
      this.define_propositions();

      BufferedWriter out = new BufferedWriter(new FileWriter(output_file));

      String text;

      try (BufferedReader br = new BufferedReader(new FileReader(agent_file))) {
        text = "/*\n * AgentSpeak code:\n *\n";
        out.append(text);
        String line;
        while ((line = br.readLine()) != null) {
          text = " * " + line + "\n";
          out.append(text);
        }
        text = " */ \n\n";
        out.append(text);
      }

      // Include headers and start class declaration
      text = "#ifndef CONFIGURATION_H_\n"                                     +
             "#define CONFIGURATION_H_\n\n"                                   +
             "#include \"bdi/belief_base.h\"\n"                               +
             "#include \"bdi/event_base.h\"\n"                                +
             "#include \"bdi/plan_base.h\"\n"                                 +
             "#include \"bdi/intention_base.h\"\n"                            +
             "#include \"../../" + function_file + "\""                       +
             "\n\n"                                                           +
             "class AgentSettings\n"                                          +
             "{\n"                                                            +
             "private:\n";
      out.append(text);
    
      for (int i = 0; i < plans.size(); i++)
      {
        text = "  Body body_" + i + ";\n" + "  Context context_" + i + ";\n";
        out.append(text);
      }

      text = "  BeliefBase belief_base;\n"                                    +
             "  EventBase event_base;\n"                                      +
             "  PlanBase plan_base;\n"                                        +
             "  IntentionBase intention_base;\n";
      out.append(text);

      text = "\npublic:\n"                                                    +
             "  AgentSettings()\n  {\n"                                       +
             "    belief_base = BeliefBase(" + beliefs.size() + ");\n"        +
             "    event_base = EventBase(" + event_base_size + ");\n"         +
             "    plan_base = PlanBase(" + plans.size() + ");\n"              +
             "    intention_base = IntentionBase("                            +
             intention_base_size + ", " + intention_stack_size + ");\n";
      out.append(text);

      // Creation of beliefs
      for (String belief : beliefs.keySet())
      {
        String function_name = "";

        if (belief_functions.contains(belief))
        {
          function_name = "update_" + belief;
        }
        else
        {
          function_name = "nullptr";
        }

        text = "\n    //-----------------------------------------------------"+
               "---------------------\n\n";
        out.append(text);

        text = "    Belief belief_" + belief + "(" + prop_map.get(belief)     + 
               ", " +  function_name + ", " + beliefs.get(belief) + ");\n"    +
               "    belief_base.add_belief(belief_" + belief + ");\n";
        out.append(text);
      }

      // Creation of events
      for (String event : events)
      {
        text = "\n    //-----------------------------------------------------"+
               "---------------------\n\n";
        out.append(text);

        text = "    Event event_" + prop_map.get(event)                       +
               "(EventOperator::GOAL_ADDITION, " + prop_map.get(event) +");\n"+
               "    event_base.add_event(event_" + prop_map.get(event) +");\n";
        out.append(text);
      }

      // Creation of plans
      int plan_count = 0;
      int context_count = 0;
      for (PlanSkeleton plan : plans)
      {
        text = "\n    //-----------------------------------------------------"+
               "---------------------\n\n";
        out.append(text);

        text = "    Proposition prop_" + plan_count + "("                     +
               prop_map.get(plan.getProposition()) + ");\n    context_"       +
               context_count + " = Context(" + plan.getContext().size()       +
               ");\n    body_" + plan_count + " = Body("                      +
               plan.getBodySize() + ");\n\n";;
        out.append(text);

        for (String context : plan.getContext())
        {
          text = "    Proposition prop_" + plan_count + "_" + context + "("   +
                 prop_map.get(context) + ");\n    ContextCondition cond_"     +
                 plan_count + "_" + plan.getContext().indexOf(context)        +
                 "(prop_" + plan_count + "_" + context + ");\n    "           +
                 "context_" + context_count + ".add_context(cond_"            +
                 context_count + "_" + plan.getContext().indexOf(context)     +
                 ");\n\n";
          out.append(text);
        }

        for (BodyInstruction body : plan.getBodyInstruction())
        {
          String argument;
          if (body.getOperator() == null)
          {
            argument = "action_" + body.getProposition();
          }
          else
          {
            argument = "EventOperator::" + body.getOperator();
          }

          text = "    Proposition prop_" + plan_count + "_body_"              +
                 plan.getBodyInstruction().indexOf(body) + "("                +
                 prop_map.get(body.getProposition()) + ");\n"                 +
                 "    BodyInstruction inst_"                                  + 
                 plan.getBodyInstruction().indexOf(body) + "_"                +
                 plan_count + "(BodyType::" + body.getType() + ", " + "prop_" +
                 plan_count+ "_body_"+ plan.getBodyInstruction().indexOf(body)+
                 ", " + argument + ");\n"                                     +
                 "    body_" + plan_count         +
                 ".add_instruction(inst_"                                     + 
                 plan.getBodyInstruction().indexOf(body) + "_" + plan_count   +
                 ");\n\n";
          out.append(text);
        }

        text = "    Plan plan_" + plan_count + "(EventOperator::"              +
               plan.getOperator() + ", prop_" + plan_count + ", &context_"     +
               context_count + ", &body_" + plan_count + ");\n"                +
               "    plan_base.add_plan(plan_" + plan_count + ");\n";
        out.append(text);

        plan_count++;
        context_count++;
      }

      text = "  }\n\n";  
      out.append(text);
             
      text = "  BeliefBase * get_belief_base()\n  {\n"                        +
             "    return &belief_base;\n"                                     +
             "  }\n\n"                                                        +
             "  EventBase * get_event_base()\n  {\n"                          +
             "    return &event_base;\n"                                      +
             "  }\n\n"                                                        +
             "  PlanBase * get_plan_base()\n  {\n "                           +
             "   return &plan_base;\n"                                        +
             "  }\n\n"                                                        +
             "  IntentionBase * get_intention_base()\n  {\n"                  +
             "    return &intention_base;\n"                                  +
             "  }\n"                                                          +
             "};\n\n#endif /*"                                                +
             "CONFIGURATION_H_ */";
      out.append(text);

      out.close();
    }
    catch (Exception e)
    {
      e.printStackTrace();
    }
    return;
  }
}