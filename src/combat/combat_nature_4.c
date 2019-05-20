/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** combat_nature_4
*/

#include "rpg.h"
#include "my.h"

void combat_scene_three_4(main_t *m)
{
    if (my_strcmp(sfText_getString(TXT_COMBAT[1]), "ran away !") == 0) {
        m->my_game->fight = false;
        m->game->fight_npc = false;
        sfSleep((sfTime){1500000});
        if (m->game->pnj == 98)
            sfMusic_stop(m->intro->song_rayquaza);
        else
            sfMusic_stop(m->intro->song_fight);
        sfMusic_play(m->intro->song_game);
        GAME_SCENE = 2;
    }
}

void combat_scene_three_5(main_t *m)
{
    if (my_strcmp(sfText_getString(TXT_COMBAT[1]), "You won !!!") == 0) {
        m->my_game->fight = false;
        m->game->fight_npc = false;
        sfSleep((sfTime){1500000});
        modifyfight(m);
        if (m->game->pnj == 98)
            sfMusic_stop(m->intro->song_rayquaza);
        else
            sfMusic_stop(m->intro->song_fight);
        sfMusic_play(m->intro->song_game);
        GAME_SCENE = 2;
    }
}

void combat_scene_three(main_t *m)
{
    create_rand();
    anime_attack(m);
    player(m);
    m->combat->clock_scene_three += TIME;
    if (m->combat->pokemon_nbr <= 0) {
        sfText_setString(TXT_COMBAT[0], "Ennemy pokemon died");
        sfText_setString(TXT_COMBAT[1], "You won !!!");
    }
    if (m->combat->clock_scene_three > 4) {
        R_COMBAT[0].left += 800;
        combat_scene_three_4(m);
        combat_scene_three_5(m);
        m->combat->clock_scene_three = 0;
        m->combat->clock_anime = 0;
        m->combat->clock_attack = 0;
        m->combat->clock_anime_ball = 0;
        m->combat->stat_anime_ball = 0;
        combat_scene_three_bis(m);
    }
}

void pot(main_t *m)
{
    m->combat->pokemon[1]->pokemon_pv[m->combat->pokemon_our] += 20;
    if (m->combat->pokemon[1]->pokemon_pv[m->combat->pokemon_our] >
    m->combat->pokemon[1]->pokemon_pv_max[m->combat->pokemon_our]) {
        m->combat->pokemon[1]->pokemon_pv[m->combat->pokemon_our] =
        m->combat->pokemon[1]->pokemon_pv_max[m->combat->pokemon_our];
    }
    m->combat->pot -= 1;
    sfText_setString(TXT_COMBAT[6],
    my_itoa(m->combat->pokemon[1]->pokemon_pv[m->combat->pokemon_our]));
}

void combat_scene_one_two(main_t *m)
{
    sfRenderWindow_drawSprite(WINDOW, SP_COMBAT[4], NULL);
}
