/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** game_5
*/

#include "rpg.h"
#include "my.h"

void pnj_5_1(main_t *m)
{
    print_text("Hello, what do you want ?\0", m);
}

void pnj_6_1(main_t *m)
{
    print_text("Hello, Do you really think you can beat me\n"
    ", ahahah ?!\0", m);
    m->my_game->fight = true;
    m->game->fight_npc = true;
}

void pnj_7_1(main_t *m)
{
    print_text("Hello, Are you really trying to beat me ?!\0", m);
    m->my_game->fight = true;
    m->game->fight_npc = true;
}

void pnj_8_1(main_t *m)
{
    print_text("Hello, You wont beat me, it's impossible !\0", m);
    m->my_game->fight = true;
    m->game->fight_npc = true;
}

void game_play_bis_3(main_t *m)
{
    int pnj[9] = {1, 2, 4, 5, 6, 7, 8, -1};
    void (*flag[])(main_t *) = {pnj_1_1, pnj_2_1, pnj_4_1, pnj_5_1,
        pnj_6_1, pnj_7_1, pnj_8_1};

    for (int i = 0; pnj[i] != -1; i += 1) {
        if (pnj[i] == m->game->pnj) {
            flag[i](m);
            break;
        }
    }
    if (m->game->pnj == 3 && m->game->fighted[8] == 0) {
        print_text("Hey, It's Flora, I'm gonna beat you !!!\0", m);
        m->game->fight_npc = true;
        m->my_game->fight = true;
    }
    if (m->game->pnj == 3 && m->game->fighted[8] == 1)
        print_text("My sister is waiting for you at the West !!!\0", m);
}
