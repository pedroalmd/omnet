#ifndef MY_GLOBALS_H
#define MY_GLOBALS_H

#define PEER_AMOUNT 50

#define MIN_PERCENTAGE_STATISTICS 0

// This is a declaration of your variable, which tells the linker this value
// is found elsewhere.  Anyone who wishes to use it must include global.h,
// either directly or indirectly.

extern int ex_peer_amount;

extern int contents_has[PEER_AMOUNT];
extern int contents_wants[PEER_AMOUNT];

extern int amount_serving[PEER_AMOUNT];
extern double peer_dying_time[PEER_AMOUNT];


extern double dead_timeout;

extern double chunk_video_time;


#endif

//extern int content_chunks[5][10];
