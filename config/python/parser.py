import json
import os.path
import re

CHAR_SIZE = 256                     # max size of char
stm_dict = {}                       # dictionary to keep track of statement char
update_beliefs_list = []            # list of update belief functions
actions_list = []                   # list of action functions
functions_file = 'functions.h'
output_file = 'configuration.h'
ctx_cond_counter = 0
ctx_counter = 0
stm_counter = 0
body_counter = 0
instruction_counter = 0

#
# Clear output file
#
with (open(output_file, 'w')) as file:
  file.write("")

with (open(output_file, 'r+')) as file:
  file.truncate(0)

#
# Process belief update and action functions
#
with open(functions_file, 'r') as file:
  data = file.read().replace(' ', '')

find_update_functions = re.findall("boolupdate.+?\(boolvar\)", data)
if len(find_update_functions) != len(set(find_update_functions)):
  print("Duplicate functions to update belief!")
  exit(1)

find_action_functions = re.findall("boolaction.+?\(boolvar\)", data)
if len(find_action_functions) != len(set(find_action_functions)):
  print("Duplicate functions for action!")
  exit(1)

for line in find_update_functions: 
  function_names = re.search('bool(.*)\(boolvar\)', line)
  update_beliefs_list.append(function_names.group(1))

for line in find_action_functions:
  function_names = re.search('bool(.*)\(boolvar\)', line)
  actions_list.append(function_names.group(1))

#
# Loads JSON file and processes agent settings
#

# Write start of file
text =  "#include \"../../lib/bdi/belief_base.h\"\n"                        + \
        "#include \"../../lib/bdi/event_base.h\"\n"                         + \
        "#include \"../../lib/bdi/plan_base.h\"\n"                          + \
        "#include \"../../lib/bdi/intention_base.h\"\n"                     + \
        "#include \"" + functions_file + "\"\n\n"                           + \
        "class AgentSettings\n{\nprivate:\n"                                + \
        "  BeliefBase * belief_base;\n  EventBase * event_base;\n"          + \
        "  PlanBase * plan_base;\n\n"                                       + \
        "public:\n  AgentSettings()\n  {\n"

with open(output_file, 'a+') as file:
    file.write(text)

# Belief
with open('agent.json') as json_file:
    data = json.load(json_file)

text =  "    belief_base = new BeliefBase(" + str(len(data['belief']))      + \
        ");\n    event_base = new EventBase(" + str(len(data['event']))     + \
        ");\n    plan_base = new PlanBase(" + str(len(data['plan'])) + ");\n\n"
with open(output_file, 'a+') as file:
    file.write(text)


for belief in data['belief']:
  if len(stm_dict) >= CHAR_SIZE:
    print("Number of statements exceeds max: " + str(CHAR_SIZE))
    exit(1)

  if belief['statement'] not in stm_dict:
    stm_dict[belief['statement']] = len(stm_dict)

  function_name = "update_" + belief['statement']
  if update_beliefs_list.count(function_name):
    name = function_name
  else:
    name = "nullptr"
  
  text = ("    Belief belief_" + str(stm_dict[belief['statement']]) + "('"  + \
          str(stm_dict[belief['statement']]) + "', " + name + " , "         + \
          belief['state'] + ");\n    belief_base->add_belief(belief_"       + \
          str(stm_dict[belief['statement']]) + ");\n\n")
  text = text.replace("\'", "")
  # print(text)

  with open(output_file, 'a+') as file:
    file.write(text)

# Event
for event in data['event']:
  if len(stm_dict) >= CHAR_SIZE:
    print("Number of statements exceeds max: " + str(CHAR_SIZE))
    exit(1)

  if event['statement'] not in stm_dict:
    stm_dict[event['statement']] = len(stm_dict)

  text = "    event_base->add_event(EventOperator::"                        + \
         event['event_operator'] + ", " + str(stm_dict[event['statement']]) + \
         ");\n"
  text = text.replace("\'", "")

  with open(output_file, 'a+') as file:
    file.write(text)

with open(output_file, 'a+') as file:
  file.write("\n")

