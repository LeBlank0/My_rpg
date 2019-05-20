/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** game
*/

#include "rpg.h"
#include "my.h"

void launch_fight(main_t *m, float *timer, int *pokemon, int *lvl, int nb)
{
    static int enter = 0;
    if (*timer < 0.02 && enter == 0) {
        if (m->game->pnj == 98) {
            sfMusic_pause(m->intro->song_game);
            sfMusic_play(m->intro->song_rayquaza);
        } else {
            sfMusic_pause(m->intro->song_game);
            sfMusic_play(m->intro->song_fight);
        }
    }
    if (enter == 8) {
        enter = 0;
        *timer = 0;
        set_combat(m, pokemon, lvl, nb);
        GAME_SCENE = 4;
    }
    if (*timer >= 0.30) {
        if (m->my_game->rect_init_fight.left == 0)
            m->my_game->rect_init_fight.left = 800;
        else
            m->my_game->rect_init_fight.left = 0;
        sfSprite_setTextureRect(m->my_game->sp_init_fight,
        m->my_game->rect_init_fight);
        *timer = 0;
        enter++;
    }
    sfRenderWindow_drawSprite(WINDOW, m->my_game->sp_init_fight, NULL);
}

static void check_fight(main_t *m)
{
    if ((MAP[VER-1][HOR] == 'z' || MAP[VER-2][HOR] == 'z' ||
    MAP[VER-3][HOR] == 'z') && m->game->fighted[0] == 0) {
        m->game->pnj = 6;
        SCENE_TEXT = true;
    }
    if ((MAP[VER][HOR+1] == 'Z' || MAP[VER][HOR+2] == 'Z' ||
    MAP[VER][HOR+3] == 'Z') && m->game->fighted[1] == 0) {
        m->game->pnj = 7;
        SCENE_TEXT = true;
    }
    if ((MAP[VER-1][HOR] == 'y' || MAP[VER-2][HOR] == 'y' ||
    MAP[VER-3][HOR] == 'y') && m->game->fighted[2] == 0) {
        SCENE_TEXT = true;
        m->game->pnj = 8;
    }
    if ((MAP[VER-1][HOR] == 'T' || MAP[VER-2][HOR] == 'T' ||
    MAP[VER-3][HOR] == 'T') && m->game->fighted[4] == 0) {
        SCENE_TEXT = true;
        m->game->pnj = 10;
    }
    if ((MAP[VER+1][HOR] == 't' || MAP[VER+2][HOR] == 't' ||
    MAP[VER+3][HOR] == 't') && m->game->fighted[5] == 0) {
        SCENE_TEXT = true;
        m->game->pnj = 11;
    }
    if ((MAP[VER-1][HOR] == 'W' || MAP[VER-2][HOR] == 'W' ||
    MAP[VER-3][HOR] == 'W') && m->game->fighted[6] == 0) {
        SCENE_TEXT = true;
        m->game->pnj = 12;
    }
    if ((MAP[VER-1][HOR] == 'w' || MAP[VER-2][HOR] == 'w')
    && m->game->fighted[7] == 0) {
        SCENE_TEXT = true;
        m->game->pnj = 13;
    }
}

int game_play(main_t *m)
{
    static float time_fight = 0;
    if (m->my_game->fight == true && m->game->scene_text == false) {
        time_fight += TIME;
        if (m->game->fight_npc == true) {
            fight_npc_func(m, &time_fight);
        } else if (MAP[VER][HOR] == '8') {
            launch_fight(m, &time_fight, (int[2]){(rand() % 4) + 5, 1001},
            (int[2]){(rand() % 6) + 9, 1001}, 1);
        } else
            launch_fight(m, &time_fight, (int[2]){(rand() % 3) + 3, 1001},
            (int[2]){(rand() % 6) + 2, 1001}, 1);
    } else {
        check_fight(m);
        sfSprite_setPosition(m->my_game->map_sprite, (sfVector2f)
        {m->my_game->move_left_right, m->my_game->move_top_bottom});
        sfRenderWindow_drawSprite(WINDOW, m->my_game->map_sprite, NULL);
        sfSprite_setPosition(SP_MOBS[0], (sfVector2f){660 +
            (m->my_game->move_left_right -(-(1801 * 3.5) + 385)), -250 +
            (m->my_game->move_top_bottom -(-(1229 * 3.5) + 200))});
        sfSprite_setPosition(SP_MOBS[1], (sfVector2f){720 +
            (m->my_game->move_left_right -(-(1801 * 3.5) + 385)), -250 +
            (m->my_game->move_top_bottom -(-(1229 * 3.5) + 200))});
        sfSprite_setPosition(SP_MOBS[2], (sfVector2f){3231 +
            (m->my_game->move_left_right -(-(1801 * 3.5) + 385)), 302 +
            (m->my_game->move_top_bottom -(-(1229 * 3.5) + 200))});
        sfSprite_setPosition(SP_MOBS[3], (sfVector2f){660 +
            (m->my_game->move_left_right -(-(1658 * 3.5) + 385)), -250 +
            (m->my_game->move_top_bottom -(-(736 * 3.5) + 200))});
        sfSprite_setPosition(SP_MOBS[4], (sfVector2f){660 +
            (m->my_game->move_left_right -(-(1658 * 3.5) + 385)), -250 +
            (m->my_game->move_top_bottom -(-(751 * 3.5) + 200))});
        sfSprite_setPosition(SP_MOBS[5], (sfVector2f){608 +
            (m->my_game->move_left_right -(-(1800 * 3.5) + 385)), -3610 +
            (m->my_game->move_top_bottom -(-(1229 * 3.5) + 200))});
        sfSprite_setPosition(SP_MOBS[6], (sfVector2f){-351 +
            (m->my_game->move_left_right -(-(1658 * 3.5) + 385)), -86 +
            (m->my_game->move_top_bottom -(-(751 * 3.5) + 200))});
        sfSprite_setPosition(SP_MOBS[7], (sfVector2f){-799 +
            (m->my_game->move_left_right -(-(1658 * 3.5) + 385)), -26 +
            (m->my_game->move_top_bottom -(-(751 * 3.5) + 200))});
        sfSprite_setPosition(SP_MOBS[8], (sfVector2f){-1135 +
            (m->my_game->move_left_right -(-(1658 * 3.5) + 385)), -645 +
            (m->my_game->move_top_bottom -(-(751 * 3.5) + 200))});
        sfSprite_setPosition(SP_MOBS[9], (sfVector2f){-1750 +
            (m->my_game->move_left_right -(-(1658 * 3.5) + 385)), -478 +
            (m->my_game->move_top_bottom -(-(751 * 3.5) + 200))});
        sfSprite_setPosition(m->my_game->ia_sprite, (sfVector2f){772 +
            (m->my_game->move_left_right -(-(1801 * 3.5) + 385)), -275 +
            (m->my_game->move_top_bottom -(-(1229 * 3.5) + -500))});
        game_play_bis(m);
    }
    return (0);
}
