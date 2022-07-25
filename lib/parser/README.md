### Compile:

```
javac -cp lib/jason-2.6.jar                              \
          src/translator/As2Json.java                    \
          src/translator/PlanSkeleton.java               \
          src/translator/BodyInstruction.java            \
          src/translator/EventOperatorType.java          \
          src/translator/HeaderCreator.java
```

### Run:

```
EVENT_BASE_SIZE=3
INTENTION_BASE_SIZE=10
INTETION_STACK_SIZE=4

java -cp lib/jason-2.6.jar:src                                      \
         translator.As2Json                                         \
         agentspeak.asl                                             \
         src/example/functions.h                                    \
         src/example/configuration.h                                \
         $EVENT_BASE_SIZE $INTENTION_BASE_SIZE $INTETION_STACK_SIZE
```

### Test:

```
cd test
java -cp ../lib/jason-2.6.jar:../src                                      \
         translator.As2Json                                         \
         test.asl                                             \
         functions.h                                    \
         configuration.h                                \
         $EVENT_BASE_SIZE $INTENTION_BASE_SIZE $INTETION_STACK_SIZE
```
