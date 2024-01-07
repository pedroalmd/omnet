#include "global.h"

// This is the definition of your variable.  It can only happen in one place.
// You must include global.h so that the compiler matches it to the correct
// one, and doesn't implicitly convert it to static.
int contents_wants[5] = {'d', 'c', 'd', 'e', 'e'};
int contents_has[5] =   {'a', 'b', 'c', 'f', 'd'};
int amount_serving[5] = {0, 0, 0, 0, 0};

double dead_timeout = 0.5;


double peer_dying_time[5] = {0, 0, 0, 0, 0};
