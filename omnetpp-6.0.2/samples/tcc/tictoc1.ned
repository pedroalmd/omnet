simple Peer
{
    parameters:
        @display("i=block/routing"); // add a default icon

    gates:
        inout gate[];  // declare two way connections
        inout controller_gate[];
}

simple Switch
{
    parameters:
        @display("i=block/routing"); // add a default icon

    gates:
        inout peer_gate[];
//        inout client_gate[];  // declare two way connections
//        inout server_gate[];
}

network Tictoc1
{
    @display("bgb=407,304");
    types:
        channel Channel extends ned.DelayChannel
        {
            delay = 100ms;
        }
    submodules:
        switch[1]: Switch;
//        server[2]: Server;
//        client[2]: Client;
//        controller[1]: Controller;
		peer[5]: Peer;

    connections:
		switch[0].peer_gate++ <--> Channel <--> peer[0].gate++;
		switch[0].peer_gate++ <--> Channel <--> peer[1].gate++;
		switch[0].peer_gate++ <--> Channel <--> peer[2].gate++;
		switch[0].peer_gate++ <--> Channel <--> peer[3].gate++;
		switch[0].peer_gate++ <--> Channel <--> peer[4].gate++;

//        switch[0].client_gate++ <--> Channel <--> client[0].gate++;
//        switch[0].server_gate++ <--> Channel <--> server[0].gate++;
//        switch[0].client_gate++ <--> Channel <--> client[1].gate++;
//        controller[0].server_gate++ <--> Channel <--> server[0].controller_gate++;
//        controller[0].server_gate++ <--> Channel <--> server[1].controller_gate++;

//        switch[0].server_gate++ <--> Channel <--> server[1].gate++;
}


//simple Server
//{
//    parameters:
//        @display("i=block/routing"); // add a default icon
//
//    gates:
//        inout gate[];  // declare two way connections
//        inout controller_gate[];
//}


//simple Client
//{
//    parameters:
//        @display("i=block/routing"); // add a default icon
//
//    gates:
//        inout gate[];  // declare two way connections
//}

//simple Controller
//{
//    parameters:
//        @display("i=block/routing"); // add a default icon
//
//    gates:
//        inout client_gate[];  // declare two way connections
//        inout server_gate[];
//}

//
// Two instances (tic and toc) of Server connected both ways.
// Tic and toc will pass messages to one another.
//
