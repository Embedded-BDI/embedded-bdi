!goal1.
!goal2.

+!goal1 <- action_return_false.
-!goal1 <- action_deletion_1.

+!goal2 <- action_return_true; !goal3; action_return_true.
+!goal3 <- action_return_true; !goal4.
+!goal4 <- action_return_false.
-!goal4 <- action_deletion_1.
-!goal4 <- action_deletion_2.