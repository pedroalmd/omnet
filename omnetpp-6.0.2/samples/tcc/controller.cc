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
#include "contentO.h"
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
class Controller : public cSimpleModule
{
  protected:

    int myNum = 0;
    int count = 0;

    contentO video;
    int alive_peers[PEER_AMOUNT];
    int amount_serving_peers[PEER_AMOUNT];

    omnetpp::simtime_t c_average_chunk_arr[PEER_AMOUNT];
    omnetpp::simtime_t c_finish_dwnl_time[PEER_AMOUNT];
    omnetpp::simtime_t c_total_stall_time[PEER_AMOUNT];
    int c_stall_count_size[PEER_AMOUNT];

    omnetpp::simtime_t mean_average_chunk_arr = 0;
    omnetpp::simtime_t mean_finish_dwnl_time = 0;
    omnetpp::simtime_t mean_total_stall_time = 0;
    int mean_stall_count_size = 0;

    std::map<int, char> table;


    virtual ContentMsg *generateMessage(char content, int destination, int tcp_type = 0);
    virtual void initialize() override;
    virtual void finish() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual int getServer(char content, std::map<int, char> table);
    virtual void calculateMeans();

};

Define_Module(Controller);

void Controller::initialize()
{
    int network_size = sizeof(contents_has) / sizeof(int);

    for (int i = 0; i < network_size; i++) {
        alive_peers[i] = 1;
        table[i] = contents_has[i];
        amount_serving_peers[i] = amount_serving[i];
    }
}

void Controller::handleMessage(cMessage *msg)
{
    ContentMsg *ttmsg = check_and_cast<ContentMsg *>(msg);

    char request = 'r';
    char dead = 'd';
    char stat = 'x';

    if (ttmsg->getType() == stat) {
        c_average_chunk_arr[count] = ttmsg->getC_average_chunk_arr();
        c_finish_dwnl_time[count] = ttmsg->getC_finish_dwnl_time();
        c_total_stall_time[count] = ttmsg->getC_total_stall_time();
        c_stall_count_size[count] = ttmsg->getC_stall_count_size();
        count++;
    }


    if (ttmsg->getType() == request) {
        int server = getServer(ttmsg->getContent(), table);
        ttmsg->setDestination(server);

        if (ttmsg->getDestination() != 2222) {
            amount_serving_peers[ttmsg->getDestination()]++;
//            EV << ttmsg->getDestination() << "AAAA" << amount_serving_peers[ttmsg->getDestination()]<< "\n";
            send(ttmsg, "switch_gate$o", 0);

        }
    }
    else if (ttmsg->getType() == dead) {
        alive_peers[ttmsg->getSource_num()] = 0;
        EV << "Peer " << ttmsg->getSource_num() << " is dead" << "\n";
        ttmsg->setType('e');

        send(ttmsg, "switch_gate$o", 0);
    }
}

ContentMsg *Controller::generateMessage(char content, int destination, int tcp_type)
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

int Controller::getServer(char content, std::map<int, char>  table)
{
    int server = 2223;

    for (auto itr = table.begin(); itr != table.end(); ++itr) {
//       EV << itr->first << ": " << itr->second << endl << "\n";

       if (itr->second == content && alive_peers[itr->first] == 1) {

           if (server == 2223) {
               server = itr->first;
           }

           else if (amount_serving_peers[itr->first] < amount_serving_peers[server]) {
               server = itr->first;
           }

       }
    }

    return server;
}


void Controller::calculateMeans()
{
    for(int i = 0; i < count; i++) {
        mean_average_chunk_arr += c_average_chunk_arr[i];
        mean_finish_dwnl_time += c_finish_dwnl_time[i];
        mean_total_stall_time += c_total_stall_time[i];
        mean_stall_count_size += c_stall_count_size[i];
    }

    mean_average_chunk_arr = mean_average_chunk_arr / count;
    mean_finish_dwnl_time = mean_finish_dwnl_time / count;
    mean_total_stall_time = mean_total_stall_time / count;
    mean_stall_count_size = mean_stall_count_size / count;

}

void Controller::finish()
{
//    for(int i = 0; i < PEER_AMOUNT; i++) {
//        EV << "Peer " << i << "\n";
//        EV << "c_average_chunk_arr " << c_average_chunk_arr[i] << "\n";
//        EV << "c_finish_dwnl_time " <<  c_finish_dwnl_time[i] << "\n";
//        EV << "c_total_stall_time " << c_total_stall_time[i] << "\n";
//        EV << "c_stall_count_size " << c_stall_count_size[i] << "\n";
//    }

    calculateMeans();
    EV << "mean_average_chunk_arr " << mean_average_chunk_arr << "\n";
    EV << "mean_finish_dwnl_time " <<  mean_finish_dwnl_time << "\n";
//    EV << "mean_total_stall_time " << mean_total_stall_time << "\n";
    EV << "mean_stall_count_size " << mean_stall_count_size << "\n";
    EV << "mean_total_stall_amount_per_second " << mean_stall_count_size / mean_finish_dwnl_time << "\n";
}



