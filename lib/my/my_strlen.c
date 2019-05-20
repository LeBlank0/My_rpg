/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (i);
    for (; str[i]; i++);
    return (i);
}
