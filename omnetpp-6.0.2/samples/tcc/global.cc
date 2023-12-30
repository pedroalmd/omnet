#include "global.h"

// This is the definition of your variable.  It can only happen in one place.
// You must include global.h so that the compiler matches it to the correct
// one, and doesn't implicitly convert it to static.
int contents_has[4] = {'a', 'b', 'c', 'd'};
int contents_wants[4] = {'b', 'c', 'd', 'e'};

double peer_dying_time[4] = {0, 0.5, 0, 0};

int peer_has[4];
int peer_wants[4];
