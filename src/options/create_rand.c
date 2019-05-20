/*
** EPITECH PROJECT, 2018
** rect
** File description:
** defender game rect
*/

#include "rpg.h"
#include "my.h"

void create_rand(void)
{
    int fd = open("/dev/urandom", O_RDONLY);
    unsigned seed;

    read(fd, &seed, sizeof seed);
    srand(seed);
    close(fd);
}
