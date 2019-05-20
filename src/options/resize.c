/*
** EPITECH PROJECT, 2018
** rect
** File description:
** defender game rect
*/

#include "rpg.h"
#include "my.h"

int resize_left(main_t *m, int nb)
{
    int res = ((nb / 800.0) * (sfRenderWindow_getSize(WINDOW)).x);
    return (res);
}

int resize_top(main_t *m, int nb)
{
    int res = ((nb / 600.0) * (sfRenderWindow_getSize(WINDOW)).y);
    return (res);
}
