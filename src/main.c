#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){800, 600, 32}, "SFML window", sfResize | sfClose, NULL);
    //sfTexture* texture;
    //sfSprite* sprite;
    //sfFont* font;
    //sfText* text;
    //sfMusic* music;
    sfEvent event;
    
    /* Create the main window */
    if (!window)
        return EXIT_FAILURE;
    /* Load a sprite to display */
    /*texture = sfTexture_createFromFile("cute_image.jpg", NULL);
    if (!texture)
    return EXIT_FAILURE;
    //sprite = sfSprite_create();
    //sfSprite_setTexture(sprite, texture, sfTrue);
    /* Create a graphical text to display */
    //font = sfFont_createFromFile("arial.ttf");
    /*if (!font)
    return EXIT_FAILURE;
    text = sfText_create();
    sfText_setString(text, "Hello SFML");
    //sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    /* Load a music to play */
    //music = sfMusic_createFromFile("nice_music.ogg");
    /*if (!music)
    return EXIT_FAILURE;
    /* Play the music */
    //sfMusic_play(music);
    /* Start the game loop */
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfWhite);
        //sfRenderWindow_drawSprite(window, sprite, NULL);
        //sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_display(window);
    }
    /* Cleanup resources */
    //sfMusic_destroy(music);
    //sfText_destroy(text);
    //sfFont_destroy(font);
    //sfSprite_destroy(sprite);
    //sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}