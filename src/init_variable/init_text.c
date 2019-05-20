/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** init_.c
*/

#include "rpg.h"
#include "my.h"

const char *text[] = {
    "FRAMERATE",
    "30",
    "60",
    "144",
    "VOLUME",
    "0",
    "50",
    "100",
    "RESUME",
    "HOW TO PLAY",
    "POKE BALL",
    "POTION",
    "Restores the HP of\na POKEMON by\n 20 points",
    "A tool used for \ncatching wild\nPOKEMON",
    NULL
};

static char *menu_intro_sprite[] = {
    "./utils/Texture/menu.png",
    "./utils/Texture/option.png",
    "./utils/Texture/cadre.png",
    "./utils/Texture/htp.png",
    "./utils/Texture/menu_game.png",
    "./utils/Texture/select.png",
    "./utils/Texture/Txt.png",
    NULL
};

void init_font_and_color(main_t *m, int i)
{
    TEXT[i] = sfText_create();
    sfText_setFont(TEXT[i], FONT);
    sfText_setString(TEXT[i], text[i]);
    sfText_setColor(TEXT[i], sfBlack);
    if (i == 0 || i == 4 || i == 8 || i == 9)
        sfText_setColor(TEXT[i], (sfColor){27, 163, 64, 255});
    if (i == 2 || i == 7)
        sfText_setColor(TEXT[i], (sfColor){247, 47, 3, 255});
    sfText_setCharacterSize(TEXT[i], 75);
}

void init_text(main_t *m)
{
    m->game->tx_textbox = sfTexture_createFromFile(menu_intro_sprite[6], NULL);
    FONT = sfFont_createFromFile("./utils/Font/font.ttf");
    m->game->str = NULL;
    m->game->bloc = sfText_create();
    sfText_setString(m->game->bloc, m->game->str);
    sfText_setFont(m->game->bloc, FONT);
    sfText_setCharacterSize(m->game->bloc, 30);
    m->game->sp_textbox = sfSprite_create();
    sfText_setColor(m->game->bloc, sfBlack);
    sfSprite_setTexture(m->game->sp_textbox, m->game->tx_textbox, sfTrue);
    for (int i = 0; i < NB_TEXT_OPTION; i++)
        init_font_and_color(m, i);
}

void init_text_inventory(main_t *m)
{
    m->menu_intro->font = sfFont_createFromFile("./utils/Font/font.ttf");
    for (int i = 0; i < NB_TEXT_OPTION; i++) {
        TEXT[i] = sfText_create();
        sfText_setFont(TEXT[i], FONT);
        sfText_setString(TEXT[i], text[i]);
        sfText_setColor(TEXT[i], sfBlack);
        if (i == 0 || i == 4 || i == 8 || i == 9)
            sfText_setColor(TEXT[i], (sfColor){27, 163, 64, 255});
        if (i == 2 || i == 7)
            sfText_setColor(TEXT[i], (sfColor){247, 47, 3, 255});
        sfText_setCharacterSize(TEXT[i], 75);
        if (i == 10 || i == 11)
            sfText_setCharacterSize(TEXT[i], 70);
        if (i > 11)
            sfText_setCharacterSize(TEXT[i], 50);
    }
}

void init_variable_intro_menu(main_t *m)
{
    m->menu_intro->rect = (sfIntRect) {0, 0, 800, 600};
    m->game->coord = 185;
    m->game->pos = 1;
    for (size_t i = 0; i < NB_SP_MENU_INTRO; i++) {
        TX_MENU_INTRO[i] = sfTexture_createFromFile(menu_intro_sprite[i], NULL);
        SP_MENU_INTRO[i] = sfSprite_create();
        sfSprite_setTexture(SP_MENU_INTRO[i], TX_MENU_INTRO[i], sfTrue);
        if (i == 0)
            sfSprite_setTextureRect(SP_MENU_INTRO[i], m->menu_intro->rect);
    }
}
