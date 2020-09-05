#!/bin/bash

javac -cp lib/jason-2.6.jar src/translator/As2Json.java src/translator/PlanSkeleton.java src/translator/BodyInstruction.java src/translator/EventOperatorType.java src/translator/HeaderCreator.java
java -cp lib/jason-2.6.jar:src translator.As2Json agentspeak.asl