/*
** EPITECH PROJECT, 2018
** start end
** File description:
** my_hunter
*/

#include "my.h"

void you_win(sprites_t *s)
{
    sfVector2f scale;
    scale.x = 1.70;
    scale.y = 0.75;
    sfSprite_setScale(s->win_s, scale);
    sfSprite_setTexture(s->win_s, s->win_t, sfFalse);
    sfRenderWindow_drawSprite(s->window, s->win_s, NULL);
}

void you_start(sprites_t *s)
{
    sfSprite_setTexture(s->start_s, s->start_t, sfFalse);
    sfRenderWindow_drawSprite(s->window, s->start_s, NULL);
}

void target(sprites_t *s)
{
    sfSprite_setTexture(s->target_s, s->target_t, sfFalse);
    sfSprite_setPosition(s->target_s, s->vector);
    sfRenderWindow_drawSprite(s->window, s->target_s, NULL);
}

void mouse_move(sfEvent event, sprites_t *s)
{
    if (event.type == sfEvtMouseMoved) {
        s->vector.x = event.mouseMove.x - 50;
        s->vector.y = event.mouseMove.y - 50;
    }
}

void click_event(value_t *v, sprites_t *s)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(s->window, &event)) {
        mouse_move(event, s);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(s->window);
        if (event.type == sfEvtMouseButtonPressed)
            v->start += 1;
        if (event.type == sfEvtKeyPressed)
            v->start += 1;
    }
}
