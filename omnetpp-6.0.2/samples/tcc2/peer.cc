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
  private:
    // Statistics variables

    omnetpp::simtime_t finish_dwnl_time;
    omnetpp::simtime_t partial_chunk_arr_time = 0;
    omnetpp::simtime_t last_chunk_arr_time = 0;
    omnetpp::simtime_t average_chunk_arr = 0;
    std::vector<int> stall_count = {};

    omnetpp::simtime_t total_stall_time = 0;
    omnetpp::simtime_t first_stall_time = 0;
    int chunk_index_stall = 2222;

    int next_chunk = 0; // Video starts when second chunk arrives;

    int stop_flag = 0;

    //

    int main_tcp_with = 5555;
    int spare_tcp_with = 5555;

    long a_chunks_received;

    long percentage = 0;

    cHistogram hopCountStats;
    cOutVector hopCountVector;

  protected:

    contentO video_has;
    contentO video_wants;

    int index;
    std::vector<int> serving_peers = {};
    int is_Alive = 1;

    virtual ContentMsg *generateMessage(char type, char content, int destination = 2222, int tcp_type = 0, int chunk = 0);
    virtual ContentMsg *generateStatMessage(char type, omnetpp::simtime_t c_average_chunk_arr, omnetpp::simtime_t c_finish_dwnl_time, omnetpp::simtime_t c_total_stall_time, int c_stall_count_size);
    virtual ContentMsg *generateDeadSelfMessage(char type);
    virtual void handleTcpMessage(ContentMsg *ttmsg);
    virtual void handleRequestMessage(ContentMsg *ttmsg);
    virtual void handleContentMessage(ContentMsg *ttmsg);
    virtual void handleVideoMessage(ContentMsg *ttmsg);
    virtual void sendDeadResponseMessage();
    virtual void appendToServingPeers(int element);
    virtual void appendToStallCount(int element);
    virtual int isInArray(int element, std::vector<int> v);
    virtual void eraseFromServingPeers(int element);
    virtual int getElementIndexInVector(int element, std::vector<int> v);
    virtual void printServingPeers();
    virtual int getNextChunk(int starting_index = 0);
    virtual void printChunk();
    virtual void setAverageChunkTime();
    virtual int getServer();
    virtual int getMainServing();
    virtual void beforeFinishing();
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void sendUnknownRequest();
    virtual void finish() override;
};

Define_Module(Peer);


void Peer::initialize()
{
    index = getIndex();

    if (peer_dying_time[index] != 0) {
        ContentMsg *d_msg = generateMessage('f', '0', index, 0); // r = request (comes from Peer)
        scheduleAt(peer_dying_time[index], d_msg);
    }

    a_chunks_received = 0;

    hopCountStats.setName("hopCountStats");
//    hopCountStats.setRangeAutoUpper(0, 10, 1.5);
    hopCountVector.setName("HopCount");


    video_has.setName(contents_has[index]);
    video_wants.setName(contents_wants[index]);

    ContentMsg *msg = generateMessage('r', video_wants.getName(), 2222, 0); // r = request (comes from Peer)
    send(msg, "gate$o", 0); // 0 is always the switch
}


void Peer::handleMessage(cMessage *msg)
{
    ContentMsg *ttmsg = check_and_cast<ContentMsg *>(msg);

    char tcp = 't';
    char request = 'r';
    char content = 'c';
    char dead = 'd';
    char video = 'v';
    char self_dead = 'f';

    printServingPeers();

    if (is_Alive == 0) {

        return;
    }


    if (ttmsg->getDestination() == 2223) {
        stop_flag = 1;
        beforeFinishing();

        return;
    }

    if (ttmsg->getDestination() == getIndex()) {
        // Message arrived.
        EV << "Message " << ttmsg->getType() << " arrived from peer " << ttmsg->getSource_num() << "\n";
    }

//    if (peer_dying_time[index] != 0 && simTime() >= peer_dying_time[index]) {
//        is_Alive = 0;
//        cDisplayString& dispStr = getDisplayString();
//        dispStr.setTagArg("i", 1, "red");
//        beforeFinishing();
//    }
//


    if (ttmsg->getType() == tcp) {
        handleTcpMessage(ttmsg);
    }

    else if (ttmsg->getType() == content) {
        handleContentMessage(ttmsg);
    }

    else if (ttmsg->getType() == self_dead) {
        is_Alive = 0;
        cDisplayString& dispStr = getDisplayString();
        dispStr.setTagArg("i", 1, "red");
        beforeFinishing();
        sendDeadResponseMessage();
    }

    else if (ttmsg->getType() == video) {
        handleVideoMessage(ttmsg);
    }

    else if (ttmsg->getType() == request) {
        handleRequestMessage(ttmsg);
    }

    else if (ttmsg->getType() == dead) {

        if (ttmsg->getSource_num() == spare_tcp_with) {
            spare_tcp_with = 5555;
            sendUnknownRequest();
            return;
        }

        if (spare_tcp_with == 5555) {
            main_tcp_with = 5555;
            sendUnknownRequest();
        }
        else if (spare_tcp_with != 5555) {
            main_tcp_with = spare_tcp_with;
            spare_tcp_with = 5555;

            EV << "Sending first request!\n";

            ContentMsg *cmsg = generateMessage('r', video_wants.getName(), main_tcp_with, 4, getNextChunk()); // r = request (comes from Peer)
            send(cmsg, "gate$o", 0); // 0 is always the switch

            sendUnknownRequest();

        }
    }
}


