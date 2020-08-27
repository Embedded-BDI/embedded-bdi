package translator;

public enum EventOperatorType {
  BELIEF_ADDITION,      // +
  BELIEF_DELETION,      // -
  GOAL_ADDITION,        // +!
  GOAL_DELETION,        // -!
  TEST_GOAL_ADDITION,   // +?!
  TEST_GOAL_DELETION,   // -?!
}