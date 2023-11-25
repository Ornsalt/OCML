#pragma once

#include "ocml.h"

typedef struct OsClock_s {
    sfClock *core;
    double reset;
    double delta;
} Clock_t;

Clock_t *setClock(double reset);
void unsetClock(Clock_t *clock);
void resetClock(Clock_t *clock, double reset);
size_t updateClock(Clock_t *clock);

typedef struct OsWindowIni {
    sfVideoMode mode;
    char *title;
    sfUint32 style;
    short fps;
    sfBool vsync;
    sfBool key;
    sfBool grab;
    sfBool visible;
    sfBool hide;
    char *icon;
} WdIni_t;

typedef struct OsWindow_s {
    sfRenderWindow *core;
    Clock_t *clock;
    sfEvent event;
} Window_t;

Window_t *setWindow(WdIni_t *conf);
void screenshot(Window_t *wd, char *path);
void unsetWindow(Window_t *wd);