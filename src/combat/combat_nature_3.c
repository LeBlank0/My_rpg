/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** combay_nature_3
*/

#include "rpg.h"
#include "my.h"

void player(main_t *m)
{
    int a = 0;
    int b = 0;
    int c = 0;

    m->combat->clock_attack += TIME;
    if (m->combat->clock_attack > 2.2) {
        if (m->combat->pokemon[0]->pokemon_pv[m->combat->pokemon_en] <= 0) {
            m->combat->pokemon_nbr -= 1;
            sfText_setString(TXT_COMBAT[0], "Ennemy pokemon");
            sfText_setString(TXT_COMBAT[1], "died !");
            sfSprite_setPosition(SP_COMBAT[1], (sfVector2f){850, 650});
            m->combat->pokemon[1]->pokemon_xp[m->combat->pokemon_our] +=
            (m->combat->pokemon[0]->pokemon_lvl[m->combat->pokemon_en] * 7);
            m->combat->clock_attack = 0;
            m->combat->clock_anime_ball = 0;
            m->combat->stat_anime_ball = 0;
            reset_pokemon(m);
            return;
        }
        c = (rand() % 19) + 1;
        do {
            c -= 1;
            a = c <= 18 ? 53 : a;
            a = c <= 5 ? 41 : a;
            a = c <= 2 ? 28 : a;
            a = c == 0 ? 15 : a;
        }
        while (my_strcmp(get_info
        (m, m->combat->pokemon[0]->pokemon[m->combat->pokemon_en], a), "-")
        != 1 || my_atoi(get_info
        (m, m->combat->pokemon[0]->pokemon[m->combat->pokemon_en], (a + 9))) >
        m->combat->pokemon[0]->pokemon_lvl[m->combat->pokemon_en]);
        b = ((m->combat->pokemon[0]->pokemon_pv[m->combat->pokemon_en] * 200) /
        m->combat->pokemon[0]->pokemon_pv_max[m->combat->pokemon_en]);
        b = b < 5 ? 15 : b;
        if (rand() % b == 1 && m->game->fight_npc == false) {
            sfText_setString(TXT_COMBAT[0], "Ennemy pokemon");
            sfText_setString(TXT_COMBAT[1], "ran away !");
            m->combat->clock_anime = 0;
            m->combat->clock_attack = 0;
            m->combat->clock_anime_ball = 0;
            m->combat->stat_anime_ball = 0;
            return;
        }
        attack_choice(m, 0, a);
        m->combat->clock_anime = 0;
        m->combat->clock_attack = 0;
        m->combat->clock_anime_ball = 0;
        m->combat->stat_anime_ball = 0;
    }
}

void animation_combat_scene_four(main_t *m)
{
    R_COMBAT[0].left = 800;
    sfSprite_setTextureRect(SP_COMBAT[0], R_COMBAT[0]);
    sfText_setString(TXT_COMBAT[0], "What should your");
    sfText_setString(TXT_COMBAT[1], "pokemon do ?");
    sfText_setString(TXT_COMBAT[10], "Attack          Bag");
    sfText_setString(TXT_COMBAT[11], "Pokemon       Run");
    sfSprite_setPosition(SP_COMBAT[1], (sfVector2f){468, 25});
    sfSprite_setPosition(SP_COMBAT[4], (sfVector2f){437, 480});
    R_COMBAT[3] = (sfIntRect){0, 0, 12, 12};
    sfSprite_setTextureRect(SP_COMBAT[3], R_COMBAT[3]);
    sfSprite_setRotation(SP_COMBAT[3], 0);
    COMBAT_SCENE = 1;
}

void combat_scene_four_bis(main_t *m, int c)
{
    m->inv->cas = 0;
    if (c == 0) {
        sfText_setString(TXT_COMBAT[0], "You catched the");
        sfText_setString(TXT_COMBAT[1], "ennemy pokemon !");
        m->combat->pokemon[1]->pokemon_lvl[get_poke_nb(m, 1)] =
        m->combat->pokemon[0]->pokemon_lvl[m->combat->pokemon_en];
        m->combat->pokemon[1]->pokemon_pv[get_poke_nb(m, 1)] =
        m->combat->pokemon[0]->pokemon_pv[m->combat->pokemon_en];
        m->combat->pokemon[1]->pokemon_pv_max[get_poke_nb(m, 1)] =
        m->combat->pokemon[0]->pokemon_pv_max[m->combat->pokemon_en];
        m->combat->pokemon[1]->pokemon[get_poke_nb(m, 1)] =
        m->combat->pokemon[0]->pokemon[m->combat->pokemon_en];
        sfSprite_setRotation(SP_COMBAT[3], 0);
    } else if (c >= 1) {
        sfText_setString(TXT_COMBAT[0], "The pokemon");
        sfText_setString(TXT_COMBAT[1], "get out of the pokeball !");
        if (rand() % 7 == 0)
            sfText_setString(TXT_COMBAT[1], "ran away !");
        R_COMBAT[3] = (sfIntRect){0, 12, 12, 12};
        sfSprite_setTextureRect(SP_COMBAT[3], R_COMBAT[3]);
        sfSprite_setRotation(SP_COMBAT[3], 0);
    }
}

void combat_scene_four(main_t *m)
{
    static float clock_scene_four = 0;
    static int anime = 0;
    static int b = 0;
    static int c = 0;

    if (anime == 0)
        anime_pokeball(m);
    sfRenderWindow_drawSprite(WINDOW, SP_COMBAT[3], NULL);
    clock_scene_four += TIME;
    if (b == 0 && clock_scene_four > 3.5) {
        clock_scene_four = 0;
        b = 1;
        c = rand() % 3;
        combat_scene_four_bis(m, c);
        anime = 1;
    }
    else if (b == 1 && clock_scene_four > 2.5) {
        clock_scene_four = 0;
        anime = 0;
        b = 0;
        m->combat->clock_anime = 0;
        m->combat->clock_attack = 0;
        m->combat->clock_anime_ball = 0;
        m->combat->stat_anime_ball = 0;
        if (c == 0) {
            if (m->game->pnj == 98)
                sfMusic_stop(m->intro->song_rayquaza);
            else
                sfMusic_stop(m->intro->song_fight);
            sfMusic_play(m->intro->song_game);
            m->game->fight_npc = false;
            GAME_SCENE = 2;
            return;
        }
        if (my_strcmp(sfText_getString(TXT_COMBAT[1]), "ran away !") == 0) {
            sfSleep((sfTime){1000000});
            if (m->game->pnj == 98)
                sfMusic_stop(m->intro->song_rayquaza);
            else
                sfMusic_stop(m->intro->song_fight);
            sfMusic_play(m->intro->song_game);
            m->game->fight_npc = false;
            GAME_SCENE = 2;
        }
        animation_combat_scene_four(m);
    }
}

void combat_scene_three_bis(main_t *m)
{
    sfSprite_setTextureRect(SP_COMBAT[0], R_COMBAT[0]);
    sfText_setString(TXT_COMBAT[0], "What should your");
    sfText_setString(TXT_COMBAT[1], "pokemon do ?");
    sfText_setString(TXT_COMBAT[10], "Attack          Bag");
    sfText_setString(TXT_COMBAT[11], "Pokemon       Run");
    COMBAT_SCENE = 1;
}
