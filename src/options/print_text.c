/*
** EPITECH PROJECT, 2018
** rect
** File description:
** defender game rect
*/

#include "rpg.h"
#include "my.h"

static void reset_text(main_t *m)
{
    m->game->str = NULL;
    m->game->chat = 0;
    SCENE_TEXT = false;
}

static void show_text(main_t *m)
{
    sfSprite_setPosition(m->game->sp_textbox, (sfVector2f) {0, 460});
    sfRenderWindow_drawSprite(WINDOW, m->game->sp_textbox, NULL);
    sfText_setCharacterSize(m->game->bloc, 45);
    sfText_setPosition(m->game->bloc, (sfVector2f) {30, 472});
    sfRenderWindow_drawText(WINDOW, m->game->bloc, NULL);
}

void print_text(char *sen, main_t *m)
{
    static float the_time = 0;
    static float time_tot = 0;
    the_time += TIME;
    time_tot += TIME;

    if (my_strcmp(m->game->str, sen) == 0 && m->game->chat == 1 && time_tot > 2)
        m->game->chat = 2;
    if (m->game->chat == 1)
        m->game->str = sen;
    else if (the_time > 0.02) {
        the_time = 0;
        m->game->str = add_char_to_str(m->game->str, sen, m->game->chat);
    }
    sfText_setString(m->game->bloc, m->game->str);
    if (time_tot > 3 || m->game->chat >= 2) {
        m->game->str = add_char_to_str(m->game->str, sen, 2);
        the_time = 0;
        time_tot = 0;
        reset_text(m);
    }
    show_text(m);
}