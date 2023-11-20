#include "ocml.h"

Font_t *setFont(char *path, size_t size, sfUint32 style)
{
    Font_t *font = malloc(sizeof(Font_t));

    if (font) {
        font->core = sfFont_createFromFile(path);
        font->size = size;
        font->style = style;
    }
    return (font);
}

void unsetFont(Font_t *font)
{
    if (font) {
        sfFont_destroy(font->core);
        free(font);
    }
}

Text_t *setText(Font_t *font, char *string, sfColor color)
{
    Text_t *text = malloc(sizeof(Text_t));

    if (text && font && text) {
        text->core = sfText_create();
        sfText_setFont(text->core, font->core);
        sfText_setString(text->core, string);
        sfText_setCharacterSize(text->core, font->size);
        sfText_setStyle(text->core, font->size);
        sfText_setColor(text->core, color);
        //sfText_setPosition(text->core, coord);
    }
    return (text);
}

void unsetText(Text_t *text)
{
    if (text) {
        sfText_destroy(text->core);
        free(text);
    }
}