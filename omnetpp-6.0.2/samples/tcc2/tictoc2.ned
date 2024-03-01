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

network Tictoc2
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
		peer[150]: Peer;

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
        switch[0].peer_gate++ <--> Channel <--> peer[100].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[101].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[102].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[103].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[104].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[105].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[106].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[107].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[108].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[109].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[110].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[111].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[112].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[113].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[114].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[115].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[116].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[117].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[118].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[119].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[120].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[121].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[122].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[123].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[124].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[125].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[126].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[127].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[128].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[129].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[130].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[131].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[132].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[133].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[134].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[135].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[136].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[137].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[138].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[139].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[140].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[141].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[142].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[143].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[144].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[145].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[146].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[147].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[148].gate++;
        switch[0].peer_gate++ <--> Channel <--> peer[149].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[150].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[151].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[152].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[153].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[154].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[155].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[156].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[157].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[158].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[159].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[160].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[161].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[162].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[163].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[164].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[165].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[166].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[167].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[168].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[169].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[170].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[171].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[172].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[173].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[174].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[175].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[176].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[177].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[178].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[179].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[180].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[181].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[182].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[183].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[184].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[185].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[186].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[187].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[188].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[189].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[190].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[191].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[192].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[193].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[194].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[195].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[196].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[197].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[198].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[199].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[200].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[201].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[202].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[203].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[204].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[205].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[206].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[207].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[208].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[209].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[210].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[211].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[212].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[213].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[214].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[215].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[216].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[217].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[218].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[219].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[220].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[221].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[222].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[223].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[224].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[225].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[226].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[227].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[228].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[229].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[230].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[231].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[232].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[233].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[234].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[235].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[236].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[237].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[238].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[239].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[240].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[241].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[242].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[243].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[244].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[245].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[246].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[247].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[248].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[249].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[250].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[251].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[252].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[253].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[254].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[255].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[256].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[257].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[258].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[259].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[260].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[261].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[262].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[263].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[264].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[265].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[266].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[267].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[268].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[269].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[270].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[271].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[272].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[273].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[274].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[275].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[276].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[277].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[278].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[279].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[280].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[281].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[282].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[283].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[284].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[285].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[286].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[287].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[288].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[289].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[290].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[291].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[292].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[293].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[294].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[295].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[296].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[297].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[298].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[299].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[300].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[301].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[302].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[303].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[304].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[305].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[306].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[307].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[308].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[309].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[310].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[311].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[312].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[313].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[314].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[315].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[316].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[317].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[318].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[319].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[320].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[321].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[322].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[323].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[324].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[325].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[326].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[327].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[328].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[329].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[330].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[331].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[332].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[333].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[334].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[335].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[336].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[337].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[338].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[339].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[340].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[341].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[342].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[343].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[344].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[345].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[346].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[347].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[348].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[349].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[350].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[351].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[352].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[353].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[354].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[355].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[356].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[357].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[358].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[359].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[360].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[361].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[362].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[363].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[364].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[365].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[366].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[367].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[368].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[369].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[370].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[371].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[372].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[373].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[374].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[375].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[376].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[377].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[378].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[379].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[380].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[381].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[382].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[383].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[384].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[385].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[386].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[387].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[388].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[389].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[390].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[391].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[392].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[393].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[394].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[395].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[396].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[397].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[398].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[399].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[400].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[401].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[402].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[403].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[404].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[405].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[406].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[407].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[408].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[409].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[410].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[411].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[412].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[413].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[414].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[415].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[416].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[417].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[418].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[419].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[420].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[421].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[422].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[423].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[424].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[425].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[426].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[427].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[428].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[429].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[430].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[431].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[432].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[433].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[434].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[435].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[436].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[437].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[438].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[439].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[440].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[441].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[442].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[443].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[444].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[445].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[446].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[447].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[448].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[449].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[450].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[451].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[452].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[453].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[454].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[455].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[456].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[457].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[458].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[459].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[460].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[461].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[462].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[463].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[464].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[465].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[466].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[467].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[468].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[469].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[470].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[471].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[472].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[473].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[474].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[475].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[476].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[477].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[478].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[479].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[480].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[481].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[482].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[483].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[484].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[485].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[486].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[487].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[488].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[489].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[490].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[491].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[492].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[493].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[494].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[495].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[496].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[497].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[498].gate++;
//        switch[0].peer_gate++ <--> Channel <--> peer[499].gate++;
        
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
