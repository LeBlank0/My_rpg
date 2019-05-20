/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** my_atoi
*/

#include "my.h"

int my_atoi(char *ato_i)
{
    int tmp = 0;
    int i = 0;

    while (ato_i[i]) {
        tmp = 10 * tmp + ato_i[i] - '0';
        i += 1;
    }

    return (tmp);
}