/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** my_atoi
*/

#include "my.h"

void del_sp_and_tx(sfTexture **texture, sfSprite **sprite, size_t index)
{
    for (size_t i = 0; i < index; i++) {
        sfTexture_destroy(texture[i]);
        sfSprite_destroy(sprite[i]);
    }
    free(texture);
    free(sprite);
}
