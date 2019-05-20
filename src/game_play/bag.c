/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** bag.c
*/

#include "rpg.h"
#include "my.h"

static int coord_y[] = {
    0,
    19*3.75,
    43*3.75,
    67*3.75,
    91*3.75,
    115*3.75,
};

static void file_info(main_t *m, int i)
{
    sfText_setString(m->bag->txbag[i]->name,
    get_info(m, m->combat->pokemon[1]->pokemon[i], 0));
    sfText_setString(m->bag->txbag[i]->pv,
    my_itoa(m->combat->pokemon[1]->pokemon_pv[i]));
    sfText_setString(m->bag->txbag[i]->pv_max,
    my_itoa(m->combat->pokemon[1]->pokemon_pv_max[i]));
    sfText_setString(m->bag->txbag[i]->lvl,
    my_itoa(m->combat->pokemon[1]->pokemon_lvl[i]));
}

static void print_first_pokemon(main_t *m)
{
    print_first_pokemon_2(m);
    sfText_setPosition(m->bag->txbag[0]->lvl, (sfVector2f)
    {51*3.333, 42*3.75});
    sfText_setPosition(m->bag->txbag[0]->pv, (sfVector2f)
    {40*3.333, 59*3.75});
    sfText_setPosition(m->bag->txbag[0]->pv_max, (sfVector2f)
    {66*3.333, 59*3.75});
    sfRenderWindow_drawText(WINDOW, m->bag->txbag[0]->name, NULL);
    sfRenderWindow_drawText(WINDOW, m->bag->txbag[0]->lvl, NULL);
    sfRenderWindow_drawText(WINDOW, m->bag->txbag[0]->pv, NULL);
    sfRenderWindow_drawText(WINDOW, m->bag->txbag[0]->pv_max, NULL);
    sfSprite_setTextureRect(m->bag->txbag[0]->sprite, m->bag->txbag[0]->rect);
    sfRenderWindow_drawSprite(WINDOW, m->bag->txbag[0]->sprite, NULL);
    sfSprite_setPosition(m->bag->txbag[0]->sprite, (sfVector2f)
    {7*3.333, 31*3.75});
}

void bag_else_condition(main_t *m, int coord, int i)
{
    file_info(m, i);
    m->game->rect_box[i].left = 142;
    m->bag->txbag[i]->rect = (sfIntRect){my_atoi(get_info(m,
        m->combat->pokemon[1]->pokemon[i], 75)), (my_atoi(get_info
        (m, m->combat->pokemon[1]->pokemon[i], 70)) + 585), 64, 64};
    sfSprite_setTextureRect(m->bag->txbag[i]->sprite,
    m->bag->txbag[i]->rect);
    sfRenderWindow_drawSprite(WINDOW, m->bag->txbag[i]->sprite, NULL);
    sfSprite_setPosition(m->bag->txbag[i]->sprite, (sfVector2f)
    {93*3.333, coord});
    sfText_setPosition(m->bag->txbag[i]->name, (sfVector2f) {X_BAG - 38,
        coord_y[i] - 50});
    sfText_setPosition(m->bag->txbag[i]->lvl, (sfVector2f) {X_BAG,
        coord_y[i]});
    sfText_setPosition(m->bag->txbag[i]->pv, (sfVector2f) {X_BAG + 240,
        coord_y[i]});
    sfText_setPosition(m->bag->txbag[i]->pv_max, (sfVector2f)
    {X_BAG + 310, coord_y[i]});
}

void before_loop_bag(main_t *m)
{
    m->bag->txbag[0]->rect = (sfIntRect){my_atoi(get_info(m,
        m->combat->pokemon[1]->pokemon[0], 75)), (my_atoi(get_info
        (m, m->combat->pokemon[1]->pokemon[0], 70)) + 585), 64, 64};
    print_first_pokemon(m);
}

int bag(main_t *m)
{
    int y = 34;
    int coord = 10 * 3.75;

    before_loop_bag(m);
    for (int i = 1; i < NB_SP_BAG; i++, y += 90) {
        sfSprite_setTextureRect(SP_BAG[i], m->game->rect_box[i]);
        sfSprite_setPosition(SP_BAG[i], (sfVector2f) {313, y});
        sfRenderWindow_drawSprite(WINDOW, SP_BAG[i], NULL);
        if (m->combat->pokemon[1]->pokemon[i] == 1001) {
            m->game->rect_box[i].left = 0;
        } else {
            bag_else_condition(m, coord, i);
            sfRenderWindow_drawText(WINDOW, m->bag->txbag[i]->name, NULL);
            sfRenderWindow_drawText(WINDOW, m->bag->txbag[i]->lvl, NULL);
            sfRenderWindow_drawText(WINDOW, m->bag->txbag[i]->pv, NULL);
            sfRenderWindow_drawText(WINDOW, m->bag->txbag[i]->pv_max, NULL);
            coord += 90;
        }
    }
    return (0);
}
