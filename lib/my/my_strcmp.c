/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** function that compares the size of two string
*/

#include "my.h"

int my_strcmp(const char *s1, const char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return (1);

    for (size_t i = 0; s1[i]; i++)
        if (s1[i] != s2[i])
            return (1);
    for (size_t i = 0; s2[i]; i++)
        if (s2[i] != s1[i])
            return (1);
    return (0);
}