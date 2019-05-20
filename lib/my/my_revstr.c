/*
** EPITECH PROJECT, 2018
** revstr
** File description:
** revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char c;

    if (str == NULL)
        return (str);
    else
        i = my_strlen(str);

    while (j < (i - 1)) {
        c = str[j];
        str[j] = str[i - 1];
        str[i - 1] = c;
        i--;
        j++;
    }
    return (str);
}
