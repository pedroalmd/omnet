////
//// This file is part of an OMNeT++/OMNEST simulation example.
////
//// Copyright (C) 2003 Ahmet Sekercioglu
//// Copyright (C) 2003-2015 Andras Varga
////
//// This file is distributed WITHOUT ANY WARRANTY. See the file
//// `license' for details on this and other legal matters.
////
//
//#include <stdio.h>
//#include <string.h>
//#include <omnetpp.h>
//#include "contentO.h"
//
//
//using namespace omnetpp;
//
//// Include a generated file: the header file created from tictoc1.msg.
//// It contains the definition of the ContentMsg0 class, derived from
//// cMessage.
//#include "content_m.h"
//
//
///**
// * In this step the destination address is no longer node 2 -- we draw a
// * random destination, and we'll add the destination address to the message.
// *
// * The best way is to subclass cMessage and add destination as a data member.
// * Hand-coding the message class is usually tiresome because it contains
// * a lot of boilerplate code, so we let OMNeT++ generate the class for us.
// * The message class specification is in tictoc1.msg -- tictoc1_m.h
// * and .cc will be generated from this file automatically.
// *
// * To make the model execute longer, after a message arrives to its destination
// * the destination node will generate another message with a random destination
// * address, and so forth.
// */
//class Controller : public cSimpleModule
//{
//  protected:
//    int myNum = 0;
//    contentO video;
//    int alive_peers[100];
//
//
//    virtual ContentMsg *generateMessage(char content, int destination, int tcp_type = 0);
//    virtual void initialize() override;
//    virtual void handleMessage(cMessage *msg) override;
//};
//
//Define_Module(Controller);
//
//void Controller::initialize()
//{
////    int servers_amount = 2;
////
////
////    for (int i = 0; i < servers_amount; i++) {
////        ContentMsg *msg = generateMessage('k', i); // r = request (comes from client)
////        scheduleAt(0.0, msg);
////    }
//}
//
//void Controller::handleMessage(cMessage *msg)
//{
//    ContentMsg *ttmsg = check_and_cast<ContentMsg *>(msg);
//
//    char request = 'r';
//    char tcp = 't';
//    char keepalive = 'k';
//    char alive = 'a';
//    char dead = 'd';
//
//
//    myNum++;
//
//    EV << "Video: " << video.getName() << "\n";
//
//    video.setName('d');
//
//    if (ttmsg->getContent() == keepalive) {
//            EV << "Generating keepalive check. " << myNum << "\n";
//
//            ContentMsg *msg = generateMessage('k', ttmsg->getDestination());
//            send(msg, "server_gate$o", ttmsg->getDestination());
//    }
//
//    else if (ttmsg->getContent() == alive) {
//        EV << "Server " << ttmsg->getSource_num() << " is alive. \n";
//
//        ContentMsg *msg = generateMessage('k', ttmsg->getSource_num());
//        scheduleAt(simTime() + 0.5, msg);
//    }
//}
//
//ContentMsg *Controller::generateMessage(char content, int destination, int tcp_type)
//{
//    // Produce Source_num and destination addresses.
//    int src = getIndex();  // our module index
//    int n = getVectorSize();  // module vector size
//    int dest = destination;
//
//    char msgname[20];
//    sprintf(msgname, "Request");
//
//    // Create message object and set Source_num and destination field.
//    ContentMsg *msg = new ContentMsg(msgname);
//    msg->setSource_num(src);
//    msg->setDestination(dest);
//    msg->setContent(content);
//
//    if (content == 't') {
//        msg->setTcp_type(tcp_type);
//    }
//
//    return msg;
//}
//
