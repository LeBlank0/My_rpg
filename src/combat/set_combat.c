/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** combat in the wild set
*/

#include "rpg.h"
#include "my.h"

static void set_combat_bis_bis(main_t *m)
{
    sfText_setString(TXT_COMBAT[8], "  ");
    sfText_setString(TXT_COMBAT[9], "  ");
    sfText_setString(TXT_COMBAT[10], "  ");
    sfText_setString(TXT_COMBAT[11], "  ");
    sfSprite_setOrigin(SP_COMBAT[3], (sfVector2f){6, 6});
    sfSprite_setRotation(SP_COMBAT[3], 0);
    sfSprite_setPosition(SP_COMBAT[1], (sfVector2f){468, 25});
    sfSprite_setPosition(SP_COMBAT[2], (sfVector2f){90, 173});
    sfSprite_setPosition(SP_COMBAT[4], (sfVector2f){437, 480});
    m->combat->clock_anime = 0;
    m->combat->clock_attack = 0;
    m->combat->stat_anime_ball = 0;
    m->combat->clock_anime_ball = 0;
    m->combat->clock_scene_three = 0;
}

static void set_combat_bis(main_t *m, int p1, int a)
{
    R_COMBAT[0] = (sfIntRect){0, 0, 800, 600};
    R_COMBAT[3] = (sfIntRect){0, 0, 12, 12};
    R_COMBAT[5] = (sfIntRect){0, 0, 159, 7};
    R_COMBAT[6] = (sfIntRect){0, 0, 159, 7};
    sfSprite_setTextureRect(SP_COMBAT[0], R_COMBAT[0]);
    sfSprite_setTextureRect(SP_COMBAT[1], R_COMBAT[1]);
    sfSprite_setTextureRect(SP_COMBAT[2], R_COMBAT[2]);
    sfSprite_setTextureRect(SP_COMBAT[3], R_COMBAT[3]);
    sfSprite_setTextureRect(SP_COMBAT[5], R_COMBAT[5]);
    sfSprite_setTextureRect(SP_COMBAT[6], R_COMBAT[6]);
    sfText_setString(TXT_COMBAT[0], "THE COMBAT");
    sfText_setString(TXT_COMBAT[1], "BEGIN !!!");
    sfText_setString(TXT_COMBAT[2], get_info(m, p1, 0));
    sfText_setString(TXT_COMBAT[3],
    my_itoa(m->combat->pokemon[0]->pokemon_lvl[0]));
    sfText_setString(TXT_COMBAT[4], get_info(m, a, 0));
    sfText_setString(TXT_COMBAT[5],
    my_itoa(m->combat->pokemon[1]->pokemon_lvl[m->combat->pokemon_our]));
    sfText_setString(TXT_COMBAT[6],
    my_itoa(m->combat->pokemon[1]->pokemon_pv[m->combat->pokemon_our]));
    sfText_setString(TXT_COMBAT[7],
    my_itoa(m->combat->pokemon[1]->pokemon_pv_max[m->combat->pokemon_our]));
    set_combat_bis_bis(m);
}

void set_combat_1(main_t *m, int *p1)
{
    R_COMBAT[1] = (sfIntRect){my_atoi(get_info(m,
        m->combat->pokemon[0]->pokemon[m->combat->pokemon_en], 75)),
        (my_atoi(get_info(m,
        m->combat->pokemon[0]->pokemon[m->combat->pokemon_en], 70)) + 585),
        64, 64};
    R_COMBAT[2] = (sfIntRect){my_atoi(get_info(m,
        m->combat->pokemon[1]->pokemon[m->combat->pokemon_our], 75)),
        my_atoi(get_info(m,
        m->combat->pokemon[1]->pokemon[m->combat->pokemon_our], 70)), 64, 64};
    set_combat_bis(m, p1[m->combat->pokemon_en],
    m->combat->pokemon[1]->pokemon[m->combat->pokemon_our]);
}

void set_combat(main_t *m, int *p1, int *p2, int nb)
{
    COMBAT_SCENE = 0;
    m->inv->cas = 0;
    m->combat->pot = 2;
    m->combat->pokemon_en = 0;
    m->combat->pokemon_our = 0;
    for (; m->combat->pokemon[1]->pokemon_pv[m->combat->pokemon_our] <= 0;
    m->combat->pokemon_our += 1);
    m->combat->pokemon_nbr = nb;
    for (int i = 0; p1[i] != 1001; i++) {
        m->combat->pokemon[0]->pokemon[i] = p1[i];
        m->combat->pokemon[0]->pokemon[i + 1] = 1001;
        m->combat->pokemon[0]->pokemon_lvl[i] = p2[i];
        m->combat->pokemon[0]->pokemon_pv[i] =
        (my_atoi(get_info(m, p1[i], 11)) +
        m->combat->pokemon[0]->pokemon_lvl[i]);
        m->combat->pokemon[0]->pokemon_pv_max[i] =
        (my_atoi(get_info(m, p1[i], 11)) +
        m->combat->pokemon[0]->pokemon_lvl[i]);
    }
    set_combat_1(m, p1);
}
