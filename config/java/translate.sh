#!/bin/bash

javac -cp lib/jason-2.6.jar src/translator/As2Json.java
java -cp lib/jason-2.6.jar:src translator.As2Json agentspeak.asl