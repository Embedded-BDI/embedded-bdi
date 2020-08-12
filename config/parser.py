import json
import os.path
import re

CHAR_SIZE = 1

#
# Process belief update and action functions
# 
with open('functions.h', 'r') as file:
  data = file.read().replace(' ', '')

find_update_functions = re.findall("boolupdate.+?\(boolvar\)", data)
if len(find_update_functions) != len(set(find_update_functions)):
  print("Duplicate functions to update belief!")
  exit(1)

find_action_functions = re.findall("boolaction.+?\(boolvar\)", data)
if len(find_action_functions) != len(set(find_action_functions)):
  print("Duplicate functions for action!")
  exit(1)

update_beliefs_list = []
for line in find_update_functions: 
  function_names = re.search('bool(.*)\(boolvar\)', line)
  update_beliefs_list.append(function_names.group(1))
  # print(update_beliefs_list)

actions_list = []
for line in find_action_functions:
  function_names = re.search('bool(.*)\(boolvar\)', line)
  actions_list.append(function_names.group(1))
  # print(actions_list)

#
# Loads JSON file and processes agent settings
#

# Belief
stm_dict = {}

with open('agent.json') as json_file:
    data = json.load(json_file)
    # print(data)

for belief in data['belief']:
  if len(stm_dict) < CHAR_SIZE and belief['statement'] not in stm_dict:
    stm_dict[belief['statement']] = len(stm_dict)
  else:
    print("Number of beliefs exceeds max: " + str(CHAR_SIZE))
    exit(1)

  function_name = "update_" + belief['statement']
  if update_beliefs_list.count(function_name):
    text = ("  Belief belief('" +  str(stm_dict[belief['statement']]) + \
            "', " + function_name + " , " + belief['state'] + ");\n")
    text = text.replace("\'", "")
    # print(text)
  else:
    text = ("  Belief belief('" +  str(stm_dict[belief['statement']]) + \
            "', nullptr , " + belief['state'] + ");\n")
    text = text.replace("\'", "")
    # print(text)

  with open('text.txt', 'a+') as file:
    file.write(text)

# Event

# Plan