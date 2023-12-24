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
// It contains the definition of the TictocMsg10 class, derived from
// cMessage.
#include "tictoc1_m.h"

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
class Txc1 : public cSimpleModule
{
  protected:
    virtual TicTocMsg1 *generateMessage(char content, int destination);
    virtual void forwardMessage(TicTocMsg1 *msg);
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Txc1);

void Txc1::initialize()
{
    // Module 0 sends the first message
    if (getIndex() == 0) {
        // Boot the process scheduling the initial message as a self-message.
        TicTocMsg1 *msg = generateMessage('a', 1);
        send(msg, "gate$o", 0);
//        scheduleAt(0.0, msg);
    }
}

//void Txc1::handleMessage(cMessage *msg)
//{
//    TicTocMsg1 *ttmsg = check_and_cast<TicTocMsg1 *>(msg);
//
//    if (ttmsg->getDestination() == getIndex()) {
//        // Message arrived.
//        EV << "Message " << ttmsg << " arrived after " << ttmsg->getHopCount() << " hops.\n";
//        bubble("ARRIVED, starting new one!");
//        delete ttmsg;
//
//        // Generate another one.
//        EV << "Generating another message: ";
//        TicTocMsg1 *newmsg = generateMessage();
//        EV << newmsg << endl;
//        forwardMessage(newmsg);
//    }
//    else {
//        // We need to forward the message.
//        forwardMessage(ttmsg);
//    }
//}

void Txc1::handleMessage(cMessage *msg)
{
    TicTocMsg1 *ttmsg = check_and_cast<TicTocMsg1 *>(msg);

    if (ttmsg->getDestination() == getIndex()) {
        // Message arrived.
        EV << "Message " << ttmsg->getContent() << " arrived from peer " << ttmsg->getSource() << "\n";
    }

    if (ttmsg->getContent() == 'a') {
    // Generate another one.
        EV << "Generating another message. \n";
        delete ttmsg;

        TicTocMsg1 *msg = generateMessage('a', 0);
        send(msg, "gate$o", 0);
    }

//    else {
//        // We need to forward the message.
//        forwardMessage(ttmsg);
//    }
}

TicTocMsg1 *Txc1::generateMessage(char content, int destination)
{
    // Produce source and destination addresses.
    int src = getIndex();  // our module index
    int n = getVectorSize();  // module vector size
    int dest = destination;

    char msgname[20];
    sprintf(msgname, "Request");

    // Create message object and set source and destination field.
    TicTocMsg1 *msg = new TicTocMsg1(msgname);
    msg->setSource(src);
    msg->setDestination(dest);
    msg->setContent(content);
    return msg;
}

void Txc1::forwardMessage(TicTocMsg1 *msg)
{
    // Increment hop count.
    msg->setHopCount(msg->getHopCount()+1);

    // Same routing as before: random gate.
    int n = gateSize("gate");
    int k = intuniform(0, n-1);

    EV << "Forwarding message " << msg << " on gate[" << k << "]\n";
    send(msg, "gate$o", k);
}

