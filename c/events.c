/*
** EPITECH PROJECT, 2018
** events
** File description:
** my_hunter
*/

#include "create_sprite.h"
#include "struct.h"
#include "my.h"

void my_events(value_t *v, sprites_t *s)
{
    while (sfRenderWindow_pollEvent(s->window, &s->event)) {
        mouse_move(s->event, s);
        if (s->event.type == sfEvtClosed)
            sfRenderWindow_close(s->window);
        if (s->event.type == sfEvtMouseButtonPressed)
            my_events2(v, s->event);
    }
}

void my_events2(value_t *val, sfEvent ev)
{
    int mousex;
    int mousey;

    if (ev.mouseButton.button == sfMouseLeft) {
        mousex = ev.mouseButton.x;
        mousey = ev.mouseButton.y;
        for (int i = 110; i != 0; i--) {
            if (mousex == val->x)
                my_events3(val, mousey);
            mousex--;
        }
    }
}

void my_events3(value_t *val, int mousey)
{
    int mouse = mousey;

    for (int j = 110; j != 0; j--) {
        if (mouse == val->y)
            val->totoro += 1;
        mouse--;
    }
}

void events(value_t *v, sprites_t *s)
{
    my_events(v, s);
    if (v->totoro == 0 && v->score < 10)
        my_enemy(v, s);
    if (v->totoro == 1) {
        v->y += 50;
        v->x = 0;
        v->totoro -= 1;
        v->score += 1;
    }
    if (v->score == 10)
        you_win(s);
}
