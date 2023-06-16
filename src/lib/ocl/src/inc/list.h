#pragma once

typedef struct Os2DLink {
    char    *name;
    void    *data;
    link_t  *prev;
    link_t  *next;
} link_t;

typedef struct Os2DList {
    link_t *head;
    link_t *tail;
    link_t *sent;
} list_t;