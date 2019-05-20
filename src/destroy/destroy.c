/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** alloc
*/

#include "rpg.h"
#include "my.h"

void my_destroy_2(main_t *m)
{
    del_sp_and_tx(TX_MENU_INTRO, SP_MENU_INTRO, NB_SP_MENU_INTRO);
    sfFont_destroy(FONT);
    sfMusic_destroy(m->intro->song);
    sfRenderWindow_close(WINDOW);
    free(m->game);
    free(m->intro);
    free(m->menu_intro);
    free(m->settings);
    free(m->my_game);
    free(m);
}

void my_destroy(main_t *m)
{
    free(TX_INTRO);
    free(SP_INTRO);
    free(TX_MENU_INTRO);
    free(SP_MENU_INTRO);
    free(LIST);
    for (size_t i = 0; MAP[i] != NULL; i++)
        free(MAP[i]);
    free(MAP);
    sfTexture_destroy(m->my_game->map_texture);
    sfSprite_destroy(m->my_game->map_sprite);
    sfTexture_destroy(m->my_game->sacha_texture);
    sfSprite_destroy(m->my_game->sacha_sprite);
    for (size_t i = 0; i < NB_TEXT_OPTION; i++)
        sfText_destroy(TEXT[i]);
    free(TEXT);
    del_sp_and_tx(TX_INTRO, SP_INTRO, NB_SP_INTRO);
    my_destroy_2(m);
}
