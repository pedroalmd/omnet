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
#include <cmath>
#include "contentO.h"
#include "global.h"

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

    int index;
    std::vector<int> serving_peers = {};
    int is_Alive = 1;

    virtual ContentMsg *generateMessage(char type, char content, int destination = 255, int tcp_type = 0);
    virtual void handleTcpMessage(ContentMsg *ttmsg);
    virtual void handleRequestMessage(ContentMsg *ttmsg);
    virtual void handleContentMessage(ContentMsg *ttmsg);
    virtual void sendDeadResponseMessage(ContentMsg *ttmsg);
    virtual void appendToServingPeers(int element);
    virtual int isInArray(int element, std::vector<int> v);
    virtual void eraseFromServingPeers(int element);
    virtual int getElementIndexInVector(int element, std::vector<int> v);
    virtual void printServingPeers();


    virtual int getServer();
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Peer);

void Peer::initialize()
{
    index = getIndex();

    video_has.setName(contents_has[index]);
    video_wants.setName(contents_wants[index]);

    ContentMsg *msg = generateMessage('r', video_wants.getName(), 255, 0); // r = request (comes from Peer)
    send(msg, "gate$o", 0); // 0 is always the switch
}

void Peer::handleMessage(cMessage *msg)
{
    ContentMsg *ttmsg = check_and_cast<ContentMsg *>(msg);

    char tcp = 't';
    char request = 'r';
    char content = 'c';
    char dead = 'd';

    printServingPeers();

    if (ttmsg->getDestination() == getIndex()) {
        // Message arrived.
        EV << "Message " << ttmsg->getType() << " arrived from peer " << ttmsg->getSource_num() << "\n";
    }

    if (peer_dying_time[index] != 0 && simTime() >= peer_dying_time[index]) {
        is_Alive = 0;
    }

    if (is_Alive == 0) {
        if (ttmsg->getType() != content && ttmsg->getType() != dead) {
            if (ttmsg->getType() == tcp) {
                if (ttmsg->getTcp_type() != 1) {
                    return;
                }
            }

            sendDeadResponseMessage(ttmsg);
        }

        return;
    }

    if (ttmsg->getType() == tcp) {
        handleTcpMessage(ttmsg);
    }

    else if (ttmsg->getType() == content) {
        handleContentMessage(ttmsg);
    }

    else if (ttmsg->getType() == request) {
        handleRequestMessage(ttmsg);
    }

    else if (ttmsg->getType() == dead) {
        EV << "Sending unknown destination request!\n";

        ContentMsg *msg = generateMessage('r', video_wants.getName(), 255, 0);
        send(msg, "gate$o", 0); // 0 is always the switch
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
    msg->setTcp_type(tcp_type);

    return msg;
}

void Peer::handleTcpMessage(ContentMsg *ttmsg)
{

    if (ttmsg->getTcp_type() == 0) {
        EV << "Generating sin! \n";
        ContentMsg *msg = generateMessage('t', 0, ttmsg->getSource_num(), 1); // r = request (comes from Peer)
        send(msg, "gate$o", 0); // 0 is always the switch
    }

    else if (ttmsg->getTcp_type() == 1) {
            EV << "Generating sin+ack. \n";

            ContentMsg *msg = generateMessage('t', 0, ttmsg->getSource_num(), 2);
            send(msg, "gate$o", 0);
    }

    else if (ttmsg->getTcp_type() == 2) {
        EV << "Generating ack. \n";

        ContentMsg *msg = generateMessage('t', 0, ttmsg->getSource_num(), 3);
        send(msg, "gate$o", 0);

        EV << "Sending first request!\n";

        ContentMsg *cmsg = generateMessage('r', video_wants.getName(), ttmsg->getSource_num(), 4); // r = request (comes from Peer)
        send(cmsg, "gate$o", 0); // 0 is always the switch
    }

    else if (ttmsg->getTcp_type() == 3) {
        bubble("TCP connection established");
        appendToServingPeers(ttmsg->getSource_num());
    }
}


void Peer::handleRequestMessage(ContentMsg *ttmsg)
{


    if (ttmsg->getTcp_type() == 4) {
        double delay_time = std::pow(2, (serving_peers.size() - 1)) / 10; // evertime a peer joins, it takes double the time to respond o the request

        EV << "Sending back content!\n";
        ContentMsg *msg = generateMessage('c', video_has.getName(), ttmsg->getSource_num(), 3); // r = request (comes from Peer)
        sendDelayed(msg, delay_time, "gate$o", 0); // 0 is always the switch
    }

    else if (ttmsg->getTcp_type() == 0) {
        EV << "No TCP connection! \n";
        ContentMsg *msg = generateMessage('t', video_has.getName(), ttmsg->getSource_num(), 0); // r = request (comes from Peer)
        send(msg, "gate$o", 0); // 0 is always the switch
    }
}


void Peer::handleContentMessage(ContentMsg *ttmsg)
{
    EV << "Sending next request!\n";

    ContentMsg *msg = generateMessage('r', video_wants.getName(), ttmsg->getSource_num(), 4); // r = request (comes from Peer)
    send(msg, "gate$o", 0); // 0 is always the switch
}


void Peer::sendDeadResponseMessage(ContentMsg *ttmsg)
{
    EV << "[ME] Peer " << getIndex() << " left!\n";

    ContentMsg *msg = generateMessage('d', '0', ttmsg->getSource_num(), 0); // r = request (comes from Peer)
    sendDelayed(msg, dead_timeout, "gate$o", 0); // 0 is always the switch
}


void Peer::appendToServingPeers(int element)
{
    if (isInArray(element, serving_peers) == 0) {
        serving_peers.push_back(element);
    }
}


void Peer::eraseFromServingPeers(int element)
{
    if (isInArray(element, serving_peers) == 0) {
        return;
    }

    int element_index = getElementIndexInVector(element, serving_peers);

    serving_peers.erase(serving_peers.begin() + element_index);
}

int Peer::getElementIndexInVector(int element, std::vector<int> v)
{
    for(int i = 0; i < v.size(); i++) {
       if (element == v[i]) {
           return i;
       }
    }

    return 255;
}


void Peer::printServingPeers()
{
    for(int i = 0; i < serving_peers.size(); i++) {
        EV << "Peer " << index << " serving Peer " << serving_peers[i] << "\n";
    }
}

int Peer::isInArray(int element, std::vector<int> v)
{
    // 1 if True

    for(int i = 0; i < v.size(); i++) {
       if (element == v[i]) {
           return 1;
       }
    }

    return 0;
}


int Peer::getServer()
{
    return 0;
}

