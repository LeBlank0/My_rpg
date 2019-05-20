/*
** EPITECH PROJECT, 2018
** addchartostr
** File description:
** addchartostr
*/

#include "my.h"

char *add_char_to_str(char *str, char const *sentence, int chat)
{
    static size_t change = 1;
    if (chat == 2)
        change = 0;
    if (change > strlen(sentence))
        return (str);
    str = malloc(sizeof(char) * (change + 1));
    for (size_t i = 0; i < change; i++)
        str[i] = sentence[i];
    str[change] = '\0';
    change++;
    return (str);
}