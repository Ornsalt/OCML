#pragma once

#include "osml.h"

typedef struct OsClock {
    sfClock *core;
    float reset;
    float delta;
} clock_t;