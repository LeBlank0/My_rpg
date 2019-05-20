/*
** EPITECH PROJECT, 2018
** rect
** File description:
** defender game rect
*/

#include "rpg.h"
#include "my.h"

sfIntRect get_rect(main_t *m, sfSprite *sprite)
{
    sfIntRect rect;

    rect.left = (((sfSprite_getGlobalBounds(sprite)).left
    / 800.0) * (sfRenderWindow_getSize(WINDOW)).x);
    rect.width = (((sfSprite_getGlobalBounds(sprite)).width
    / 800.0) * (sfRenderWindow_getSize(WINDOW)).x);
    rect.top = (((sfSprite_getGlobalBounds(sprite)).top
    / 600.0) * (sfRenderWindow_getSize(WINDOW)).y);
    rect.height = (((sfSprite_getGlobalBounds(sprite)).height
    / 600.0) * (sfRenderWindow_getSize(WINDOW)).y);
    return (rect);
}