# Plan
for idx, plan in enumerate(data['plan']):
  if len(stm_dict) >= CHAR_SIZE:
    print("Number of statements exceeds max: " + str(CHAR_SIZE))
    exit(1)

  if plan['statement'] not in stm_dict:
    stm_dict[plan['statement']] = len(stm_dict)

  text = "    Statement stm_" + str(stm_counter) + "("                      + \
         str(stm_dict[plan['statement']]) + ");\n\n"
  plan_stm = str(stm_counter)
  text = text.replace("\'", "")
  with open(output_file, 'a+') as file:
    file.write(text)
  stm_counter += 1

  for context in plan['context']:
    text = "    Context * context_" + str(ctx_counter) + " = new Context("  + \
           str(len(context['context_condition'])) + ");\n\n"
    text = text.replace("\'", "")
    with open(output_file, 'a+') as file:
      file.write(text)

    for ctx_cond in context['context_condition']:
      if ctx_cond['statement'] not in stm_dict:
        print("Belief from context does not exist in Agent's Belief Base")
        exit(1)
      text = "    Statement stm_" + str(stm_counter)                        + \
             "(" + str(stm_dict[ctx_cond['statement']]) + ");\n"
      text = text.replace("\'", "")
      stm_counter += 1
      with open(output_file, 'a+') as file:
        file.write(text)
      text = "    ContextCondition cond_" + str(ctx_cond_counter) + "("     + \
             "stm_" + str(stm_dict[ctx_cond['statement']]) + ", "           + \
             ctx_cond['is_true'] + ");\n"
      text = text.replace("\'", "")
      with open(output_file, 'a+') as file:
        file.write(text)
      
      text = "    context_" + str(ctx_counter) + "->add_context(cond_"      + \
             str(ctx_cond_counter) + ");\n\n" 
      text = text.replace("\'", "")
      with open(output_file, 'a+') as file:
        file.write(text)
      ctx_cond_counter += 1

  
  for body in plan['body']:
    text = "    Body * body_" + str(body_counter) + " = new Body("          + \
           str(len(body['instruction'])) + ");\n\n"
    text = text.replace("\'", "")
    with open(output_file, 'a+') as file:
      file.write(text)

    for instruction in body['instruction']: 
      if instruction['body_type'] == 'ACTION':
          function_name = "action_" + instruction['statement']
          if actions_list.count(function_name) < 1:
            print("Missing function for action: " + instruction['statement'])
            exit(1)

          if instruction['statement'] not in stm_dict:
            stm_dict[instruction['statement']] = len(stm_dict)

          text = "    Statement stm_" + str(stm_counter) + "("              + \
                str(stm_dict[instruction['statement']]) + ");\n"
          text = text.replace("\'", "")
          with open(output_file, 'a+') as file:
            file.write(text)
            
          text = "    BodyInstruction inst_" + str(instruction_counter)     + \
                 "(BodyType::" + instruction['body_type'] + ", "            + \
                 "stm_" + str(stm_counter) + ", "    + \
                 function_name + ");\n"
          text = text.replace("\'", "")
          with open(output_file, 'a+') as file:
            file.write(text)
          stm_counter += 1
      else:
        if instruction['statement'] not in stm_dict:
          stm_dict[instruction['statement']] = len(stm_dict)

        text = "    Statement stm_" + str(stm_counter) + "("                + \
              str(stm_dict[instruction['statement']]) + ");\n"
        text = text.replace("\'", "")
        with open(output_file, 'a+') as file:
          file.write(text)
          
        text = "    BodyInstruction inst_" + str(instruction_counter)       + \
                "(BodyType::" + instruction['body_type'] + ", "             + \
                "stm_" + str(stm_counter) + ", "    + \
                "EventOperator::" + instruction['operator'] + ");\n"
        text = text.replace("\'", "")
        with open(output_file, 'a+') as file:
          file.write(text)
        stm_counter += 1
      
      text = "    body_" + str(body_counter) + "->add_instruction(inst_"    + \
             str(instruction_counter) + ");\n\n"
      text = text.replace("\'", "")
      with open(output_file, 'a+') as file:
        file.write(text)
  body_counter += 1

  text = "    Plan plan_" + str(idx) + "(EventOperator::"                   + \
         plan['event_operator'] + ", " + "stm_" + plan_stm + ", "           + \
         "context_" + str(ctx_counter) + ", " + "body_"                     + \
         str(body_counter-1) + ");\n"
  with open(output_file, 'a+') as file:
    file.write(text)
  
  text = "    plan_base->add_plan(plan_" + str(idx) + ");\n"
  with open(output_file, 'a+') as file:
    file.write(text)

with open(output_file, 'a+') as file:
    file.write("  }\n\n")


text =  "  ~AgentSettings()\n  {\n    delete belief_base;\n"                + \
        "    delete event_base;\n    delete plan_base;\n  }\n\n"       
with open(output_file, 'a+') as file:
    file.write(text)


text = "  BeliefBase * get_belief_base()\n  {\n    return belief_base;\n  }\n\n"
with open(output_file, 'a+') as file:
    file.write(text)

text = "  EventBase * get_event_base()\n  {\n    return event_base;\n  }\n\n"
with open(output_file, 'a+') as file:
    file.write(text)

text = "  PlanBase * get_plan_base()\n  {\n    return plan_base;\n  }\n"
with open(output_file, 'a+') as file:
    file.write(text)

# Add characters at the end of the class
with open(output_file, 'a+') as file:
    file.write("};")