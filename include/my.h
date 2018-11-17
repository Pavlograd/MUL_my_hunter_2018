/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** task02
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "create_sprite.h"
#include "struct.h"

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
sfRenderWindow *createMyWindow(unsigned int width, unsigned int height);
void move_rect(sfIntRect *rect, sprites_t *s, value_t *v);
void my_enemy(value_t *value, sprites_t *s);
int my_put_window(sprites_t *s, value_t *v);
void events(value_t *v, sprites_t *s);
void my_events(value_t *v, sprites_t *s);
void my_events2(value_t *val, sfEvent ev);
void my_events3(value_t *val, int mousey);
void value_x(sprites_t *s, value_t *value);
value_t *value_create(void);
sprites_t *sprites_create(void);
void you_win(sprites_t *s);
void you_start(sprites_t *s);
void click_event(value_t *v, sprites_t *s);
void target(sprites_t *s);
void mouse_move(sfEvent event, sprites_t *s);

#endif /* MY_H_ */
