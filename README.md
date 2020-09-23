## Description

Master's thesis on programming of embedded agents using propositional logic & BDI architecture.

[GitHub repository](http://github.com/matuzalemmuller/embedded-bdi)


----

## Table of Contents

- [Requirements](#requirements-)
- [Documentation](#documentation)
- [Usage](#usage)
  * [Functions file](#functions-file)
  * [AgentSpeak file](#agentspeak-file)
  * [Build agent](#build-agent)
  * [Advanced](#advanced)
- [For Developers](#for-developers)
- [Unit Tests](#unit-tests)

----

## Requirements
* [OpenJDK](https://openjdk.java.net/) (or [Java SDK](https://www.oracle.com/java/technologies/javase-downloads.html)).
* C++11 compiler. [g++ 4.9 or later](https://gcc.gnu.org/gcc-4.9/changes.html) is recommended but another compiler can also be set in the `Makefile`.
* (Recommended) [Doxygen](https://www.doxygen.nl/index.html) for documentation generation.
* (Recommended) [Graphviz](https://graphviz.org/) for UML/chart support in documentation.

## Documentation

HTML documentation can be generated using [Doxygen](https://www.doxygen.nl/download.html). To generate the documentation, simply run `make docs` at the root folder of the repository or check the [docs](docs/) folder for more details.

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

Currently, only propositional logic and simple plan context are supported by the tool. An example of agent code supported is displayed below:

```
!goal1.

+!goal1 <- action_1, !goal2.

+!goal2 <- +belief1.

+belief1 <- action_2.

+!goal3 : belief_3 && belief_4 <- !goal4.

-!goal3 <- action_3.
```

### Build agent

To create the agent executable, run `make all` to perform the AgentSpeak code translation and build the agent executable. The executable will be available at `build/agent.out`.

### Advanced

Since the agent aims to be run in embedded platforms, resource usage must be limited. As a result, the size of the Event Base, Intention Base, and stack of Plans per Intention must be defined in the `agent.config` file.

```
EVENT_BASE_SIZE=6
INTENTION_BASE_SIZE=10
INTETION_STACK_SIZE=4
```

## For Developers

This project was developed using [Eclipse CDT](https://www.eclipse.org/cdt/) and the launch configurations for both Unit Tests and Agent are available in each project folder. Note that the launch configurations add debug symbols to the binaries to ease debugging and these can be removed in `Project Properties -> C/C++ Build -> Settings -> Tools Settings -> Cross G++ Compiler -> Debugging`. This is important as debug symbols increase the binary size.

The `Makefile` available in the root folder also allows usage of CLI for building and debugging with customization of compiler, debug, and optimization options.

## Unit Tests

[CircleCI](https://circleci.com/) is used for continuous integration and all code committed to the `master/main` branch passed Unit Tests. To run the tests locally, run `make tests` and then execute the binary available at `build/unittest.out`.