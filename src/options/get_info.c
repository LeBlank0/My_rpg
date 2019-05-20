/*
** EPITECH PROJECT, 2018
** rect
** File description:
** defender game rect
*/

#include "rpg.h"
#include "my.h"

char *get_info(main_t *m, int line, int pos)
{
    char *res = NULL;
    int i = 0;
    int y = 0;

    for (; LIST[line][i + pos] != ' '
    && LIST[line][i + pos] != '\n'
    && LIST[line][i + pos] != '\0'; i++);
    res = malloc(sizeof(char) * (i + 1));
    for (; LIST[line][y + pos] != ' '
        && LIST[line][y + pos] != '\n'
        && LIST[line][y + pos] != '\0'; y++)
        res[y] = LIST[line][y + pos];
    res[y] = '\0';
    return (res);
}
