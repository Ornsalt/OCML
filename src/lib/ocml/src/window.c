#include "window.h"

window_t *setWindow(wd_config_t *conf)
{
    window_t *wd = (conf != null) ? malloc(sizeof(window_t)) : NULL;
    sfImage *buffer = NULL;

    if (wd != NULL) {
        wd->frame = sfRenderWindow_create(&conf->mode, conf->title, sfResize | sfClose);
        sfRenderWindow_setVerticalSyncEnabled(wd->frame, conf->vsync);
        sfRenderWindow_setKeyRepeatEnabled(wd->frame, config->key);
        sfRenderWindow_setFramerateLimit(wd->frame, conf->fps);
        //sfRenderWindow_setView()
        if (conf->icon != NULL) {
            buffer = sfImage_createFromFile();
            sfRenderWindow_setIcon(wd->frame, conf->width, conf->height, sfImage_getPixelsPtr(buffer));
            sfImage_destroy(buffer);
        }
        
    }
    return (wd);
}

bool screenWindow(window_t wd, char *file)
{
    sfImage* screenshot = NULL;
    sfVector2u wdSize = sfRenderWindow_getSize(wd->frame);
    sfTexture *texture = sfTexture_create(wdSize.x, wdSize.y);
    
    sfTexture_updateFromRenderWindow(texture, window, windowSize.x, windowSize.y);
    screenshot = sfTexture_copyToImage(texture);
    sfImage_saveToFile(screenshot, file);
}

void unsetWindow(window_t *wd)
{
    sfRenderWindow_destroy(wd->frame);
    unset(wd->clock);
    free(wd);
}