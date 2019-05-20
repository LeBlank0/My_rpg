/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init
*/

#include "rpg.h"
#include "my.h"

char *inventory_sprite[] = {
    "./utils/Texture/inventory.png",
    "./utils/Texture/item.png",
    "./utils/Texture/select.png",
    "./utils/Texture/choosepokemon.png",
    NULL
};

void init_inventory(main_t *m)
{
    TX_INVENTORY = malloc(sizeof(sfTexture*) * NB_INVENTORY);
    SP_INVENTORY = malloc(sizeof(sfSprite*) * NB_INVENTORY);
    RECT_ITEM = (sfIntRect) {0, 0, 18, 21};
    m->inv->coord = 95;
    for (int i = 0; i < NB_INVENTORY; i++){
        TX_INVENTORY[i] = sfTexture_createFromFile(inventory_sprite[i], NULL);
        SP_INVENTORY[i] = sfSprite_create();
        sfSprite_setTexture(SP_INVENTORY[i], TX_INVENTORY[i], sfTrue);
        if (i == 1)
            sfSprite_setScale(SP_INVENTORY[i], (sfVector2f) {4, 4});
    }
    init_text_inventory(m);
}

void init_choice(main_t *m)
{
    m->game->tx_arrow = sfTexture_createFromFile(inventory_sprite[2], NULL);
    m->game->tx_choice = sfTexture_createFromFile(inventory_sprite[3], NULL);
    m->game->sp_choice = sfSprite_create();
    m->game->sp_arrow = sfSprite_create();
    m->game->pokemon_choice = sfSprite_create();
    sfSprite_setTexture(m->game->pokemon_choice, TX_COMBAT[1], sfTrue);
    sfSprite_setTextureRect(m->game->pokemon_choice, m->game->rect_pokemon);
    sfSprite_setPosition(m->game->pokemon_choice, (sfVector2f) {320, 130});
    sfSprite_setScale(m->game->pokemon_choice, (sfVector2f) {2.75, 2.75});
    sfSprite_setTexture(m->game->sp_choice, m->game->tx_choice, sfTrue);
    sfSprite_setTexture(m->game->sp_arrow, m->game->tx_arrow, sfTrue);
    sfSprite_setScale(m->game->sp_arrow, (sfVector2f) {1, 1});
    sfSprite_setPosition(m->game->sp_arrow, m->game->move_arrow);
}