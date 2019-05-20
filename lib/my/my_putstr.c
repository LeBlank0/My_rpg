/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** funcions that displays one by one character of a string
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return (0);
}