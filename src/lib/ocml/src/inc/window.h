#pragma once

#include "osml.h"

typedef struct OsWindowConf {
    char *title;
    sfVideoMode *mode;
    sfBool vsync;
    sfBool key;
    short fps;
    wd_icon_t *icon;
} wd_config_t;

typedef struct OsWindowIcon {

} wd_icon_t;

typedef struct OsWindow {
    sfRenderWindow *frame;
    clock_t *clock;
} window_t;
