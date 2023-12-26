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
class Server : public cSimpleModule
{
  protected:
    virtual ContentMsg *generateMessage(char content, int destination, int tcp_type = 0);
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Server);

void Server::initialize()
{
}

void Server::handleMessage(cMessage *msg)
{
    ContentMsg *ttmsg = check_and_cast<ContentMsg *>(msg);

    char request = 'r';
    char tcp = 't';

    if (ttmsg->getContent() == tcp) {
        if (ttmsg->getTcp_type() == 1) {
                EV << "Generating syn+ack. \n";

                ContentMsg *msg = generateMessage('t', ttmsg->getSource_num(), 2);
                send(msg, "gate$o", 0);
        }

        else if (ttmsg->getTcp_type() == 3) {
            bubble("TCP connection established");
        }
    }

    if (ttmsg->getDestination() == getIndex()) {
        // Message arrived.
        EV << "Message " << ttmsg->getContent() << " arrived from client " << ttmsg->getSource_num() << "\n";
    }

    if (ttmsg->getContent() == request) {
        EV << "Generating response. \n";

        ContentMsg *msg = generateMessage('c', ttmsg->getSource_num());
        send(msg, "gate$o", 0);
    }
}

ContentMsg *Server::generateMessage(char content, int destination, int tcp_type)
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
    msg->setContent(content);

    if (content == 't') {
        msg->setTcp_type(tcp_type);
    }

    return msg;
}

