/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** game_6
*/

#include "rpg.h"
#include "my.h"

void pnj_1_1(main_t *m)
{
    print_text("You can't pass !\nThe professor is waiting for "
    "you at his laboratory.\0", m);
}

void pnj_2_1(main_t *m)
{
    print_text("Flora is waiting for you in the north"
    ", go see her !!!\0", m);
}

void pnj_4_1(main_t *m)
{
    print_text("Hello, I'm healing your Pokemons !!!\n And... "
    "It's all good, I've healed them all.\0", m);
    game_play_bis_2(m);
}