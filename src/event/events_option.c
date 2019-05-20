/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** events_option.c
*/

#include "rpg.h"
#include "my.h"

void move_scale(main_t *m)
{
    if ((EVENT.type == sfEvtKeyReleased && EVENT.key.code ==
    sfKeyDown && COORD == 185) || (EVENT.type ==
    sfEvtKeyReleased && EVENT.key.code == sfKeyUp && STATE == 2)) {
        COORD = 265;
        STATE = 1;
    } else if ((EVENT.type == sfEvtKeyReleased &&
    EVENT.key.code == sfKeyUp && COORD == 265) ||
    (EVENT.type == sfEvtKeyReleased && EVENT.key.code ==
    sfKeyUp && STATE == 1)) {
        COORD = 185;
        STATE = 0;
    } else if ((EVENT.type == sfEvtKeyReleased &&
    EVENT.key.code == sfKeyDown && STATE == 1) || (EVENT.type
    == sfEvtKeyReleased && EVENT.key.code == sfKeyUp && STATE == 3)) {
        COORD = 345;
        STATE = 2;
    } else if (EVENT.type == sfEvtKeyReleased &&
        EVENT.key.code == sfKeyDown && STATE == 2 && (COORD = 425))
        STATE = 3;
}

void change_set1(int set_1, main_t *m)
{
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code ==
    sfKeyRight && set_1 != 3 && STATE == 0) {
        sfText_setColor(TEXT[set_1 + 1], (sfColor) {247, 47, 3, 255});
        sfText_setColor(TEXT[set_1], sfBlack);
    }
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code ==
    sfKeyLeft && set_1 != 1 && STATE == 0) {
        sfText_setColor(TEXT[set_1 - 1], (sfColor) {247, 47, 3, 255});
        sfText_setColor(TEXT[set_1], sfBlack);
    }
}

void change_set2(int set_2, main_t *m)
{
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code ==
    sfKeyRight && set_2 != 7 && STATE == 1) {
        sfText_setColor(TEXT[set_2 + 1], (sfColor) {247, 47, 3, 255});
        sfText_setColor(TEXT[set_2], sfBlack);
    }
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code ==
    sfKeyLeft && set_2 != 5 && STATE == 1) {
        sfText_setColor(TEXT[set_2 - 1], (sfColor) {247, 47, 3, 255});
        sfText_setColor(TEXT[set_2], sfBlack);
    }
}

void change_game_scene_options(main_t *m)
{
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code ==
    sfKeyEnter && STATE == 3) {
        if (OLD_GAME_SCENE == 2)
            GAME_SCENE = 2;
        else
            GAME_SCENE = 1;
    }
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code ==
        sfKeyEnter && STATE == 2)
        GAME_SCENE = 5;
}
