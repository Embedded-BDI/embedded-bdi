### Compile:

```
javac -cp lib/jason-2.6.jar src/translator/As2Json.java src/translator/PlanSkeleton.java src/translator/BodyInstruction.java src/translator/EventOperatorType.java
```

### Run:

```
java -cp lib/jason-2.6.jar:src translator.As2Json agentspeak.asl
```