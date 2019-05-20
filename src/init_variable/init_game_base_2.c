/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_game_base_2
*/

#include "rpg.h"
#include "my.h"

void init_map(main_t *m)
{
    m->my_game->map_sprite = sfSprite_create();
    m->my_game->map_texture =
    sfTexture_createFromFile("./utils/Texture/map.png", NULL);
    sfSprite_setTexture(m->my_game->map_sprite, m->my_game->map_texture,
    sfTrue);
    m->my_game->rect_map = (sfIntRect){0, 0, 3000, 1535};
    sfSprite_setTextureRect(m->my_game->map_sprite, m->my_game->rect_map);
    sfSprite_setScale(m->my_game->map_sprite, (sfVector2f){3.5, 3.5});
    sfSprite_setPosition(m->my_game->map_sprite, (sfVector2f){-800, -380});
}

void init_map2(main_t *m)
{
    m->my_game->map_sprite2 = sfSprite_create();
    m->my_game->map_texture2 =
    sfTexture_createFromFile("./utils/Texture/map_2.png", NULL);
    sfSprite_setTexture(m->my_game->map_sprite2, m->my_game->map_texture2,
    sfTrue);
    sfSprite_setTextureRect(m->my_game->map_sprite2, m->my_game->rect_map);
    sfSprite_setScale(m->my_game->map_sprite2, (sfVector2f){3.5, 3.5});
    sfSprite_setPosition(m->my_game->map_sprite2, (sfVector2f){-800, -380});
}

void init_sacha(main_t *m)
{
    int file = open("utils/map_txt/pokemon", O_RDONLY);
    char *buff = malloc(sizeof(char) * (6000));

    read(file, buff, 6000);
    LIST = my_str_to_tab(buff, '\n');
    m->my_game->sacha_sprite = sfSprite_create();
    m->my_game->sacha_texture =
    sfTexture_createFromFile("./utils/Texture/14_21.png", NULL);
    sfSprite_setTexture(m->my_game->sacha_sprite, m->my_game->sacha_texture,
    sfTrue);
    m->my_game->rect_sacha = (sfIntRect){0, 0, 14, 21};
    sfSprite_setTextureRect(m->my_game->sacha_sprite, m->my_game->rect_sacha);
    sfSprite_setScale(m->my_game->sacha_sprite, (sfVector2f){3.5, 3.5});
    m->my_game->move_left_right = -(1801 * 3.5) + 385;
    m->my_game->move_top_bottom = -(1229 * 3.5) + 200;
    sfSprite_setPosition(m->my_game->sacha_sprite, (sfVector2f) {385, 200});
    m->my_game->pers_move_restart = 0;
}