ContentMsg *Peer::generateMessage(char type, char content, int destination, int tcp_type, int chunk)
{
    // Produce Source_num and destination addresses.
    int src = getIndex();  // our module index

    char msgname[20];
    sprintf(msgname, "Request");

    // Create message object and set Source_num and destination field.
    ContentMsg *msg = new ContentMsg(msgname);

    msg->setSource_num(src);
    msg->setDestination(destination);
    msg->setType(type);
    msg->setContent(content);
    msg->setTcp_type(tcp_type);
    msg->setChunk(chunk);

    return msg;
}


ContentMsg *Peer::generateStatMessage(char type, omnetpp::simtime_t c_average_chunk_arr, omnetpp::simtime_t c_finish_dwnl_time, omnetpp::simtime_t c_total_stall_time, int c_stall_count_size)
{
    // Produce Source_num and destination addresses.
    int src = getIndex();  // our module index

    char msgname[20];
    sprintf(msgname, "Request");

    // Create message object and set Source_num and destination field.
    ContentMsg *msg = new ContentMsg(msgname);

    msg->setSource_num(src);
    msg->setType(type);
    msg->setC_average_chunk_arr(c_average_chunk_arr);
    msg->setC_finish_dwnl_time(c_finish_dwnl_time);
    msg->setC_total_stall_time(c_total_stall_time);
    msg->setC_stall_count_size(c_stall_count_size);

    return msg;
}


ContentMsg *Peer::generateDeadSelfMessage(char type)
{
    // Produce Source_num and destination addresses.
    int src = getIndex();  // our module index

    char msgname[20];
    sprintf(msgname, "Request");

    // Create message object and set Source_num and destination field.
    ContentMsg *msg = new ContentMsg(msgname);

    msg->setSource_num(src);
    msg->setType(type);

    for(int i = 0; i < serving_peers.size(); i++) {
        peers_serving[index][i] = serving_peers[i];
    }
    return msg;
}


