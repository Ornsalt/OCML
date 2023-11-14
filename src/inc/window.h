#pragma once

#include "ocml.h"

typedef struct OsWindowIni {
    char *title;
    sfVideoMode mode;
    sfBool vsync;
    sfBool key;
    sfBool grab;
    sfBool visible;
    sfBool hide;
    short fps;
    char *icon;
} WdIni_t;

typedef struct OsWindow_s {
    sfRenderWindow *core;
    Clock_t *clock;
} Window_t;

Window_t *setWindow(WdIni_t *conf);
void screenshot(Window_t *wd, char *file);
void unsetWindow(Window_t *wd);