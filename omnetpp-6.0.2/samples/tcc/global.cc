#include "global.h"

// This is the definition of your variable.  It can only happen in one place.
// You must include global.h so that the compiler matches it to the correct
// one, and doesn't implicitly convert it to static.
int contents_has[5] = {'a', 'b', 'c', 'd', 'd'};
int contents_wants[5] = {'d', 'c', 'd', 'e', 'e'};

double peer_dying_time[5] = {0, 0, 0, 0.5, 0};

int peer_has[4];
int peer_wants[4];
