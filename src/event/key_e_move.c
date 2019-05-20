/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** key_e_move
*/

#include "rpg.h"
#include "my.h"

void key_e_move(main_t *m)
{
    if (MAP[VER + 1][HOR] == 'i' || MAP[VER - 1][HOR] == 'i' ||
    MAP[VER][HOR + 1] == 'i' || MAP[VER][HOR - 1] == 'i') {
        if (m->game->talk_professor == false) {
            MAP[64][92] = '0';
            MAP[64][91] = '0';
            m->my_game->rect_mobs[0].left += 32;
            sfSprite_setTextureRect(SP_MOBS[0], m->my_game->rect_mobs[0]);
            sfSprite_setTextureRect(SP_MOBS[1], m->my_game->rect_mobs[0]);
            GAME_SCENE = 6;
            m->game->talk_professor = true;
        } else {
            SCENE_TEXT = true;
            m->game->pnj = 2;
        }
    } else if ((MAP[VER + 1][HOR] == 'b'|| MAP[VER - 1][HOR] == 'b' ||
    MAP[VER][HOR + 1] == 'b' || MAP[VER][HOR - 1] == 'b')
    && SCENE_TEXT == false) {
        m->game->pnj = 2;
        SCENE_TEXT = true;
    } else if ((MAP[VER + 1][HOR] == 'm'|| MAP[VER - 1][HOR] == 'm' ||
    MAP[VER][HOR + 1] == 'm' || MAP[VER][HOR - 1] == 'm')
    && SCENE_TEXT == false) {
        m->game->pnj = 3;
        SCENE_TEXT = true;
    } else if ((MAP[VER + 1][HOR] == 'v'|| MAP[VER - 1][HOR] == 'v' ||
    MAP[VER][HOR + 1] == 'v' || MAP[VER][HOR - 1] == 'v')
    && SCENE_TEXT == false) {
        m->game->pnj = 99;
        SCENE_TEXT = true;
    } else if ((MAP[VER + 1][HOR] == 'k'|| MAP[VER - 1][HOR] == 'k' ||
    MAP[VER][HOR + 1] == 'k' || MAP[VER][HOR - 1] == 'k')
    && SCENE_TEXT == false) {
        m->game->pnj = 4;
        SCENE_TEXT = true;
    } else if ((MAP[VER + 1][HOR] == 'f'|| MAP[VER - 1][HOR] == 'f' ||
    MAP[VER][HOR + 1] == 'f' || MAP[VER][HOR - 1] == 'f')
    && SCENE_TEXT == false) {
        m->game->pnj = 5;
        SCENE_TEXT = true;
    } else if ((MAP[VER + 1][HOR] == 'Y'|| MAP[VER - 1][HOR] == 'Y' ||
    MAP[VER][HOR + 1] == 'Y' || MAP[VER][HOR - 1] == 'Y')
    && SCENE_TEXT == false) {
        m->game->pnj = 9;
        SCENE_TEXT = true;
    } else if ((MAP[VER - 1][HOR] == 'R')
    && SCENE_TEXT == false) {
        m->game->pnj = 98;
        SCENE_TEXT = true;
    } else if ((MAP[VER + 1][HOR] == 'r'|| MAP[VER - 1][HOR] == 'r' ||
    MAP[VER][HOR + 1] == 'r' || MAP[VER][HOR - 1] == 'r')
    && SCENE_TEXT == false) {
        m->game->pnj = 97;
        SCENE_TEXT = true;
    }
}
