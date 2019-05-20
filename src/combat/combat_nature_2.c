/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** combat_nature_2
*/

#include "rpg.h"
#include "my.h"

void number_pokemon(main_t *m)
{
    R_COMBAT[7] = (sfIntRect){0, (72 - (m->combat->pokemon_nbr * 12)), 72, 12};
    sfSprite_setTextureRect(SP_COMBAT[7], R_COMBAT[7]);
}

int anime_attack_if_2(main_t *m, int stat)
{
    if (stat == 0) {
        if (my_strcmp(sfText_getString(TXT_COMBAT[1]), "ran away !") != 0 &&
            my_strcmp(sfText_getString(TXT_COMBAT[1]), "You won !!!") != 0 &&
            my_strcmp(sfText_getString(TXT_COMBAT[1]), "died !") != 0)
            sfSprite_move(SP_COMBAT[2], (sfVector2f){15, 0});
        stat = 1;
    } else if (stat == 1) {
        if (my_strcmp(sfText_getString(TXT_COMBAT[1]), "ran away !") != 0 &&
            my_strcmp(sfText_getString(TXT_COMBAT[1]), "You won !!!") != 0 &&
            my_strcmp(sfText_getString(TXT_COMBAT[1]), "died !") != 0)
            sfSprite_move(SP_COMBAT[2], (sfVector2f){-15, 0});
        stat = 0;
    }
    return (stat);
}

void anime_attack(main_t *m)
{
    static int stat = 0;
    static int poke = 0;

    m->combat->clock_anime += TIME;
    if (m->combat->clock_anime > 0.48 && poke <= 3) {
        m->combat->clock_anime = 0;
        if (stat == 0) {
            sfSprite_move(SP_COMBAT[1], (sfVector2f){15, 0});
            stat = 1;
        } else if (stat == 1) {
            sfSprite_move(SP_COMBAT[1], (sfVector2f){-15, 0});
            stat = 0;
        }
        poke += 1;
    }
    if (m->combat->clock_anime > 0.48 && poke > 3 && (poke += 1)) {
        m->combat->clock_anime = 0;
        stat = anime_attack_if_2(m, stat);
    }
    poke == 8 ? (poke = 0) : 0;
}

void anime_pokeball(main_t *m)
{
    m->combat->clock_anime_ball += TIME;
    if (m->combat->clock_anime_ball > 0.56) {
        m->combat->clock_anime_ball = 0;
        if (m->combat->stat_anime_ball == 0) {
            sfSprite_setRotation(SP_COMBAT[3], 45);
            m->combat->stat_anime_ball = 1;
        }
        else if (m->combat->stat_anime_ball == 1) {
            sfSprite_setRotation(SP_COMBAT[3], 0);
            m->combat->stat_anime_ball = 2;
        }
        else if (m->combat->stat_anime_ball == 2) {
            sfSprite_setRotation(SP_COMBAT[3], -45);
            m->combat->stat_anime_ball = 3;
        }
        else if (m->combat->stat_anime_ball == 3) {
            sfSprite_setRotation(SP_COMBAT[3], 0);
            m->combat->stat_anime_ball = 0;
        }
    }
}

void reset_pokemon(main_t *m)
{
    if (m->combat->pokemon_nbr > 0) {
        m->combat->pokemon_en += 1;
        R_COMBAT[1] = (sfIntRect){my_atoi(get_info(m,
            m->combat->pokemon[0]->pokemon[m->combat->pokemon_en], 75)),
            my_atoi(get_info(m,
            m->combat->pokemon[0]->pokemon[m->combat->pokemon_en], 70)) + 585,
            64, 64};
        sfSprite_setTextureRect(SP_COMBAT[1], R_COMBAT[1]);
        sfText_setString(TXT_COMBAT[2], get_info(m,
        m->combat->pokemon[0]->pokemon[m->combat->pokemon_en], 0));
        sfText_setString(TXT_COMBAT[3],
        my_itoa(m->combat->pokemon[0]->pokemon_lvl[m->combat->pokemon_en]));
        sfSprite_setPosition(SP_COMBAT[1], (sfVector2f){468, 25});
        sfSprite_setPosition(SP_COMBAT[2], (sfVector2f){90, 173});
    }
}
