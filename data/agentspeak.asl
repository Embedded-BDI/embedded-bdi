!start.

+!start <- join_lottery;
           grab_number;
           !!wait_for_number.

+!wait_for_number : my_number <- cheer_and_leave.
+!wait_for_number <- !!wait_for_number.