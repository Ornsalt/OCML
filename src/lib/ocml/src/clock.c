#include "clock.h"

clock_t setClock(short reset)
{
    clock_t *clock = malloc(sizeof(clock_t));

    if (clock) {
        clock->core = sfClock_create();
        clock->reset = reset;
        clock->delta = 0;
    }
    return (clock);
}

void unsetClock(clock_t *clock)
{
    sfClock_Destroy(clock->core);
    free(clock);
}

void resetClock(clock_t *clock, float reset)
{
    clock->reset = 0;
    clock->delta = 0;
    sfClock_restart(clock->core);
}

bool updateClock(clock_t *clock)
{
    clock->delta += sfTime_asSeconds(sfClock_restart(clock->core));
    if (clock->delta >= clock->reset)
        clock->delta -= clock->reset;
    return (clock->delta != 0)
}