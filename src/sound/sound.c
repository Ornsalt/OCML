#include "ocml.h"

SndBuffer_t *setSoundBuffer(char *path)
{
    SndBuffer_t *buffer = (path) ? malloc(sizeof(SndBuffer_t)) : NULL;

    if (path)
        buffer->core = sfSoundBuffer_createFromFile(path);
    //sfSoundBuffer_saveToFile(buffer->core, path);
    return (buffer);
}

void unsetSoundBuffer(SndBuffer_t *buffer)
{
    if (buffer) {
        sfSoundBuffer_destroy(buffer->core);
        free(buffer);
    }
}

Sound_t *setSound(SndBuffer_t *buffer, sfBool loop)
{
    Sound_t *sound = (buffer) ? malloc(sizeof(Sound_t)) : NULL;

    if (sound && (sound->core = sfSound_create())) {
        sfSound_setBuffer(sound->core, buffer->core);
        sfSound_setLoop(sound->core, loop);
    }
    return (sound);
}

void unsetSound(Sound_t *sound)
{
    if (sound) {
        sfSound_destroy(sound->core);
        free(sound);
    }
}

Music_t *setMusic(char *path, sfBool loop)
{
    Music_t *music = (path) ? malloc(sizeof(Music_t)) : NULL;

    if (music) {
        music->core = sfMusic_createFromFile(path);
        sfMusic_setLoop(music->core, loop);
        //music->name = setStr(path);
    }
    return (music);
}

void unsetMusic(Music_t *music)
{
    if (music) {
        sfMusic_destroy(music->core);
        //unsetStr(music->name);
        free(music);
    }
}