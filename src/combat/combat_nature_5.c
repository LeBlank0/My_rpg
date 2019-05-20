/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** combat_nature_5
*/

#include "rpg.h"
#include "my.h"

void xp_1(main_t *m)
{
    if (m->combat->pokemon[1]->pokemon_xp[m->combat->pokemon_our] >=
    (m->combat->pokemon[1]->pokemon_lvl[m->combat->pokemon_our] * 7)) {
        m->combat->pokemon[1]->pokemon_xp[m->combat->pokemon_our]
        -= (m->combat->pokemon[1]->pokemon_lvl[m->combat->pokemon_our] * 10);
        m->combat->pokemon[1]->pokemon_lvl[m->combat->pokemon_our] += 1;
        sfText_setString(TXT_COMBAT[5],
        my_itoa(m->combat->pokemon[1]->pokemon_lvl[m->combat->pokemon_our]));
        m->combat->pokemon[1]->pokemon_pv_max[m->combat->pokemon_our] =
        (my_atoi(get_info(m,
        m->combat->pokemon[1]->pokemon[m->combat->pokemon_our], 11)) +
        m->combat->pokemon[1]->pokemon_lvl[m->combat->pokemon_our]);
        sfText_setString(TXT_COMBAT[7],
        my_itoa(m->combat->pokemon[1]->pokemon_pv_max[m->combat->pokemon_our]));
    }
}

void hp_1(main_t *m)
{
    sfSprite_setTextureRect(SP_COMBAT[5], R_COMBAT[5]);
    sfSprite_setTextureRect(SP_COMBAT[6], R_COMBAT[6]);
    if (m->combat->pokemon[1]->pokemon_pv[m->combat->pokemon_our] <= 0) {
        sfSprite_setPosition(SP_COMBAT[2], (sfVector2f){850, 650});
        sfText_setString(TXT_COMBAT[0], "Your");
        sfText_setString(TXT_COMBAT[1], "pokemon died !");
        sfText_setString(TXT_COMBAT[6], "0");
        sfText_setString(TXT_COMBAT[8], " ");
        sfText_setString(TXT_COMBAT[9], " ");
        sfText_setString(TXT_COMBAT[10], " ");
        sfText_setString(TXT_COMBAT[11], " ");
        m->combat->clock_scene_three = 0;
        m->combat->clock_anime = 0;
        m->combat->clock_attack = 0;
        m->combat->clock_anime_ball = 0;
        m->combat->stat_anime_ball = 0;
        COMBAT_SCENE = 0;
    }
}

void hp_2(main_t *m, int pv)
{
    if (pv <= 0) {
        sfSprite_setPosition(SP_COMBAT[2], (sfVector2f){850, 650});
        sfText_setString(TXT_COMBAT[0], "All of your");
        sfText_setString(TXT_COMBAT[1], "pokemon died !");
        sfText_setString(TXT_COMBAT[6], "0");
        sfText_setString(TXT_COMBAT[8], " ");
        sfText_setString(TXT_COMBAT[9], " ");
        sfText_setString(TXT_COMBAT[10], " ");
        sfText_setString(TXT_COMBAT[11], " ");
        m->combat->clock_scene_three = 0;
        m->combat->clock_anime = 0;
        m->combat->clock_attack = 0;
        m->combat->clock_anime_ball = 0;
        m->combat->stat_anime_ball = 0;
        COMBAT_SCENE = 0;
    }
}

void combat_scene_zero_3(main_t *m)
{
    for (int i = 0; m->combat->pokemon[1]->pokemon_pv[i] <= 0 &&
        m->combat->pokemon[1]->pokemon_pv[i] != 1001; i++)
        m->combat->pokemon_our = i + 1;
    R_COMBAT[2] = (sfIntRect){my_atoi(get_info(m,
        m->combat->pokemon[1]->pokemon[m->combat->pokemon_our], 75)),
        my_atoi(get_info(m, m->combat->pokemon
        [1]->pokemon[m->combat->pokemon_our], 70)), 64, 64};
    sfSprite_setTextureRect(SP_COMBAT[2], R_COMBAT[2]);
}

void combat_scene_zero_5(main_t *m)
{
    if (my_strcmp(sfText_getString(TXT_COMBAT[0]), "Your") == 0
    && my_strcmp(sfText_getString(TXT_COMBAT[1]), "pokemon died !") == 0) {
        sfSprite_setPosition(SP_COMBAT[2], (sfVector2f){90, 173});
        combat_scene_zero_3(m);
        sfText_setString(TXT_COMBAT[4], get_info(m, m->combat->pokemon
        [1]->pokemon[m->combat->pokemon_our], 0));
        sfText_setString(TXT_COMBAT[5], my_itoa(m->combat->pokemon
        [1]->pokemon_lvl[m->combat->pokemon_our]));
        sfText_setString(TXT_COMBAT[6],
        my_itoa(m->combat->pokemon[1]->pokemon_pv[m->combat->pokemon_our]));
        sfText_setString(TXT_COMBAT[7], my_itoa(m->combat->pokemon
        [1]->pokemon_pv_max[m->combat->pokemon_our]));
    }
    m->combat->clock_scene_three = 0;
    m->combat->clock_anime = 0;
    m->combat->clock_attack = 0;
    m->combat->clock_anime_ball = 0;
    m->combat->stat_anime_ball = 0;
    R_COMBAT[0].left = 800;
    sfSprite_setTextureRect(SP_COMBAT[0], R_COMBAT[0]);
}
