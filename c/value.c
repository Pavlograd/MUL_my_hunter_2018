/*
** EPITECH PROJECT, 2018
** value
** File description:
** my_hunter
*/

#include "create_sprite.h"
#include "struct.h"
#include "my.h"

void value_x(sprites_t *s, value_t *value)
{
    if (value->x >= 1920)
            sfRenderWindow_close(s->window);
    value->x += 10;
    if (value->y > 850) {
        value->y = 0;
    }
}

value_t *value_create(void)
{
    value_t *value = malloc(sizeof(value_t));

    value->start = 0;
    value->totoro = 0;
    value->top = 0;
    value->x = 0;
    value->y = 0;
    value->score = 0;
    return (value);
}

sfVector2f position_create(void)
{
    sfVector2f position;

    position.x = 0;
    position.y = 0;
    return position;
}

sprites_t *sprites_create(void)
{
    sprites_t *s = malloc(sizeof(sprites_t));

    s->window = createMyWindow(1920, 1080);
    s->target_s = sfSprite_create();
    s->target_t = sfTexture_createFromFile("./src/target.png", NULL);
    s->sprite = sfSprite_create();
    s->texture = sfTexture_createFromFile("./src/wallpaper.png", NULL);
    s->sprite2 = sfSprite_create();
    s->texture2 = sfTexture_createFromFile("./src/totoro.png", NULL);
    s->win_s = sfSprite_create();
    s->win_t = sfTexture_createFromFile("./src/louise.png", NULL);
    s->start_s = sfSprite_create();
    s->start_t = sfTexture_createFromFile("./src/menu.jpg", NULL);
    s->music = sfMusic_createFromFile("./src/music.ogg");
    s->clock = sfClock_create();
    s->vector = position_create();
    sfMusic_play(s->music);
    return (s);
}
