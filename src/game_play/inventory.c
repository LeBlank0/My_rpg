/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** inventory.c
*/

#include "rpg.h"
#include "my.h"

int inventory(main_t *m)
{
    for (int i = 0; i < NB_INVENTORY; i++) {
        sfRenderWindow_drawSprite(WINDOW, SP_INVENTORY[i], NULL);
        if (i == 1) {
            sfSprite_setPosition(SP_INVENTORY[i], (sfVector2f) {30, 270});
            sfSprite_setTextureRect(SP_INVENTORY[i], RECT_ITEM);
        }
    }
    sfRenderWindow_drawSprite(WINDOW, SP_MENU_INTRO[5], NULL);
    sfSprite_setPosition(SP_MENU_INTRO[5], (sfVector2f) {380, m->inv->coord});
    set_pos_text(m);
    for (int i = 10; i < NB_TEXT_OPTION - 3; i++)
        sfRenderWindow_drawText(WINDOW, TEXT[i], NULL);
    if (RECT_ITEM.left == 18)
        sfRenderWindow_drawText(WINDOW, TEXT[12], NULL);
    else
        sfRenderWindow_drawText(WINDOW, TEXT[13], NULL);
    return (0);
}