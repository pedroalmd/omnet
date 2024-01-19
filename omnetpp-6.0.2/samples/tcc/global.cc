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
#elif PEER_AMOUNT == 50
    int amount_serving[PEER_AMOUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int contents_wants[PEER_AMOUNT] = {'d', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e'};
    int contents_has[PEER_AMOUNT] =   {'a', 'b', 'c', 'd', 'd', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e'};

    double peer_dying_time[PEER_AMOUNT] = {0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, };
#endif



//int content_chunks[PEER_AMOUNT][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

double dead_timeout = 0.5;

double chunk_video_time = 0.5;

// Stats variables


