#include "ocml.h"

/**
 * \brief   Create an instance of the Font_t Object.
 * \param   path the path to the file of the font.
 * \param   size the size in pixel of the font.
 * \param   style the style (bold,...) of the font.
 */
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

/**
 * \brief   Clear the memory taken by the Text_t Object.
 * \param   font the element to free.
 */
void unsetFont(Font_t *font)
{
    if (font) {
        sfFont_destroy(font->core);
        free(font);
    }
}

/**
 * \brief   Create an instance of the Text_t Object.
 * \param   font the font (Font_t Object) of the new Text_t Object.
 * \param   string the text of the new Text_t Object.
 * \param   color the color of the new Text_t Object.
 */
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

/**
 * \brief   Clear the memory taken by the Text_t Object.
 * \param   text the element to free.
 */
void unsetText(Text_t *text)
{
    if (text) {
        sfText_destroy(text->core);
        free(text);
    }
}