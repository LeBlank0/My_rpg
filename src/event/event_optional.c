/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event_2
*/

#include "rpg.h"
#include "my.h"

void move_sacha(main_t *m)
{
    char *code_key[5] = {"71", "72", "73", "74", NULL};
    void (*flag[4])(main_t *) = {left_move, right_move, up_move,
        down_move};
    for (int i = 0; code_key[i] != NULL; i += 1) {
        if (EVENT.type == sfEvtKeyPressed &&
            EVENT.key.code == atoi(code_key[i]))
            flag[i](m);
    }
}

static void get_pos_1(main_t *m)
{
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyE
    && m->game->coord == 185 && m->game->talk_professor == true) {
        OLD_GAME_SCENE = GAME_SCENE;
        GAME_SCENE = 8;
    }
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyE &&
    m->game->coord == 237) {
        OLD_GAME_SCENE = GAME_SCENE;
        GAME_SCENE = 7;
    }
}

static void get_pos(main_t *m)
{
    get_pos_1(m);
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyE &&
        m->game->coord == 289)
        exit(0);
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyE &&
    m->game->coord == 341) {
        OLD_GAME_SCENE = GAME_SCENE;
        GAME_SCENE = 3;
    }
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyE &&
        m->game->coord == 393)
        STATE_GAME = false;
}

void event_pause(main_t *m)
{
    if (m->game->coord >= 185 && EVENT.type == sfEvtKeyPressed &&
    EVENT.key.code == sfKeyDown) {
        m->game->coord += 52;
        m->game->pos += 1;
    } else if (m->game->coord <= 445 && EVENT.type == sfEvtKeyPressed &&
    EVENT.key.code == sfKeyUp && m->game->coord > 185) {
        m->game->coord -= 52;
        m->game->pos -= 1;
    }
    get_pos(m);
}
