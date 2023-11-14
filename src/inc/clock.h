#pragma once

typedef struct OsClock_s {
    sfClock *core;
    float reset;
    float delta;
} Clock_t;

Clock_t *setClock(short reset);
void unsetClock(Clock_t *clock);
void resetClock(Clock_t *clock, float reset);
size_t updateClock(Clock_t *clock);