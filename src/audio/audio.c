/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** audio
*/

#include "rpg.h"
#include "my.h"

static void music_fight(main_t *m)
{
    m->intro->song_fight = sfMusic_createFromFile("./utils/Sound/fight.ogg");
    sfMusic_setLoop(m->intro->song_fight, sfTrue);
}

static void music_game(main_t *m)
{
    m->intro->song_game = sfMusic_createFromFile("./utils/Sound/game.ogg");
    sfMusic_setLoop(m->intro->song_game, sfTrue);
}

static void music_rayquaza(main_t *m)
{
    m->intro->song_rayquaza =
    sfMusic_createFromFile("./utils/Sound/rayquaza.ogg");
    sfMusic_setLoop(m->intro->song_rayquaza, sfTrue);
}

void music_intro(main_t *m)
{
    m->intro->song = sfMusic_createFromFile("./utils/Sound/intro.ogg");
    sfMusic_setLoop(m->intro->song, sfTrue);
    sfMusic_play(m->intro->song);
    music_game(m);
    music_rayquaza(m);
    music_fight(m);
}
