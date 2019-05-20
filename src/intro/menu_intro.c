/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** menu_intro
*/

#include "rpg.h"
#include "my.h"

int menu_intro(main_t *m)
{
    sfRenderWindow_setMouseCursorVisible(WINDOW, sfTrue);
    m->menu_intro->pos_mous = sfMouse_getPositionRenderWindow(WINDOW);
    sfSprite_setTextureRect(SP_MENU_INTRO[0], m->menu_intro->rect);
    sfRenderWindow_drawSprite(WINDOW, SP_MENU_INTRO[0], NULL);
    return (0);
}
