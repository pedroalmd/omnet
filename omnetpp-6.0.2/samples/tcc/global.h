#ifndef MY_GLOBALS_H
#define MY_GLOBALS_H

// This is a declaration of your variable, which tells the linker this value
// is found elsewhere.  Anyone who wishes to use it must include global.h,
// either directly or indirectly.

extern int contents_has[5];
extern int contents_wants[5];

extern double peer_dying_time[5];

extern int peer_has[4];
extern int peer_wants[4];

#endif
