# Based on https://spin.atomicobject.com/2016/08/26/makefile-c-projects/
.DEFAULT_GOAL := all

TEST_EXEC ?= unittest.out
AGENT_EXEC ?= agent.out

DOCS_DIR ?= ./docs
BUILD_DIR ?= ./build
TEST_DIRS ?= ./lib ./test
AGENT_DIRS ?= ./lib ./src
TEST_SRCS := $(shell find $(TEST_DIRS) -name *.cpp -or -name *.c -or -name *.s -or -name *.cc)
AGENT_SRCS := $(shell find $(AGENT_DIRS) -name *.cpp -or -name *.c -or -name *.s -or -name *.cc)
TEST_OBJS := $(TEST_SRCS:%=$(BUILD_DIR)/%.o)
AGENT_OBJS := $(AGENT_SRCS:%=$(BUILD_DIR)/%.o)
TEST_DEPS := $(TEST_OBJS:.o=.d)
AGENT_DEPS := $(AGENT_OBJS:.o=.d)

TEST_INC_DIRS := $(shell find $(TEST_DIRS) -type d)
AGENT_INC_DIRS := $(shell find $(AGENT_DIRS) -type d)
TEST_INC_FLAGS := $(addprefix -I,$(TEST_INC_DIRS))
AGENT_INC_FLAGS := $(addprefix -I,$(AGENT_INC_DIRS))

TEST_CPPFLAGS ?= -std=c++11 -DGTEST_HAS_PTHREAD=0 $(TEST_INC_FLAGS) -O0 -g3 -Wall -MMD -MP
AGENT_CPPFLAGS ?= -std=c++11 $(AGENT_INC_FLAGS) -O0 -g3 -Wall -MMD -MP

CXX := g++

$(BUILD_DIR)/$(TEST_EXEC): $(TEST_OBJS)
	$(CXX) $(TEST_OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/$(AGENT_EXEC): $(AGENT_OBJS)
	$(CXX) $(AGENT_OBJS) -o $@ $(LDFLAGS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CXX) $(TEST_CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(TEST_CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cc.o: %.cc
	$(MKDIR_P) $(dir $@)
	$(CXX) $(TEST_CPPFLAGS) $(CXXFLAGS) -c $< -o $@

all: test agent

agent: $(BUILD_DIR)/$(AGENT_EXEC)

test: $(BUILD_DIR)/$(TEST_EXEC)

docs:
	if [ -d "/Applications/Doxygen.app/Contents/Resources" ]; \
	then \
		cd $(DOCS_DIR); \
		/Applications/Doxygen.app/Contents/Resources/doxygen Doxygen.doxyfile; \
	else \
		if [ $(command -v doxygen) ]; \
		then \
			cd $(DOCS_DIR); \
			doxygen Doxygen.doxyfile; \
		fi \
	fi

.PHONY: all docs clean

clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) -r $(DOCS_DIR)/html

-include $(AGENT_DEPS)
-include $(TEST_DEPS)

MKDIR_P ?= mkdir -p