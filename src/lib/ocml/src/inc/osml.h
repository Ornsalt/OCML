#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>

clock_t setClock(short reset);
void unsetClock(clock_t *clock);
void resetClock(clock_t *clock, float reset);
bool updateClock(clock_t *clock);