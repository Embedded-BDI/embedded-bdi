# Based on https://spin.atomicobject.com/2016/08/26/makefile-c-projects/

############################ General configuration #############################
# Compiler to be used
CXX := g++

# Special flags for compilation such as hardware specific-flags for embedded platforms
ADDITIONAL_FLAGS :=

# https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html
DEBUG_LEVEL :=

# https://www.rapidtables.com/code/linux/gcc/gcc-o.html
OPTIMIZATION_FLAG := -Os

# Output folders and files
.DEFAULT_GOAL := all

TEST_EXEC ?= unittest.out
AGENT_EXEC ?= agent.out
VALGRIND_EXEC ?= valgrind.out

DOCS_DIR ?= ./docs
BUILD_DIR ?= ./build

############################### Agent variables ################################
AGENT_DIRS ?= ./lib ./data ./src
AGENT_SRCS := $(shell find $(AGENT_DIRS) -name *.cpp -or -name *.c -or -name *.s -or -name *.cc)
AGENT_OBJS := $(AGENT_SRCS:%=$(BUILD_DIR)/%.o)
AGENT_DEPS := $(AGENT_OBJS:.o=.d)
AGENT_INC_DIRS := $(shell find $(AGENT_DIRS) -type d ! -path '*/Debug*')
AGENT_INC_FLAGS := $(addprefix -I,$(AGENT_INC_DIRS))

$(BUILD_DIR)/$(AGENT_EXEC): $(AGENT_OBJS)
	$(CXX) $(AGENT_OBJS) -o $@ $(LDFLAGS)

################################ Test variables ################################
TEST_DIRS ?= ./lib ./test
TEST_SRCS := $(shell find $(TEST_DIRS) -name *.cpp -or -name *.c -or -name *.s -or -name *.cc)
TEST_OBJS := $(TEST_SRCS:%=$(BUILD_DIR)/%.o)
TEST_DEPS := $(TEST_OBJS:.o=.d)
TEST_INC_DIRS := $(shell find $(TEST_DIRS) -type d ! -path '*/Debug*')
TEST_INC_FLAGS := $(addprefix -I,$(TEST_INC_DIRS) )

$(BUILD_DIR)/$(TEST_EXEC): $(TEST_OBJS)
	$(CXX) $(TEST_OBJS) -o $@ $(LDFLAGS)

############################# Valgrind variables ###############################
VALGRIND_DIRS ?= ./lib ./valgrind 
VALGRIND_SRCS := $(shell find $(VALGRIND_DIRS) -name *.cpp -or -name *.c -or -name *.s -or -name *.cc)
VALGRIND_OBJS := $(VALGRIND_SRCS:%=$(BUILD_DIR)/%.o)
VALGRIND_DEPS := $(VALGRIND_OBJS:.o=.d)
VALGRIND_INC_DIRS := $(shell find $(VALGRIND_DIRS) -type d ! -path '*/Debug*')
VALGRIND_INC_FLAGS := $(addprefix -I,$(VALGRIND_INC_DIRS))

$(BUILD_DIR)/$(VALGRIND_EXEC): $(VALGRIND_OBJS)
	$(CXX) $(VALGRIND_OBJS) -o $@ $(LDFLAGS)

################################# Build rules #################################

CPPFLAGS ?= -std=c++11 $(OPTIMIZATION_FLAG) -Wall -DGTEST_HAS_PTHREAD=0 $(DEBUG_LEVEL) $(ADDITIONAL_FLAGS) $(TEST_INC_FLAGS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cc.o: %.cc
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

################################# Make targets #################################
.PHONY: clean agent docs

all: tests valgrind agent docs

agent: translate force_agent_update $(BUILD_DIR)/$(AGENT_EXEC)

tests: $(BUILD_DIR)/$(TEST_EXEC)

valgrind: $(BUILD_DIR)/$(VALGRIND_EXEC)

translate:
	javac -cp lib/parser/lib/jason-2.6.jar                                    \
            lib/parser/src/translator/As2Json.java                          \
            lib/parser/src/translator/PlanSkeleton.java                     \
            lib/parser/src/translator/BodyInstruction.java                  \
            lib/parser/src/translator/EventOperatorType.java                \
            lib/parser/src/translator/HeaderCreator.java

	java -cp lib/parser/lib/jason-2.6.jar:lib/parser/src                      \
           translator.As2Json                                               \
           data/agentspeak.asl                                              \
           data/functions.h                                                 \
           src/config/configuration.h                                       \
           $(EVENT_BASE_SIZE) $(INTENTION_BASE_SIZE) $(INTENTION_STACK_SIZE)

docs:
	if [ -d "/Applications/Doxygen.app/Contents/Resources" ];                 \
  then                                                                      \
    cd $(DOCS_DIR);                                                         \
    /Applications/Doxygen.app/Contents/Resources/doxygen Doxygen.doxyfile;  \
  else                                                                      \
    cd $(DOCS_DIR);                                                         \
    doxygen Doxygen.doxyfile;                                               \
  fi

force_agent_update:
	touch ./src/agent_loop.cpp

clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) -r $(DOCS_DIR)/html

-include $(AGENT_DEPS)
-include $(TEST_DEPS)
-include $(VALGRIND_DEPS)
-include agent.config

MKDIR_P ?= mkdir -p