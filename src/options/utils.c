/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** utils.c
*/

#include "rpg.h"
#include "my.h"

static const sfVector2f text_pos[4] = {
    {415, 60},
    {415, 125},
    {50, 400},
    {50, 400},
};

void select_set(main_t *m)
{
    sfColor color;
    for (int i = 1; i < 4; i++) {
        color = sfText_getColor(TEXT[i]);
        if (color.r == 247 && color.g == 47 && color.b == 3 && color.a == 255)
            P1 = i;
    }
    for (int j = 5; j <= 7; j++) {
        color = sfText_getColor(TEXT[j]);
        if (color.r == 247 && color.g == 47 && color.b == 3 && color.a == 255)
            P2 = j;
    }
}

void set_pos_text(main_t *m)
{
    for (int i = 10, y = 0; i < NB_TEXT_OPTION; i++, y++)
        sfText_setPosition(TEXT[i], text_pos[y]);
}

void volume_function(main_t *m, int pos1)
{
    switch (pos1) {
    case 1:
        FPS = 30;
        break;
    case 2:
        FPS = 60;
        break;
    case 3:
        FPS = 144;
        break;
    }
}

void fps_function(main_t *m, int pos2)
{
    switch (pos2) {
    case 5:
        VOLUME = 0;
        break;
    case 6:
        VOLUME = 50;
        break;
    case 7:
        VOLUME = 100;
        break;
    }
}

void check_set(main_t *m, int pos1, int pos2)
{
    volume_function(m, pos1);
    fps_function(m, pos2);
}