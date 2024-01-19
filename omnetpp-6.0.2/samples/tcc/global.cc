#include "global.h"
#include <omnetpp.h>


// This is the definition of your variable.  It can only happen in one place.
// You must include global.h so that the compiler matches it to the correct
// one, and doesn't implicitly convert it to static.


#if PEER_AMOUNT == 5
    int amount_serving[PEER_AMOUNT] = {0, 0, 0, 0, 0};

    int contents_wants[PEER_AMOUNT] = {'d', 'c', 'd', 'e', 'e'};
    int contents_has[PEER_AMOUNT] =   {'a', 'b', 'c', 'd', 'd'};

    double peer_dying_time[PEER_AMOUNT] = {0, 0, 0, 5, 40};

#elif PEER_AMOUNT == 10
    int amount_serving[PEER_AMOUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int contents_wants[PEER_AMOUNT] = {'c', 'd', 'd', 'b', 'b', 'e', 'b', 'd', 'a', 'c'};
    int contents_has[PEER_AMOUNT] =   {'e', 'd', 'a', 'a', 'b', 'a', 'c', 'd', 'd', 'b'};

    double peer_dying_time[PEER_AMOUNT] = {0, 58, 0, 0, 0, 27, 0, 0, 0, 40};

#elif PEER_AMOUNT == 50
    int amount_serving[PEER_AMOUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int contents_wants[PEER_AMOUNT] = {'d', 'c', 'd', 'd', 'd', 'a', 'd', 'a', 'a', 'c', 'e', 'c', 'c', 'e', 'c', 'c', 'c', 'e', 'e', 'c', 'e', 'c', 'c', 'a', 'b', 'c', 'e', 'c', 'e', 'a', 'c', 'c', 'b', 'a', 'a', 'c', 'a', 'e', 'a', 'b', 'b', 'c', 'e', 'b', 'a', 'a', 'a', 'c', 'd', 'b'};
    int contents_has[PEER_AMOUNT] =   {'b', 'b', 'a', 'a', 'e', 'b', 'c', 'c', 'b', 'b', 'c', 'e', 'e', 'a', 'c', 'c', 'd', 'e', 'b', 'c', 'd', 'c', 'c', 'e', 'c', 'c', 'b', 'e', 'b', 'a', 'e', 'b', 'c', 'd', 'e', 'e', 'd', 'a', 'a', 'c', 'e', 'a', 'a', 'd', 'c', 'e', 'c', 'd', 'a', 'c'};

    double peer_dying_time[PEER_AMOUNT] = {0, 0, 0, 0, 9, 0, 0, 51, 50, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 55, 0, 0, 0, 0, 13, 12, 45, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 40, 6, 0, 0, 0, 0, 0, 25, 0};

#elif PEER_AMOUNT == 100
    int amount_serving[PEER_AMOUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int contents_wants[PEER_AMOUNT] = {'d', 'e', 'b', 'c', 'a', 'c', 'a', 'd', 'a', 'd', 'c', 'a', 'd', 'b', 'e', 'b', 'd', 'd', 'a', 'c', 'e', 'c', 'b', 'e', 'e', 'a', 'c', 'd', 'a', 'c', 'a', 'd', 'e', 'e', 'b', 'e', 'e', 'a', 'e', 'b', 'd', 'b', 'e', 'e', 'd', 'b', 'b', 'b', 'a', 'a', 'c', 'c', 'c', 'e', 'd', 'd', 'e', 'd', 'c', 'b', 'a', 'b', 'e', 'a', 'e', 'c', 'b', 'b', 'e', 'c', 'b', 'e', 'd', 'c', 'c', 'e', 'e', 'c', 'e', 'a', 'd', 'a', 'c', 'e', 'd', 'e', 'a', 'd', 'c', 'a', 'd', 'e', 'a', 'd', 'a', 'c', 'e', 'c', 'c', 'c'};
    int contents_has[PEER_AMOUNT] = {'a', 'e', 'd', 'c', 'a', 'e', 'b', 'a', 'd', 'e', 'c', 'd', 'c', 'e', 'b', 'd', 'b', 'e', 'e', 'a', 'a', 'a', 'b', 'a', 'b', 'a', 'c', 'b', 'd', 'd', 'b', 'b', 'c', 'b', 'd', 'e', 'd', 'b', 'e', 'e', 'e', 'd', 'a', 'd', 'c', 'e', 'e', 'c', 'e', 'a', 'a', 'a', 'e', 'c', 'e', 'e', 'a', 'c', 'a', 'b', 'c', 'c', 'a', 'c', 'b', 'd', 'e', 'e', 'c', 'c', 'c', 'a', 'c', 'd', 'b', 'a', 'b', 'b', 'e', 'b', 'a', 'b', 'd', 'b', 'c', 'c', 'c', 'c', 'a', 'd', 'd', 'e', 'e', 'a', 'd', 'c', 'e', 'a', 'd', 'a'};

    double peer_dying_time[PEER_AMOUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 11, 0, 32, 0, 0, 0, 34, 0, 0, 0, 29, 52, 38, 0, 0, 32, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 36, 31, 0, 0, 32, 22, 58, 0, 57, 8, 60, 0, 53, 0, 23, 0, 0, 0, 0, 5, 0, 0, 0, 15, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 15, 46, 6, 56, 26, 0, 0, 0};
#endif

int ex_peer_amount = PEER_AMOUNT;
//int content_chunks[PEER_AMOUNT][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

double dead_timeout = 0.5;

double chunk_video_time = 0.5;

// Stats variables


