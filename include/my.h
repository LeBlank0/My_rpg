/*
** EPITECH PROJECT, 2018
** my_rpg_2018
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

char *get_file(char *str);
char *my_itoa(int nb);
char *my_revstr(char *str);
char **my_str_to_tab(char *str, char c);
int my_strlen(char const *str);
int my_strcmp(const char *s1, const char *s2);
int my_putstr(char const *str);
int my_atoi(char *ato_i);
void del_sp_and_tx(sfTexture **texture, sfSprite **sprite, size_t index);
char *add_char_to_str(char *str, char const *sentence, int chat);

#endif /* MY_H_ */
