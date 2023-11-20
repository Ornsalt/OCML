#include "ocml.h"

Clock_t *setClock(double reset)
{
    Clock_t *clock = malloc(sizeof(Clock_t));

    if (clock) {
        clock->core = sfClock_create();
        clock->reset = reset;
        clock->delta = 0.0;
    }
    return (clock);
}

void unsetClock(Clock_t *clock)
{
    sfClock_destroy(clock->core);
    free(clock);
}

void resetClock(Clock_t *clock, double reset)
{
    clock->reset = reset;
    clock->delta = 0;
    sfClock_restart(clock->core);
}

size_t updateClock(Clock_t *clock)
{
    size_t frame = 0;

    clock->delta += sfTime_asSeconds(sfClock_restart(clock->core));
    for (frame = 0; clock->delta >= clock->reset; frame++)
        clock->delta -= clock->reset;
    return (frame);
}