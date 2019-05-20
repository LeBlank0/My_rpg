/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** init_sac.c
*/

#include "rpg.h"
#include "my.h"

char *path_bag[] = {
    "./utils/Texture/sac_pokemon.png",
    "./utils/Texture/ui.png",
    NULL
};

void init_sprite_bag(main_t *m)
{
    init_pokemon(m, 3);
    X_BAG = 125*3.333;
    TX_BAG[0] = sfTexture_createFromFile(path_bag[0], NULL);
    SP_BAG[0] = sfSprite_create();
    sfSprite_setScale(SP_BAG[0], (sfVector2f) {3.333, 3.75});
    sfSprite_setTexture(SP_BAG[0], TX_BAG[0], sfTrue);
    TX_BAG[1] = sfTexture_createFromFile(path_bag[1], NULL);
    for (int i = 1; i < NB_SP_BAG; i++) {
        m->game->rect_box[i] = (sfIntRect) {142, 0, 142, 22};
        SP_BAG[i] = sfSprite_create();
        sfSprite_setTexture(SP_BAG[i], TX_BAG[1], sfTrue);
        sfSprite_setScale(SP_BAG[i], (sfVector2f) {3.333, 3.75});
    }
}

void init_text_infos(main_t *m)
{
    for (int i = 0; i < 6; i++) {
        m->bag->txbag[i]->rect = (sfIntRect) {0, 585, 64, 64};
        m->bag->txbag[i]->sprite = sfSprite_create();
        sfSprite_setTexture(m->bag->txbag[i]->sprite, TX_COMBAT[1], sfTrue);
        m->bag->txbag[i]->name = sfText_create();
        m->bag->txbag[i]->pv = sfText_create();
        m->bag->txbag[i]->pv_max = sfText_create();
        m->bag->txbag[i]->lvl = sfText_create();
        sfText_setFont(m->bag->txbag[i]->name, FONT);
        sfText_setFont(m->bag->txbag[i]->pv, FONT);
        sfText_setFont(m->bag->txbag[i]->pv_max, FONT);
        sfText_setFont(m->bag->txbag[i]->lvl, FONT);
        sfText_setCharacterSize(m->bag->txbag[i]->name, 50);
        sfText_setCharacterSize(m->bag->txbag[i]->pv, 35);
        sfText_setCharacterSize(m->bag->txbag[i]->pv_max, 35);
        sfText_setCharacterSize(m->bag->txbag[i]->lvl, 35);
        sfText_setColor(m->bag->txbag[i]->name, sfBlack);
        sfText_setColor(m->bag->txbag[i]->pv, sfBlack);
        sfText_setColor(m->bag->txbag[i]->lvl, sfBlack);
        sfText_setColor(m->bag->txbag[i]->pv_max, sfBlack);
    }
}
