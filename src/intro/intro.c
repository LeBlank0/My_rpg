/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** intro
*/

#include "rpg.h"
#include "my.h"

static void set_frame(main_t *m)
{
    m->intro->rect.left += 540;
    if (INTRO_SC == 0 && m->intro->rect.left >= 8640 &&
    m->intro->rect.top >= 8640) {
        m->intro->rect.left = 0;
        m->intro->rect.top = 0;
        INTRO_SC = 1;
    }
    else if (INTRO_SC == 1 && m->intro->rect.left >= 3780 &&
    m->intro->rect.top >= 8640) {
        m->intro->rect.left = 3780;
        m->intro->rect.top = 4860;
    }
    else if (m->intro->rect.left >= 8640) {
        m->intro->rect.left = 0;
        m->intro->rect.top += 540;
    }
}

int intro_emerald(main_t *m)
{
    static float clock_intro = 0;

    clock_intro += TIME;
    if (clock_intro > 0.116667) {
        clock_intro = 0;
        set_frame(m);
        sfSprite_setTextureRect(m->intro->sprite[INTRO_SC], m->intro->rect);
    }
    sfRenderWindow_drawSprite(WINDOW, SP_INTRO[INTRO_SC], NULL);
    return (0);
}
