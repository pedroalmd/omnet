simple Txc1
{
    parameters:
        @display("i=block/routing"); // add a default icon

    gates:
        inout gate[];  // declare two way connections
}

//
// Two instances (tic and toc) of Txc1 connected both ways.
// Tic and toc will pass messages to one another.
//
network Tictoc1
{
	types:
	    channel Channel extends ned.DelayChannel {
	        delay = 100ms;
	    }
    submodules:
        peer[3]: Txc1;
    connections:
        peer[0].gate++ <--> Channel <--> peer[1].gate++;
        peer[1].gate++ <--> Channel <--> peer[2].gate++;
        // peer[1].gate++ <--> Channel <--> peer[4].gate++;
        // peer[3].gate++ <--> Channel <--> peer[4].gate++;
        // peer[4].gate++ <--> Channel <--> peer[5].gate++;
}
