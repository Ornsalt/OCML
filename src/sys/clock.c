#include "ocml.h"

/**
 * \brief   Create a instance of the Clock_t Object.
 * \param   reset the value a witch a clock refresh.
 * \return  Clock_t Object.
 */
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

/**
 * \brief   Clear the memory taken by the Clock_t Object.
 * \param   clock the element to free.
 */
void unsetClock(Clock_t *clock)
{
    sfClock_destroy(clock->core);
    free(clock);
}

/**
 * \brief   reset an instance of the Clock_t Object.
 * \param   clock the clock to reset.
 * \param   reset the value a witch a clock refresh.
 */
void resetClock(Clock_t *clock, double reset)
{
    clock->reset = reset;
    clock->delta = 0;
    sfClock_restart(clock->core);
}

/**
 * \brief   Get how much time have elapsed since the last call.
 * \param   clock the clock to update.
 * \return  size_t, the frame that have elapsed since the last call.
 */
size_t updateClock(Clock_t *clock)
{
    size_t frame = 0;

    clock->delta += sfTime_asSeconds(sfClock_restart(clock->core));
    for (frame = 0; clock->delta >= clock->reset; frame++)
        clock->delta -= clock->reset;
    return (frame);
}