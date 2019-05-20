/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** event
*/

#include "rpg.h"
#include "my.h"

static void event_scene_two(main_t *m)
{
    if (STATE_GAME == true) {
        event_pause(m);
        if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyEnter)
            STATE_GAME = false;
    } else if (SCENE_TEXT == true) {
        if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyE)
            m->game->chat += 1;
    } else if (m->game->direction == 'n' && m->my_game->fight == false) {
        move_sacha(m);
        event_key_code(m);
        if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyEnter)
            STATE_GAME = true;
    }
}

void game_scene_six_bis(main_t *m)
{
    if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyDown) {
        if (m->game->move_arrow.y == 288)
            m->game->move_arrow.y += 60;
        else
            m->game->move_arrow.y -= 60;
    } else if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyEnter
    && m->game->move_arrow.y == 288) {
        if (m->game->rect_pokemon.top == 585)
            init_pokemon(m, 0);
        if (m->game->rect_pokemon.top == 650)
            init_pokemon(m, 1);
        if (m->game->rect_pokemon.top == 715)
            init_pokemon(m, 2);
        GAME_SCENE = 2;
        SCENE_TEXT = true;
        m->game->pnj = 2;
    }
}

void game_scene_six(main_t *m)
{
    if (EVENT.type == sfEvtKeyPressed &&
    EVENT.key.code == sfKeyRight) {
        if (m->game->rect_pokemon.top >= 715)
            m->game->rect_pokemon.top = 585;
        else
            m->game->rect_pokemon.top += 65;
    } else if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyLeft) {
        if (m->game->rect_pokemon.top > 585)
            m->game->rect_pokemon.top -= 65;
        else
            m->game->rect_pokemon.top = 715;
    } else if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyUp) {
        if (m->game->move_arrow.y == 348)
            m->game->move_arrow.y -= 60;
        else
            m->game->move_arrow.y += 60;
    } else
        game_scene_six_bis(m);
}

void event_bag(main_t *m)
{
    if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyBackspace)
        GAME_SCENE = OLD_GAME_SCENE;
}

void event_game(main_t *m)
{
    char *ch_scene[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", NULL};
    void (*scene[9])(main_t *) = {event_scene_zero, event_scene_one,
        event_scene_two, event_scene_three, game_scene_four, game_scene_five,
        game_scene_six, event_inventory, event_bag};
    if (EVENT.type == sfEvtClosed) {
        my_destroy(m);
        exit(0);
    }
    for (int i = 0; ch_scene[i] != NULL; i += 1)
        my_strcmp(ch_scene[i], my_itoa(GAME_SCENE)) == 0 ? scene[i](m) : 0;
}
