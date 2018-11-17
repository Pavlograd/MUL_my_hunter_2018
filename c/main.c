/*
** EPITECH PROJECT, 2018
** main
** File description:
** window
*/

#include "create_sprite.h"
#include "struct.h"
#include "my.h"

void move_rect(sfIntRect *rect, sprites_t *s, value_t *v)
{
    sfTime time;
    float seconds;

    while (1) {
        time = sfClock_getElapsedTime(s->clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds >= 0.1) {
            if (rect->top <= 220) {
                rect->top += 110;
            } else {
                rect->top = 0;
            }
            sfClock_restart(s->clock);
            break;
        }
    }
}

sfVector2f position_totoro(int x, int y)
{
    sfVector2f position;

    position.x = x;
    position.y = y;
    return position;
}

sfIntRect rect_totoro(int top)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;
    return rect;
}

void my_enemy(value_t *value, sprites_t *s)
{
    sfIntRect rect = rect_totoro(value->top);
    sfVector2f position = position_totoro(value->x, value->y);

    move_rect(&rect, s, value);
    sfSprite_setTextureRect(s->sprite2, rect);
    sfSprite_setTexture(s->sprite2, s->texture2, sfFalse);
    sfSprite_setPosition(s->sprite2, position);
    sfRenderWindow_drawSprite(s->window, s->sprite2, NULL);
    value->top = rect.top;
}

int main(int ac, char **av)
{
    char *str = av[1];
    value_t *value = value_create();
    sprites_t *sprites = sprites_create();

    if (ac == 2) {
        if (str[0] == '-' && str[1] == 'h' && str[2] == '\0') {
            write(1, "project : my_hunter Epitech 2018\n", 33);
            write(1, "Theme : Ghibli Studio and Totoro <3\n", 36);
            write(1, "Shoot Totoro with the left click\n", 34);
            write(1, "If one Totoro survives you lose...\n", 36);
            write(1, "Kill all Totoro to win\n", 24);
            write(1, "Have fun even if its a shitty game\n", 36);
        } else {
            exit(84);
        }
        exit(0);
    }
    if (ac > 2)
        exit(84);
    my_put_window(sprites, value);
}
