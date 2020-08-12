import json
import os.path
import re

CHAR_SIZE = 256             # max size of char
stm_dict = {}               # dictionary to keep track of statement char
update_beliefs_list = []    # list of update belief functions
actions_list = []           # list of action functions
functions_file = 'functions.h'
output_file = 'configuration.h'

#
# Clear output file
#
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
  # print(update_beliefs_list)

for line in find_action_functions:
  function_names = re.search('bool(.*)\(boolvar\)', line)
  actions_list.append(function_names.group(1))
  # print(actions_list)


#
# Loads JSON file and processes agent settings
#

# Write start of file
text = "#include \"../lib/bdi/belief_base.h\"\n"                  + \
       "#include \"../lib/bdi/event_base.h\"\n"                   + \
       "#include \"../lib/bdi/intention.h\"\n"                    + \
       "#include \"" + functions_file + "\"\n\n"                  + \
       "class AgentSettings\n{\npublic:\n  AgentSettings() {}\n"  + \
       "  ~AgentSettings() {}\n\n"                                + \
       "  BeliefBase get_belief_base()\n  {\n"

with open(output_file, 'a+') as file:
    file.write(text)

# Belief
with open('agent.json') as json_file:
    data = json.load(json_file)
    # print(data)

text = "    BeliefBase belief_base(" + str(len(data['belief'])) + ");\n\n"
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
          belief['state'] + ");\n    belief_base.add_belief(belief_"        + \
          str(stm_dict[belief['statement']]) + ");\n\n")
  text = text.replace("\'", "")
  # print(text)

  with open(output_file, 'a+') as file:
    file.write(text)

text = "    return belief_base;\n  }\n\n"
with open(output_file, 'a+') as file:
    file.write(text)


# Event
text= "  EventBase get_event_base()\n  {\n"
with open(output_file, 'a+') as file:
    file.write(text)

text = "    EventBase event_base(" + str(len(data['event'])) + ");\n\n"
with open(output_file, 'a+') as file:
    file.write(text)

for event in data['event']:
  if len(stm_dict) >= CHAR_SIZE:
    print("Number of statements exceeds max: " + str(CHAR_SIZE))
    exit(1)

  if event['statement'] not in stm_dict:
    stm_dict[event['statement']] = len(stm_dict)

  text = "    event_base.add_event(EventOperator::"                         + \
         event['event_operator'] + ", " + str(stm_dict[event['statement']]) + \
         ");\n"
         
  text = text.replace("\'", "")

  with open(output_file, 'a+') as file:
    file.write(text)

text = "\n    return event_base;\n  }\n"
with open(output_file, 'a+') as file:
    file.write(text)

# Plan


# Add characters at the end of the class
with open(output_file, 'a+') as file:
    file.write("};")