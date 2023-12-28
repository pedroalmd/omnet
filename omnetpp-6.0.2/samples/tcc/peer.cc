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
#include "contentO.h"

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
class Peer : public cSimpleModule
{
  protected:
    contentO video_has;
    contentO video_wants;

    int has_tcp = 0;

    virtual ContentMsg *generateMessage(char type, char content, int destination = 255, int tcp_type = 0);
    virtual int getServer();
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Peer);

void Peer::initialize()
{
    int index = getIndex();

    if (index == 0) {
        video_has.setName('a');
        video_wants.setName('b');
        EV << "Generating sin! \n";
        ContentMsg *msg = generateMessage('r', video_wants.getName()); // r = request (comes from Peer)
        send(msg, "gate$o", 0); // 0 is always the switch
    } else {
        video_has.setName('b');
        video_wants.setName('c');
    }
    // Module 0 sends the first message
        // Boot the process scheduling the initial message as a self-message.

//        scheduleAt(0.0, msg);
}

void Peer::handleMessage(cMessage *msg)
{
    ContentMsg *ttmsg = check_and_cast<ContentMsg *>(msg);

    char tcp = 't';
    char request = 'r';
    char content = 'c';

    if (ttmsg->getType() == tcp) {

        if (ttmsg->getTcp_type() == 2) {
            EV << "Generating ack. \n";

            ContentMsg *msg = generateMessage('t', 0, ttmsg->getSource_num(), 3);
            send(msg, "gate$o", 0);

            EV << "Sending next request!\n";

            ContentMsg *cmsg = generateMessage('r', video_wants.getName(), ttmsg->getSource_num()); // r = request (comes from Peer)
            send(cmsg, "gate$o", 0); // 0 is always the switch
        }

        if (ttmsg->getTcp_type() == 1) {
                EV << "Generating syn+ack. \n";

                ContentMsg *msg = generateMessage('t', 0, ttmsg->getSource_num(), 2);
                send(msg, "gate$o", 0);
        }

        else if (ttmsg->getTcp_type() == 3) {
            bubble("TCP connection established");
        }

    }

    else if (ttmsg->getType() == content) {
        EV << "Sending next request!\n";

        ContentMsg *msg = generateMessage('r', video_wants.getName(), ttmsg->getSource_num()); // r = request (comes from Peer)
        send(msg, "gate$o", 0); // 0 is always the switch
    }

    else if (ttmsg->getType() == request) {
        EV << "Sending back content!\n";

        ContentMsg *msg = generateMessage('c', video_has.getName(), ttmsg->getSource_num()); // r = request (comes from Peer)
        send(msg, "gate$o", 0); // 0 is always the switch
    }

    if (ttmsg->getDestination() == getIndex()) {
        // Message arrived.
        EV << "Message " << ttmsg->getType() << " arrived from peer " << ttmsg->getSource_num() << "\n";
    }
}

ContentMsg *Peer::generateMessage(char type, char content, int destination, int tcp_type)
{
    // Produce Source_num and destination addresses.
    int src = getIndex();  // our module index
    int n = getVectorSize();  // module vector size
    int dest = destination;

    char msgname[20];
    sprintf(msgname, "Request");

    // Create message object and set Source_num and destination field.
    ContentMsg *msg = new ContentMsg(msgname);
    msg->setSource_num(src);
    msg->setDestination(dest);
    msg->setType(type);
    msg->setContent(content);

    if (type == 't') {
        msg->setTcp_type(tcp_type);
    }

    return msg;
}

int Peer::getServer()
{
    return 0;
}

