/*
** EPITECH PROJECT, 2018
** create-sprite
** File description:
** my_hunter
*/

#include "my.h"

#ifndef STRINGU
#define STRINGU

struct sprites {
    sfRenderWindow *window;
    sfColor color;
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *sprite2;
    sfTexture *texture2;
    sfSprite *win_s;
    sfTexture *win_t;
    sfSprite *start_s;
    sfTexture *start_t;
    sfSprite *target_s;
    sfTexture *target_t;
    sfVector2f vector;
    sfClock *clock;
    sfMusic *music;
    sfEvent event;
};

typedef struct sprites sprites_t;

#endif /* STRINGU */
