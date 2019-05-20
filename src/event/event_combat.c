/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event_combat_2
*/

#include "rpg.h"
#include "my.h"

void combat_event_scene_one(main_t *m)
{
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyDown
        && get_rect(m, SP_COMBAT[4]).top == resize_top(m, 480))
        sfSprite_move(SP_COMBAT[4], (sfVector2f){0, 40});
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyUp
        && get_rect(m, SP_COMBAT[4]).top == resize_top(m, 520))
        sfSprite_move(SP_COMBAT[4], (sfVector2f){0, -40});
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyRight
        && get_rect(m, SP_COMBAT[4]).left == resize_left(m, 437))
        sfSprite_move(SP_COMBAT[4], (sfVector2f){225, 0});
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyLeft
        && get_rect(m, SP_COMBAT[4]).left == resize_left(m, 662))
        sfSprite_move(SP_COMBAT[4], (sfVector2f){-225, 0});
    combat_event_enter_scene_one(m);
}

void combat_event_scene_two(main_t *m)
{
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyDown
        && get_rect(m, SP_COMBAT[4]).top == resize_top(m, 480))
        sfSprite_move(SP_COMBAT[4], (sfVector2f){0, 40});
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyUp
        && get_rect(m, SP_COMBAT[4]).top == resize_top(m, 520))
        sfSprite_move(SP_COMBAT[4], (sfVector2f){0, -40});
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyRight
        && get_rect(m, SP_COMBAT[4]).left == resize_left(m, 50))
        sfSprite_move(SP_COMBAT[4], (sfVector2f){220, 0});
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyLeft
        && get_rect(m, SP_COMBAT[4]).left == resize_left(m, 270))
        sfSprite_move(SP_COMBAT[4], (sfVector2f){-220, 0});
    combat_event_enter_scene_two(m);
}
