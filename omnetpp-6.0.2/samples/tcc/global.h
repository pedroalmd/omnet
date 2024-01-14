#ifndef MY_GLOBALS_H
#define MY_GLOBALS_H

// This is a declaration of your variable, which tells the linker this value
// is found elsewhere.  Anyone who wishes to use it must include global.h,
// either directly or indirectly.

extern int contents_has[5];
extern int contents_wants[5];
//extern int content_chunks[5][10];

extern int amount_serving[5];

extern double dead_timeout;


extern double peer_dying_time[5];

#endif
