#include "ocml.h"

/**
 * \brief   Create an instance of the SndBuffer_t Object.
 * \param   path the path to the file containing the sound.
 */
SndBuffer_t *setSoundBuffer(char *path)
{
    SndBuffer_t *buffer = (path) ? malloc(sizeof(SndBuffer_t)) : NULL;

    if (path)
        buffer->core = sfSoundBuffer_createFromFile(path);
    //sfSoundBuffer_saveToFile(buffer->core, path);
    return (buffer);
}

/**
 * \brief   Clear the memory taken by the SndBuffer_t Object.
 * \param   buffer the element to free.
 */
void unsetSoundBuffer(SndBuffer_t *buffer)
{
    if (buffer) {
        sfSoundBuffer_destroy(buffer->core);
        free(buffer);
    }
}

/**
 * \brief   Create an instance of the Sound_t Object.
 * \param   buffer the stream containing the sound.
 * \param   loop a boolean representing if the sound must be play in a loop.
 */
Sound_t *setSound(SndBuffer_t *buffer, sfBool loop)
{
    Sound_t *sound = (buffer) ? malloc(sizeof(Sound_t)) : NULL;

    if (sound && (sound->core = sfSound_create())) {
        sfSound_setBuffer(sound->core, buffer->core);
        sfSound_setLoop(sound->core, loop);
    }
    return (sound);
}

/**
 * \brief   Clear the memory taken by the Sound_t Object.
 * \param   sound the element to free.
 */
void unsetSound(Sound_t *sound)
{
    if (sound) {
        sfSound_destroy(sound->core);
        free(sound);
    }
}

/**
 * \brief   Create an instance of the Music_t Object.
 * \param   path the path to the file containing the music.
 * \param   loop a boolean representing if the music must be play in a loop.
 */
Music_t *setMusic(char *path, sfBool loop)
{
    Music_t *music = (path) ? malloc(sizeof(Music_t)) : NULL;

    if (music) {
        music->core = sfMusic_createFromFile(path);
        sfMusic_setLoop(music->core, loop);
        music->name = setStr(path);
    }
    return (music);
}

/**
 * \brief   Clear the memory taken by the Music_t Object.
 * \param   music the element to free.
 */
void unsetMusic(Music_t *music)
{
    if (music) {
        sfMusic_destroy(music->core);
        unsetStr(music->name);
        free(music);
    }
}