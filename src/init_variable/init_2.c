/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_2
*/

#include "rpg.h"
#include "my.h"

static const int pos_combat_text[24] = {
    75,
    480,
    75,
    520,
    70,
    107,
    297,
    107,
    458,
    320,
    677,
    320,
    604,
    380,
    670,
    380,
    298,
    480,
    298,
    520,
    465,
    480,
    465,
    520,
};

void init_text_combat(main_t *m)
{
    m->combat->font = sfFont_createFromFile("utils/Font/pokemon.ttf");
    for (int i = 0; i != 12; i++) {
        TXT_COMBAT[i] = sfText_create();
        sfText_setFont(TXT_COMBAT[i], m->combat->font);
        sfText_setCharacterSize(TXT_COMBAT[i], 15);
        sfText_setPosition(TXT_COMBAT[i], (sfVector2f){pos_combat_text[i * 2],
            pos_combat_text[(i * 2) + 1]});
        sfText_setColor(TXT_COMBAT[i], sfBlack);
    }
    sfText_setCharacterSize(TXT_COMBAT[0], 23);
    sfText_setCharacterSize(TXT_COMBAT[1], 23);
    sfText_setCharacterSize(TXT_COMBAT[8], 23);
    sfText_setCharacterSize(TXT_COMBAT[9], 23);
    sfText_setCharacterSize(TXT_COMBAT[10], 23);
    sfText_setCharacterSize(TXT_COMBAT[11], 23);
}

void init_map_txt(main_t *m, const char *str)
{
    int f = open(str, O_RDONLY);
    struct stat ststat;
    char *buffer = NULL;

    stat(str, &ststat);
    buffer = malloc(sizeof(char) * (ststat.st_size + 1));
    read(f, buffer, ststat.st_size);
    buffer[ststat.st_size] = '\0';
    MAP = my_str_to_tab(buffer, '\n');
    VER = 72;
    HOR = 86;
}

void init_combat(main_t *m)
{
    for (size_t i = 0; i < 7; i++) {
        m->combat->pokemon[0]->pokemon[i] = 1001;
        m->combat->pokemon[1]->pokemon[i] = 1001;
        m->combat->pokemon[0]->pokemon_lvl[i] = 1001;
        m->combat->pokemon[1]->pokemon_lvl[i] = 1001;
        m->combat->pokemon[0]->pokemon_pv[i] = 1001;
        m->combat->pokemon[1]->pokemon_pv[i] = 1001;
        m->combat->pokemon[0]->pokemon_pv_max[i] = 1001;
        m->combat->pokemon[1]->pokemon_pv_max[i] = 1001;
        m->combat->pokemon[0]->pokemon_xp[i] = 0;
        m->combat->pokemon[1]->pokemon_xp[i] = 0;
    }
}
