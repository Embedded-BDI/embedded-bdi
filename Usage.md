## Usage

In order to generate the agent executable, two files are necessary: `data/functions.h` and `data/agentpeak.asl`. The former contains the functions to update beliefs and act in the environment, and the latter contains the agent code.

### Functions file

Functions to update the belief must contain the prefix `update_` and functions that act in the environment must start with `action_`. In the example below, the function `action_close_door` refers to the action *close_door* and `update_open_door` updates the belief `open_door`.

```
bool action_close_door(bool var)
{
  std::cout << "A" << std::endl;
  return true;
}

bool update_open_door(bool var)
{
  return true;
}
```

### AgentSpeak file

Currently, only propositional logic and simple plan context is supported by the tool. Example of agent code supported is displayed below:

```
!goal1.

+!goal1 <- action_1, !goal2.

+!goal2 <- +belief1.

+belief1 <- action_2.

+!goal3 : belief_3 AND belief_4 <- !goal4.

-!goal3 <- action_3.
```

## Build agent

To create the agent executable, run `make all` to perform the AgentSpeak code translation and build the agent executable. The executable will be available at `build/agent.out`.

## Advanced

Since the agent aims to be run in embedded platforms, resource usage must be limited. As a result, the size of the Event Base, Intention Base and stack of Plans per Intention must be defined in the `bases_size.mk` file.

```
EVENT_BASE_SIZE=6
INTENTION_BASE_SIZE=10
INTETION_STACK_SIZE=4
```