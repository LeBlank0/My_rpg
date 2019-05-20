/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** alloc
*/

#include "rpg.h"
#include "my.h"

static void allocation_sucs(main_t *m)
{
    TXT_COMBAT = malloc(sizeof(sfText*) * 12);
    TX_COMBAT = malloc(sizeof(sfTexture*) * NB_SP_COMBAT);
    SP_COMBAT = malloc(sizeof(sfSprite*) * NB_SP_COMBAT);
    R_COMBAT = malloc(sizeof(sfIntRect) * NB_SP_COMBAT);
    TX_INTRO = malloc(sizeof(sfTexture*) * NB_SP_INTRO);
    SP_INTRO = malloc(sizeof(sfSprite*) * NB_SP_INTRO);
    TX_MENU_INTRO = malloc(sizeof(sfTexture*) * NB_SP_MENU_INTRO);
    SP_MENU_INTRO = malloc(sizeof(sfSprite*) * NB_SP_MENU_INTRO);
    TEXT = malloc(sizeof(sfText *) * NB_TEXT_OPTION);
    TEXT_BAG = malloc(sizeof(sfText *) * NB_INFO_BAG);
    SP_MOBS = malloc(sizeof(sfSprite *) * NB_MOBS);
    MOVE_MOBS = malloc(sizeof(int) * NB_MOBS * 2);
    TX_INVENTORY = malloc(sizeof(sfTexture*) * NB_INVENTORY);
    SP_INVENTORY = malloc(sizeof(sfSprite*) * NB_INVENTORY);
    TX_BAG = malloc(sizeof(sfTexture *) * NB_SP_BAG);
    SP_BAG = malloc(sizeof(sfSprite *) * NB_SP_BAG);
    m->my_game->rect_mobs = malloc(sizeof(sfIntRect) * 2);
    m->game->rect_box = malloc(sizeof(sfIntRect) * NB_SP_BAG);
    m->game->fighted = malloc(sizeof(int) * 9);
}

static void combat_alloc(main_t *m)
{
    m->combat->pokemon = malloc(sizeof(pokemon_t*) * 2);
    m->combat->pokemon[0] = malloc(sizeof(pokemon_t));
    m->combat->pokemon[1] = malloc(sizeof(pokemon_t));
    m->combat->pokemon[0]->pokemon = malloc(sizeof(int)*7);
    m->combat->pokemon[1]->pokemon = malloc(sizeof(int)*7);
    m->combat->pokemon[0]->pokemon_lvl = malloc(sizeof(int)*7);
    m->combat->pokemon[1]->pokemon_lvl = malloc(sizeof(int)*7);
    m->combat->pokemon[0]->pokemon_pv = malloc(sizeof(int)*7);
    m->combat->pokemon[1]->pokemon_pv = malloc(sizeof(int)*7);
    m->combat->pokemon[0]->pokemon_pv_max = malloc(sizeof(int)*7);
    m->combat->pokemon[1]->pokemon_pv_max = malloc(sizeof(int)*7);
    m->combat->pokemon[0]->pokemon_xp = malloc(sizeof(int)*7);
    m->combat->pokemon[1]->pokemon_xp = malloc(sizeof(int)*7);
}

void alloc_info_text(main_t *m)
{
    m->bag->txbag = malloc(sizeof(txbag_t*) * 6);
    for (int i = 0; i < 6; i++) {
        m->bag->txbag[i] = malloc(sizeof(txbag_t));
        m->bag->txbag[i]->lvl = malloc(sizeof(sfText *));
        m->bag->txbag[i]->name = malloc(sizeof(sfText *));
        m->bag->txbag[i]->pv = malloc(sizeof(sfText *));
        m->bag->txbag[i]->pv_max = malloc(sizeof(sfText *));
    }
}

void rpg_malloc(main_t *m)
{
    m->game = malloc(sizeof(game_t));
    m->intro = malloc(sizeof(intro_t));
    m->menu_intro = malloc(sizeof(menu_intro_t));
    m->settings = malloc(sizeof(settings_t));
    m->my_game = malloc(sizeof(my_game_t));
    m->combat = malloc(sizeof(combat_t));
    m->inv = malloc(sizeof(inventory_t));
    m->bag = malloc(sizeof(bag_t));
    combat_alloc(m);
    allocation_sucs(m);
    alloc_info_text(m);
}
