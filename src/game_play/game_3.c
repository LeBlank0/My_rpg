/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** game_3
*/

#include "rpg.h"
#include "my.h"

void move_right(main_t *m, float *timer)
{
    static int enter = 0;
    if (enter == 4) {
        enter = 0;
        *timer = 0;
        m->game->the_move--;
        HOR += 1;
        if (m->game->the_move <= 0) {
            m->game->the_move = 0;
            m->game->old_direction = 'r';
            m->game->direction = 'n';
            return;
        }
    }
    if (*timer >= 0.02) {
        m->my_game->move_left_right -= 14;
        *timer = 0;
        enter++;
    }
}

void move_left(main_t *m, float *timer)
{
    static int enter = 0;
    if (enter == 4) {
        enter = 0;
        *timer = 0;
        m->game->the_move--;
        HOR -= 1;
        if (m->game->the_move <= 0) {
            m->game->the_move = 0;
            m->game->old_direction = 'l';
            m->game->direction = 'n';
            return;
        }
    }
    if (*timer >= 0.02) {
        m->my_game->move_left_right += 14;
        *timer = 0;
        enter++;
    }
}

void move_charac(main_t *m)
{
    static float time_movement = 0;
    if (m->game->direction != 'n') {
        time_movement += TIME;
        if (m->game->direction == 'u')
            move_up(m, &time_movement);
        if (m->game->direction == 'd')
            move_down(m, &time_movement);
        if (m->game->direction == 'r')
            move_right(m, &time_movement);
        if (m->game->direction == 'l')
            move_left(m, &time_movement);
    }
    else if (m->game->direction == 'n') {
        if (m->game->old_direction == 'u') {
            m->my_game->rect_sacha.top = 0;
            m->my_game->rect_sacha.left = 14;
        }
        if (m->game->old_direction == 'd') {
            m->my_game->rect_sacha.top = 0;
            m->my_game->rect_sacha.left = 0;
        }
        if (m->game->old_direction == 'r') {
            m->my_game->rect_sacha.top = 0;
            m->my_game->rect_sacha.left = 42;
        }
        if (m->game->old_direction == 'l') {
            m->my_game->rect_sacha.top = 0;
            m->my_game->rect_sacha.left = 28;
        }
        sfSprite_setTextureRect(m->my_game->sacha_sprite,
        m->my_game->rect_sacha);
    }
}

void game_play_bis(main_t *m)
{
    ia_move(m);
    for (size_t i = 0; i != NB_MOBS; i++)
        sfRenderWindow_drawSprite(WINDOW, SP_MOBS[i], NULL);
    move_charac(m);
    sfRenderWindow_drawSprite(WINDOW, m->my_game->ia_sprite, NULL);
    if (MAP[VER][HOR] == '8')
        sfRenderWindow_drawSprite(WINDOW, m->my_game->sp_sacha_swim, NULL);
    else
        sfRenderWindow_drawSprite(WINDOW, m->my_game->sacha_sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, m->my_game->map_sprite2, NULL);
    sfSprite_setPosition(m->my_game->map_sprite2, (sfVector2f)
    {m->my_game->move_left_right, m->my_game->move_top_bottom});
    if (SCENE_TEXT == true) {
        game_play_bis_3(m);
        if (m->game->pnj == 9 && m->game->fighted[3] == 0) {
            print_text("Hello, I'm the boss of the arena\n"
            "Do you really think you can beat me ?!\0", m);
            m->my_game->fight = true;
            m->game->fight_npc = true;
        }
        if (m->game->pnj == 9 && m->game->fighted[3] == 1)
            print_text("You have now the abitity to swim,\n"
            "Good luck for the rest of your trip!\0", m);
        if (m->game->pnj == 10 && m->game->fighted[4] == 0) {
            print_text("I'm the first kid of the forest !!\n"
            " you can't beat me\0", m);
            m->my_game->fight = true;
            m->game->fight_npc = true;
        }
        if (m->game->pnj == 11 && m->game->fighted[5] == 0) {
            print_text("Do you really think you can pass the "
            "forest alive ?\0", m);
            m->my_game->fight = true;
            m->game->fight_npc = true;
        }
        if (m->game->pnj == 12 && m->game->fighted[6] == 0) {
            print_text("I'm the king of the kid !!\n you can't beat me\0", m);
            m->my_game->fight = true;
            m->game->fight_npc = true;
        }
        if (m->game->pnj == 13 && m->game->fighted[7] == 0) {
            print_text("You are near the next town!!\n "
            "but i wont let you pass like this \0", m);
            m->my_game->fight = true;
            m->game->fight_npc = true;
        }
        if (m->game->pnj == 97)
            print_text("I have been told that a mistery monster \n"
            "is in the North after you crossed the water !\0", m);
        if (m->game->pnj == 98) {
            print_text("RAY!\nRAYYYYYYYYYYYYYYYYYYYYYY !!!\0", m);
            m->my_game->fight = true;
            m->game->fight_npc = true;
        }
        if (m->game->pnj == 99)
            print_text("Choose your pokemon whysely\n"
            "It is illegal to throw them.\0", m);
    } if (STATE_GAME == true)
        menu_pause(m);
}

void modifyfight(main_t *m)
{
    if (m->game->pnj == 3) {
        MAP[33][82] = '0';
        MAP[34][82] = '0';
        m->my_game->rect_mobs[1].left += 32;
        sfSprite_setTextureRect(SP_MOBS[3], m->my_game->rect_mobs[1]);
        sfSprite_setTextureRect(SP_MOBS[4], m->my_game->rect_mobs[1]);
        m->game->fighted[8] = 1;
    }
    if (m->game->pnj == 6)
        m->game->fighted[0] = 1;
    if (m->game->pnj == 7)
        m->game->fighted[1] = 1;
    if (m->game->pnj == 8)
        m->game->fighted[2] = 1;
    if (m->game->pnj == 9) {
        m->game->fighted[3] = 1;
        m->game->swim = true;
    }
    if (m->game->pnj == 10)
        m->game->fighted[4] = 1;
    if (m->game->pnj == 11)
        m->game->fighted[5] = 1;
    if (m->game->pnj == 12)
        m->game->fighted[6] = 1;
    if (m->game->pnj == 13)
        m->game->fighted[7] = 1;
}
