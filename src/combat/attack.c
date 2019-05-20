/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** event
*/

#include "rpg.h"
#include "my.h"

static void at_player(main_t *m, int deg, char *attack)
{
    m->combat->pokemon[1]->pokemon_pv[m->combat->pokemon_our] -= deg;
    sfText_setString(TXT_COMBAT[0], "Ennemy pokemon used");
    sfText_setString(TXT_COMBAT[1], attack);
    sfText_setString(TXT_COMBAT[6],
    my_itoa(m->combat->pokemon[1]->pokemon_pv[m->combat->pokemon_our]));
    COMBAT_SCENE = 3;
}

static void at_ennemie(main_t *m, int deg, char *attack)
{
    m->combat->pokemon[0]->pokemon_pv[m->combat->pokemon_en] -= deg;
    R_COMBAT[0].left = 0;
    sfSprite_setTextureRect(SP_COMBAT[0], R_COMBAT[0]);
    sfText_setString(TXT_COMBAT[0], "Your pokemon used");
    sfText_setString(TXT_COMBAT[1], attack);
    sfText_setString(TXT_COMBAT[8], " ");
    sfText_setString(TXT_COMBAT[9], " ");
    sfText_setString(TXT_COMBAT[10], " ");
    sfText_setString(TXT_COMBAT[11], " ");
    sfSprite_setPosition(SP_COMBAT[4], (sfVector2f){437, 480});
    COMBAT_SCENE = 3;
}

char *get_attack(main_t *m, int pok, int nb)
{
    char *attack;
    int nbr = m->combat->pokemon_our;

    if (pok == 0)
        nbr = m->combat->pokemon_en;
    attack = get_info(m, m->combat->pokemon[pok]->pokemon[nbr], nb);
    if (m->combat->pokemon[pok]->pokemon_lvl[nbr]
        < my_atoi(get_info(m,
        m->combat->pokemon[pok]->pokemon[nbr], (nb + 9))))
        return ("-");
    return (attack);
}

void attack_choice(main_t *m, int pok, int nb)
{
    char *attack = get_attack(m, pok, nb);
    char *att[26] = {"Sonic", "Growl", "Leer", "Sand", "Splash", "Howl",
        "Tail", "Constric", "Poison", "Pound", "Absorb", "Quick", "Scratch",
        "Ember", "Tackle", "Water", "Acid", "Wing", "Bite", "Mud", "Rollout",
        "Roar", "AirSlash", "HypeBeam", "Ultraser", NULL};
    int deg[25] = {10, 10, 10, 10, 10, 10, 10, 10, 15, 20, 20, 20, 20, 20,
        20, 20, 20, 30, 30, 30, 30, 20, 40, 60, 80};

    if (my_strcmp("-", attack) == 0)
        return;
    if (pok == 1) {
        for (int i = 0; att[i] != NULL; i++)
            my_strcmp(att[i], attack) == 0 ? at_ennemie(m, deg[i], attack) : 0;
    }
    if (pok == 0) {
        for (int i = 0; att[i] != NULL; i++)
            my_strcmp(att[i], attack) == 0 ? at_player(m, deg[i], attack) : 0;
    }
}
