#!/bin/bash

EVENT_BASE_SIZE=6
INTENTION_BASE_SIZE=10
INTETION_STACK_SIZE=4

javac -cp lib/parser/lib/jason-2.6.jar                              \
          lib/parser/src/translator/As2Json.java                    \
          lib/parser/src/translator/PlanSkeleton.java               \
          lib/parser/src/translator/BodyInstruction.java            \
          lib/parser/src/translator/EventOperatorType.java          \
          lib/parser/src/translator/HeaderCreator.java

java -cp lib/parser/lib/jason-2.6.jar:lib/parser/src                \
         translator.As2Json                                         \
         data/agentspeak.asl                                        \
         data/functions.h                                           \
         src/config/configuration.h                                 \
         $EVENT_BASE_SIZE $INTENTION_BASE_SIZE $INTETION_STACK_SIZE