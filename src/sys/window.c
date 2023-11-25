#include "ocml.h"

/**
 * \brief   Create a instance of the Window_t Object.
 * \param   conf the parameters to setup the Window_t Object.
 * \return  Window_t Object.
 */
Window_t *setWindow(WdIni_t *conf)
{
    Window_t *wd = (conf) ? malloc(sizeof(Window_t)) : NULL;
    sfImage *icon = (wd && conf->icon) ? sfImage_createFromFile(conf->icon) : NULL;
    v2u_t iconSize = (icon) ? sfImage_getSize(icon) : (v2u_t){0, 0};

    if (wd) {
        wd->core = sfRenderWindow_create(conf->mode, conf->title, conf->style, NULL);
        sfRenderWindow_setFramerateLimit(wd->core, conf->fps);
        sfRenderWindow_setVerticalSyncEnabled(wd->core, conf->vsync);
        sfRenderWindow_setKeyRepeatEnabled(wd->core, conf->key);
        sfRenderWindow_setMouseCursorGrabbed(wd->core, conf->grab);
        sfRenderWindow_setMouseCursorVisible(wd->core, conf->visible);
        sfRenderWindow_setVisible(wd->core, conf->hide);
        //sfRenderWindow_setView();
        if (icon) {
            sfRenderWindow_setIcon(wd->core, iconSize.x, iconSize.y, sfImage_getPixelsPtr(icon));
            sfImage_destroy(icon);
        }
        wd->clock = setClock((double) 1 / conf->fps);
    }
    return (wd);
}

/**
 * \brief   Take a screenshote of the current window.
 * \param   wd the window to take a screenshot from.
 * \param   path the path to the file it will be saved has (name and extension included).
 */
void screenshot(Window_t *wd, char *path)
{
    v2u_t wdSize = (wd) ? sfRenderWindow_getSize(wd->core) : (v2u_t){0, 0};
    sfTexture *texture = (wd) ? sfTexture_create(wdSize.x, wdSize.y) : NULL;
    sfImage* screenshot = NULL;
    
    if (texture && path) {
        sfTexture_updateFromRenderWindow(texture, wd->core, wdSize.x, wdSize.y);
        screenshot = sfTexture_copyToImage(texture);
        sfImage_saveToFile(screenshot, path);
        sfImage_destroy(screenshot);
        sfTexture_destroy(texture);
    }
}

/**
 * \brief   Clear the memory taken by the Window_t Object.
 * \param   wd the element to free.
 */
void unsetWindow(Window_t *wd)
{
    if (wd) {
        sfRenderWindow_destroy(wd->core);
        unsetClock(wd->clock);
        free(wd);
    }
}