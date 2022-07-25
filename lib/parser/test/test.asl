!start.

+!start <- +happy.

+happy <- !!hello.

+!hello <- say_hello.

+!hello : i_am_host <- .broadcast(tell,happy).
