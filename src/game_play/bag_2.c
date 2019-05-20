/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** bag_2
*/

#include "rpg.h"
#include "my.h"

void print_first_pokemon_2(main_t *m)
{
    sfRenderWindow_drawSprite(WINDOW, SP_BAG[0], NULL);
    sfText_setString(m->bag->txbag[0]->name,
    get_info(m, m->combat->pokemon[1]->pokemon[0], 0));
    sfText_setString(m->bag->txbag[0]->pv,
    my_itoa(m->combat->pokemon[1]->pokemon_pv[0]));
    sfText_setString(m->bag->txbag[0]->pv_max,
    my_itoa(m->combat->pokemon[1]->pokemon_pv_max[0]));
    sfText_setString(m->bag->txbag[0]->lvl,
    my_itoa(m->combat->pokemon[1]->pokemon_lvl[0]));
    sfText_setPosition(m->bag->txbag[0]->name, (sfVector2f)
    {26*3.333, 22*3.75});
}