/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** event_inventory
*/

#include "rpg.h"
#include "my.h"

void event_inventory(main_t *m)
{
    if (m->game->event.type == sfEvtKeyReleased &&
    m->game->event.key.code == sfKeyBackspace) {
        GAME_SCENE = OLD_GAME_SCENE;
        m->inv->cas = 0;
    }
    if (m->game->event.type == sfEvtKeyReleased &&
    m->game->event.key.code == sfKeyDown) {
        RECT_ITEM.left = 18;
        m->inv->coord = 160;
    }
    if (m->game->event.type == sfEvtKeyReleased &&
    m->game->event.key.code == sfKeyE && RECT_ITEM.left == 18 &&
    OLD_GAME_SCENE == 4) {
        m->inv->cas = 2;
        GAME_SCENE = OLD_GAME_SCENE;
    }
    if (m->game->event.type == sfEvtKeyReleased &&
    m->game->event.key.code == sfKeyUp) {
        RECT_ITEM.left = 0;
        m->inv->coord = 95;
    }
    if (m->game->event.type == sfEvtKeyReleased &&
    m->game->event.key.code == sfKeyE && RECT_ITEM.left == 0
    && get_poke_nb(m, 1) <= 6 && m->game->fight_npc == false) {
        m->inv->cas = 1;
        GAME_SCENE = OLD_GAME_SCENE;
    }
}
