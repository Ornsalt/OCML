#pragma once

#include "ocml.h"

typedef struct osSoundBuffer_s {
    sfSoundBuffer *core;
    //String_t *name;
} SndBuffer_t;

SndBuffer_t *setSoundBuffer(char *path);
void unsetSoundBuffer(SndBuffer_t *buffer);

typedef struct osSound_s {
    sfSound  *core;
    //String_t *name;
} Sound_t;

Sound_t *setSound(SndBuffer_t *buffer, sfBool loop);
void unsetSound(Sound_t *sound);

typedef struct osMusic_s {
    sfMusic  *core;
    String_t *name;
} Music_t;

Music_t *setMusic(char *path, sfBool loop);
void unsetMusic(Music_t *music);