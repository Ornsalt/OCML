#pragma once

#include "ocml.h"

typedef struct osFont_s {
    sfFont  *core;
    size_t   size;
    sfUint32 style;
} Font_t;

Font_t *setFont(char *path, size_t size, sfUint32 style);
void unsetFont(Font_t *font);

typedef struct osText_s {
    sfText *core;
} Text_t;

Text_t *setText(Font_t *font, char *string, sfColor color);
void unsetText(Text_t *text);