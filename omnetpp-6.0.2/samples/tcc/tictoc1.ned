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
		peer[100]: Peer;

    connections:
		switch[0].peer_gate++ <--> Channel <--> peer[0].gate++;
		switch[0].peer_gate++ <--> Channel <--> peer[1].gate++;
		switch[0].peer_gate++ <--> Channel <--> peer[2].gate++;
		switch[0].peer_gate++ <--> Channel <--> peer[3].gate++;
		switch[0].peer_gate++ <--> Channel <--> peer[4].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[5].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[6].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[7].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[8].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[9].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[10].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[11].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[12].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[13].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[14].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[15].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[16].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[17].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[18].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[19].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[20].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[21].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[22].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[23].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[24].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[25].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[26].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[27].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[28].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[29].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[30].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[31].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[32].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[33].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[34].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[35].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[36].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[37].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[38].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[39].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[40].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[41].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[42].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[43].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[44].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[45].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[46].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[47].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[48].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[49].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[50].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[51].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[52].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[53].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[54].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[55].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[56].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[57].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[58].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[59].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[60].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[61].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[62].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[63].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[64].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[65].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[66].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[67].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[68].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[69].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[70].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[71].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[72].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[73].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[74].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[75].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[76].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[77].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[78].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[79].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[80].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[81].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[82].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[83].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[84].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[85].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[86].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[87].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[88].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[89].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[90].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[91].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[92].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[93].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[94].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[95].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[96].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[97].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[98].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[99].gate++;

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
