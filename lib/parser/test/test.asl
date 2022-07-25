!start.

+!start <- +happy.

+happy <- !!hello.

+!hello <- say_hello.

+!hello : am_i_host <- .broadcast(tell,happy).
