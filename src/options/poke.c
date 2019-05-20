/*
** EPITECH PROJECT, 2018
** rect
** File description:
** defender game rect
*/

#include "rpg.h"
#include "my.h"

int get_poke_nb(main_t *m, int a)
{
    int i = 0;

    for (; m->combat->pokemon[a]->pokemon[i] != 1001; i++);
    return (i);
}
