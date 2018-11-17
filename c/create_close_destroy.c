/*
** EPITECH PROJECT, 2018
** create_close_destroy
** File description:
** my_hunter
*/

#include "my.h"

void destroy(sprites_t *s)
{
    sfMusic_destroy(s->music);
    sfSprite_destroy(s->sprite);
    sfSprite_destroy(s->sprite2);
    sfTexture_destroy(s->texture);
    sfTexture_destroy(s->texture2);
    sfRenderWindow_destroy(s->window);
}

void background(sprites_t *s)
{
    sfSprite_setTexture(s->sprite, s->texture, sfFalse);
    sfRenderWindow_drawSprite(s->window, s->sprite, NULL);
}

int my_put_window(sprites_t *s, value_t *v)
{
    sfRenderWindow_setFramerateLimit(s->window, 120);
    while (sfRenderWindow_isOpen(s->window)) {
        if (v->start == 0) {
            you_start(s);
            click_event(v, s);
        } else {
            sfRenderWindow_clear(s->window, s->color);
            background(s);
            events(v, s);
            value_x(s, v);
        }
        target(s);
        sfRenderWindow_display(s->window);
    }
    destroy(s);
}

sfRenderWindow *createMyWindow(unsigned int width, unsigned int height)
{
    sfRenderWindow *win;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;

    win = sfRenderWindow_create(video_mode,
                                "Window", sfDefaultStyle, NULL);
    return win;
}
