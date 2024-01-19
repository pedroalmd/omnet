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
        @display("i=abstract/switch"); // add a default icon

    gates:
        inout peer_gate[];
        inout controller_gate[];  // declare two way connections
//        inout server_gate[];
}

simple Controller
{
    parameters:
        @display("i=abstract/dispatcher"); // add a default icon

    gates:
//        inout client_gate[];  // declare two way connections
        inout switch_gate[];
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
        controller[1]: Controller;
		peer[5]: Peer;

    connections:
		switch[0].peer_gate++ <--> Channel <--> peer[0].gate++;
		switch[0].peer_gate++ <--> Channel <--> peer[1].gate++;
		switch[0].peer_gate++ <--> Channel <--> peer[2].gate++;
		switch[0].peer_gate++ <--> Channel <--> peer[3].gate++;
		switch[0].peer_gate++ <--> Channel <--> peer[4].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[5].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[6].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[7].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[8].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[9].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[10].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[11].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[12].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[13].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[14].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[15].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[16].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[17].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[18].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[19].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[20].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[21].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[22].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[23].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[24].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[25].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[26].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[27].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[28].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[29].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[30].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[31].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[32].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[33].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[34].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[35].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[36].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[37].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[38].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[39].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[40].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[41].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[42].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[43].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[44].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[45].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[46].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[47].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[48].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[49].gate++;

        controller[0].switch_gate++ <--> Channel <--> switch[0].controller_gate++;

//        switch[0].client_gate++ <--> Channel <--> client[0].gate++;
//        switch[0].server_gate++ <--> Channel <--> server[0].gate++;
//        switch[0].client_gate++ <--> Channel <--> client[1].gate++;
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


//
// Two instances (tic and toc) of Server connected both ways.
// Tic and toc will pass messages to one another.
//
