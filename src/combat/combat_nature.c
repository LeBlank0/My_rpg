/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** combat in the wild
*/

#include "rpg.h"
#include "my.h"

static void combat_scene_zero_2(main_t *m)
{
    if (m->game->pnj == 98)
        sfMusic_stop(m->intro->song_rayquaza);
    else
        sfMusic_stop(m->intro->song_fight);
    sfMusic_play(m->intro->song_game);
    for (int i = 0; m->combat->pokemon[1]->pokemon_pv[i] != 1001; i++) {
        m->combat->pokemon[1]->pokemon_pv[i] =
        m->combat->pokemon[1]->pokemon_pv_max[i];
    }
    VER = 72;
    HOR = 86;
    m->my_game->move_left_right = -(1801 * 3.5) + 385;
    m->my_game->move_top_bottom = -(1229 * 3.5) + 200;
    m->game->fight_npc = false;
    GAME_SCENE = 2;
}

static void combat_scene_zero(main_t *m)
{
    static float clock_scene_zero = 0;

    clock_scene_zero += TIME;
    if (clock_scene_zero > 2) {
        clock_scene_zero = 0;
        if (my_strcmp(sfText_getString(TXT_COMBAT[0]), "All of your") == 0
        && my_strcmp(sfText_getString(TXT_COMBAT[1]), "pokemon died !") == 0) {
            m->my_game->fight = false;
            m->game->fight_npc = false;
            sfSleep((sfTime){1500000});
            combat_scene_zero_2(m);
        }
        combat_scene_zero_5(m);
        sfText_setString(TXT_COMBAT[0], "What should your");
        sfText_setString(TXT_COMBAT[1], "pokemon do ?");
        sfText_setString(TXT_COMBAT[8], "");
        sfText_setString(TXT_COMBAT[9], "");
        sfText_setString(TXT_COMBAT[10], "Attack          Bag");
        sfText_setString(TXT_COMBAT[11], "Pokemon       Run");
        COMBAT_SCENE = 1;
    }
}

static void xp(main_t *m)
{
    float one = (float) {
        m->combat->pokemon[1]->pokemon_xp[m->combat->pokemon_our]}
    / (float){m->combat->pokemon[1]->pokemon_lvl[m->combat->pokemon_our] * 10};

    xp_1(m);
    if (m->combat->pokemon[1]->pokemon_lvl[m->combat->pokemon_our] > 100)
        m->combat->pokemon[1]->pokemon_lvl[m->combat->pokemon_our] = 100;
    if (m->combat->pokemon[1]->pokemon_lvl[m->combat->pokemon_our] >=
        my_atoi(get_info
        (m, m->combat->pokemon[1]->pokemon[m->combat->pokemon_our], 66)))
        m->combat->pokemon[1]->pokemon[m->combat->pokemon_our] += 9;
    R_COMBAT[8].top = 0;
    for (float i = 0; i < one; i += 0.0625)
        R_COMBAT[8].top += 8;
    sfSprite_setTextureRect(SP_COMBAT[8], R_COMBAT[8]);
}

static void hp(main_t *m)
{
    int pv = 0;
    float zero = (float) {
        m->combat->pokemon[0]->pokemon_pv[m->combat->pokemon_en]}
    / (float){m->combat->pokemon[0]->pokemon_pv_max[m->combat->pokemon_en]};
    float one = (float) {
        m->combat->pokemon[1]->pokemon_pv[m->combat->pokemon_our]}
    / (float){m->combat->pokemon[1]->pokemon_pv_max[m->combat->pokemon_our]};

    R_COMBAT[5].top = 0;
    R_COMBAT[6].top = 0;
    for (float i = 0; i < zero; i += 0.1)
        R_COMBAT[5].top += 7;
    for (float i = 0; i < one; i += 0.1)
        R_COMBAT[6].top += 7;
    hp_1(m);
    for (int i = 0; m->combat->pokemon[1]->pokemon_pv[i] != 1001; i++)
        if (m->combat->pokemon[1]->pokemon_pv[i] > 0)
            pv++;
    hp_2(m, pv);
}

int combat_nature(main_t *m)
{
    char *ch_scene[7] = {"0", "1", "2", "3", "4", NULL};
    void (*scene[6])(main_t *) = {combat_scene_zero, combat_scene_one_two,
        combat_scene_one_two, combat_scene_three, combat_scene_four};

    if (m->inv->cas == 1) {
        set_four(m);
        m->inv->cas = 0;
    } else if (m->inv->cas == 2 && m->combat->pot > 0) {
        pot(m);
        m->inv->cas = 0;
    }
    for (int i = 0; m->combat->pokemon[1]->pokemon_pv[i] != 1001; i++)
        if (m->combat->pokemon[1]->pokemon_pv[i] <= 0)
            m->combat->pokemon[1]->pokemon_pv[i] = 0;
    hp(m);
    xp(m);
    create_rand();
    if (m->combat->pokemon_nbr > 0)
        number_pokemon(m);
    for (int i = 0; i != 3; i++)
        sfRenderWindow_drawSprite(WINDOW, SP_COMBAT[i], NULL);
    for (int i = 5; i != NB_SP_COMBAT; i++)
        sfRenderWindow_drawSprite(WINDOW, SP_COMBAT[i], NULL);
    for (int i = 0; i != 12; i++)
        sfRenderWindow_drawText(WINDOW, TXT_COMBAT[i], NULL);
    for (int i = 0; ch_scene[i] != NULL; i += 1)
        my_strcmp(ch_scene[i], my_itoa(COMBAT_SCENE)) == 0 ? scene[i](m) : 0;
    return (0);
}
