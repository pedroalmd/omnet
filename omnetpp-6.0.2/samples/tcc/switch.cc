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

    virtual int getServer(char content, std::map<int, char> table);
    virtual ContentMsg *generateMessage(char type, int destination);
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

};

Define_Module(Switch);

void Switch::initialize()
{
    table[0] = 'a';
    table[1] = 'b';

    for (auto itr = table.begin(); itr != table.end(); ++itr) {
       EV << itr->first << ": " << itr->second << endl;
    }
}

void Switch::handleMessage(cMessage *msg)
{
    ContentMsg *ttmsg = check_and_cast<ContentMsg *>(msg);

    char request = 'r';
    char response = 'c';
    char tcp = 't';

    if (ttmsg->getType() == 'r') {
        if (ttmsg->getDestination() == 255) {
            int server = getServer(ttmsg->getContent(), table);

            ttmsg->setType('r');
            ttmsg->setDestination(server);
            send(ttmsg, "peer_gate$o", ttmsg->getDestination());
        }
    }

    // NEXT
    if (ttmsg->getType() == 'r') {
        if (ttmsg->getDestination() == 255) {
            int server = getServer(ttmsg->getContent(), table);

            ttmsg->setType('r');
            ttmsg->setDestination(server);
            send(ttmsg, "peer_gate$o", ttmsg->getDestination());
        }
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

int Switch::getServer(char content, std::map<int, char>  table) {
    for (auto itr = table.begin(); itr != table.end(); ++itr) {
       EV << itr->first << ": " << itr->second << endl << "\n";

       if (itr->second == content){
           return itr->first;
       }
    }

    return 255;
}