void Peer::handleTcpMessage(ContentMsg *ttmsg)
{

    if (ttmsg->getTcp_type() == 0) {
        if (main_tcp_with != 5555) {
            if (main_tcp_with == ttmsg->getSource_num()) {
                EV << "No spare peers available \n";
                return;
            }
        }

//        if (main_tcp_with != 5555) {
//            if (main_tcp_with != ttmsg->getSource_num()) {
//                spare_tcp_with = ttmsg->getSource_num();
//                EV << "Main TCP with: " << main_tcp_with << "\n";
//                EV << "Spare TCP with: " << spare_tcp_with << "\n";
//            } else {
//                EV << "No spare peers available \n";
//                return;
//            }
//        }

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


        if (main_tcp_with != 5555) { // nao tem main
            spare_tcp_with =  ttmsg->getSource_num();

            EV << "Main TCP with: " << main_tcp_with << "\n";
            EV << "Spare TCP with: " << spare_tcp_with << "\n";
            return;
        }

        main_tcp_with =  ttmsg->getSource_num();
        EV << "Main TCP with: " << main_tcp_with << "\n";
        peer_main_tcp[index] = main_tcp_with;

        sendUnknownRequest();

        EV << "Sending first request!\n";

        ContentMsg *cmsg = generateMessage('r', video_wants.getName(), main_tcp_with, 4, getNextChunk()); // r = request (comes from Peer)
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
//        double delay_time = std::pow(2, (serving_peers.size() - 1)) / 10; // evertime a peer joins, it takes double the time to respond o the request
        double delay_time = std::pow(2, (getMainServing() - 1)) / 10; // evertime a peer joins, it takes double the time to respond o the request

        EV << "Sending back content!\n";
        ContentMsg *msg = generateMessage('c', video_has.getName(), ttmsg->getSource_num(), 4, ttmsg->getChunk()); // r = request (comes from Peer)
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
    EV << "Received chunk " << ttmsg->getChunk() << "\n";
    video_wants.setChunk(ttmsg->getChunk(), 1);

    partial_chunk_arr_time = simTime() - last_chunk_arr_time;
    last_chunk_arr_time = simTime();

    video_wants.setChunkTime(ttmsg->getChunk(), partial_chunk_arr_time);

    printChunk();

    if (ttmsg->getChunk() == chunk_index_stall) {
        total_stall_time += (simTime() - first_stall_time);

        EV << "Total stall time: " << total_stall_time << " seconds. \n";

    }

    if (percentage >= 100) {
        beforeFinishing();

        return;
    }

    // First self Message

    if (ttmsg->getChunk() == 0) {
        ContentMsg *self_msg = generateMessage('v', 0, index, getNextChunk(), next_chunk); // r = request (comes from Peer)
        scheduleAt(simTime() + chunk_video_time, self_msg);
    }

    EV << "Sending next request!\n";

    // Get next chunk

    ContentMsg *msg = generateMessage('r', video_wants.getName(), ttmsg->getSource_num(), 4, getNextChunk()); // r = request (comes from Peer)
    send(msg, "gate$o", 0); // 0 is always the switch
}


void Peer::handleVideoMessage(ContentMsg *ttmsg)
{
    if (stop_flag == 1) {
        return;
    }

    int search_chunk = ttmsg->getChunk();


    if (video_wants.getChunk(search_chunk) == 0) {
        EV << "Checking Chunk: " << next_chunk << " stalled \n";

        if (chunk_index_stall != next_chunk) {
            first_stall_time = simTime();
        }

        appendToStallCount(next_chunk);
        chunk_index_stall = next_chunk;
    }
    else {
        EV << "Checking Chunk: " << next_chunk << " OK \n";
        next_chunk++;
    }

    if (getNextChunk() >= 100) {
        return;

    }
    ContentMsg *self_msg = generateMessage('v', 0, index, getNextChunk(), next_chunk); // r = request (comes from Peer)

    scheduleAt(simTime() + chunk_video_time, self_msg);
}



void Peer::sendDeadResponseMessage()
{
    EV << "[ME] Peer " << getIndex() << " left!\n";

    printServingPeers();

    ContentMsg *msg = generateDeadSelfMessage('d'); // r = request (comes from Peer)
    send(msg, "gate$o", 0); // 0 is always the switch
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


void Peer::appendToStallCount(int element)
{
    if (isInArray(element, stall_count) == 0) {
        stall_count.push_back(element);
    }
}


int Peer::getElementIndexInVector(int element, std::vector<int> v)
{
    for(int i = 0; i < v.size(); i++) {
       if (element == v[i]) {
           return i;
       }
    }

    return 2222;
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


int Peer::getNextChunk(int starting_index)
{

    int c = 2222;

    for (int index = starting_index;; index++) {
        c = video_wants.getChunk(index);
        if (c == 0) {
            return index;
        }
    }

    return 2222;
}


void Peer::printChunk()
{
    long tmp_percentage = 0;

    EV << "|";
    for(int i = 0; i < 100; i++) {
        if (video_wants.getChunk(i) == 1) {
            EV << "x";
            tmp_percentage++;
        }
        EV << " ";
    }

    EV << "|\n";
    EV << "Peer " << index << ": " << tmp_percentage << "% \n";

    percentage = tmp_percentage;

    char buf[40];
    sprintf(buf, "Download Per: %ld", tmp_percentage);
    getDisplayString().setTagArg("t", 0, buf);

    a_chunks_received++;

    hopCountVector.record(tmp_percentage);
    hopCountStats.collect(tmp_percentage);
}


void Peer::setAverageChunkTime()
{
    omnetpp::simtime_t c_time = 0;

    if (percentage == 0) {
        average_chunk_arr = 0;
        return;
    }

    for(int i = 0; i < percentage; i++) {
        c_time += video_wants.getChunkTime(i);
    }

    average_chunk_arr = c_time / percentage;
}


int Peer::getServer()
{
    return 0;
}


void Peer::beforeFinishing() {
    setAverageChunkTime();

    if (percentage != 100) {
        finish_dwnl_time = average_chunk_arr * 100;
    } else {
        finish_dwnl_time = simTime();
    }

    if (percentage >= MIN_PERCENTAGE_STATISTICS) {
        ContentMsg *msg = generateStatMessage('x', average_chunk_arr, finish_dwnl_time, total_stall_time, stall_count.size());
        send(msg, "gate$o", 0);
    }
}


void Peer::sendUnknownRequest() {
    EV << "Sending unknown destination request!\n";

    ContentMsg *msg = generateMessage('r', video_wants.getName(), 2222, 0);
    send(msg, "gate$o", 0); // 0 is always the switch
}


int Peer::getMainServing()
{
    int main_serving_amount = 0;

    for(int i = 0; i < PEER_AMOUNT; i++) {
        if (peer_main_tcp[i] == index) {
            main_serving_amount++;
        }
    }

    return main_serving_amount;
}


void Peer::finish()
{
    EV << "---------- " << index << " ----------\n";
    EV << "Finished downloading in " << finish_dwnl_time << " seconds. \n";
    EV << "Total downloaded is: " << percentage << "% \n";
    EV << "Average chunk arrival time is: " << average_chunk_arr << " seconds. \n" ;
    EV << "Total stall time: " << total_stall_time << " seconds. \n";
    EV << "Total Stall count " << stall_count.size() << "\n";

}

