//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2003 Ahmet Sekercioglu
// Copyright (C) 2003-2015 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include <map>
#include <string>

using namespace omnetpp;

// Include a generated file: the header file created from tictoc1.msg.
// It contains the definition of the ContentMsg0 class, derived from
// cMessage.
#include "content_m.h"
#include "global.h"

/**
 * In this step the destination address is no longer node 2 -- we draw a
 * random destination, and we'll add the destination address to the message.
 *
 * The best way is to subclass cMessage and add destination as a data member.
 * Hand-coding the message class is usually tiresome because it contains
 * a lot of boilerplate code, so we let OMNeT++ generate the class for us.
 * The message class specification is in tictoc1.msg -- tictoc1_m.h
 * and .cc will be generated from this file automatically.
 *
 * To make the model execute longer, after a message arrives to its destination
 * the destination node will generate another message with a random destination
 * address, and so forth.
 */
class Switch : public cSimpleModule
{
  protected:
    std::map<int, char> table;
    int alive_peers[100];

    virtual int getServer(char content, std::map<int, char> table);
    virtual ContentMsg *generateMessage(char type, int destination);
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void forwardToController(ContentMsg *ttmsg);
};

Define_Module(Switch);


void Switch::initialize()
{

    int network_size = sizeof(contents_has) / sizeof(int);

    for (int i = 0; i < network_size; i++) {
        alive_peers[i] = 1;
        table[i] = contents_has[i];
    }

//    for (auto itr = table.begin(); itr != table.end(); ++itr) {
//       EV << itr->first << ": " << itr->second << endl;
//    }
}

void Switch::handleMessage(cMessage *msg)
{
    ContentMsg *ttmsg = check_and_cast<ContentMsg *>(msg);

    char request = 'r';
    char response = 'c';
    char tcp = 't';
    char dead_from_controller = 'e';
    char dead = 'd';


    if (ttmsg->getType() == request || ttmsg->getType() == response) {
        if (ttmsg->getDestination() == 2222) {
//            int server = getServer(ttmsg->getContent(), table);
//
//            ttmsg->setDestination(server);
            forwardToController(ttmsg);
        }

        if (ttmsg->getDestination() != 2222) {
            send(ttmsg, "peer_gate$o", ttmsg->getDestination());
        }

    }

    if (ttmsg->getType() == tcp) {
        send(ttmsg, "peer_gate$o", ttmsg->getDestination());
    }

    if (ttmsg->getType() == dead) {
//        send(ttmsg, "peer_gate$o", ttmsg->getDestination());
//        alive_peers[ttmsg->getSource_num()] = 0;
//        EV << "Peer " << ttmsg->getSource_num() << " is dead" << "\n";
        forwardToController(ttmsg);
    }

    if (ttmsg->getType() == dead_from_controller) {
        ttmsg->setType(dead);
        send(ttmsg, "peer_gate$o", ttmsg->getDestination());
    }



//
//    EV << "Message " << ttmsg->getType() << " arrived with type " << ttmsg->getTcp_type() << " from " << ttmsg->getSource_num() << "\n";
//
//    send(msg, "peer_gate$o", ttmsg->getDestination());
}

ContentMsg *Switch::generateMessage(char type, int destination)
{
    // Produce Source_num and destination addresses.
    int src = getIndex();  // our module index
    int n = getVectorSize();  // module vector size
    int dest = destination;

    char msgname[20];
    sprintf(msgname, "Response");

    // Create message object and set Source_num and destination field.
    ContentMsg *msg = new ContentMsg(msgname);
    msg->setSource_num(src);
    msg->setDestination(dest);
    msg->setContent(type);

    return msg;
}


//void Switch::printVector(std::vector<int> v)
//{
//    for(int i=0; i<v.size(); i++){
//        EV << "Peer: " << v[i] << "\n";
//    }
//}


int Switch::getServer(char content, std::map<int, char>  table) {
    for (auto itr = table.begin(); itr != table.end(); ++itr) {
//       EV << itr->first << ": " << itr->second << endl << "\n";

       if (itr->second == content && alive_peers[itr->first] == 1) {
           return itr->first;
       }
    }

    return 2222;
}


void Switch::forwardToController(ContentMsg *ttmsg)
{
    send(ttmsg, "controller_gate$o", 0);
}

