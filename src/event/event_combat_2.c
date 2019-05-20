/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** event
*/

#include "rpg.h"
#include "my.h"

static float clo = 0;

static void set_ball(main_t *m)
{
    R_COMBAT[0].left = 0;
    sfSprite_setTextureRect(SP_COMBAT[0], R_COMBAT[0]);
    sfSprite_setPosition(SP_COMBAT[1], (sfVector2f){850, 650});
    sfText_setString(TXT_COMBAT[0], "You touched");
    sfText_setString(TXT_COMBAT[1], "him !");
    sfText_setString(TXT_COMBAT[8], " ");
    sfText_setString(TXT_COMBAT[9], " ");
    sfText_setString(TXT_COMBAT[10], " ");
    sfText_setString(TXT_COMBAT[11], " ");
    m->inv->cas = 0;
    m->my_game->fight = false;
    m->game->fight_npc = false;
    COMBAT_SCENE = 4;
}

void set_four(main_t *m)
{
    set_ball(m);
}

static void set_two(main_t *m)
{
    R_COMBAT[0].left += 800;
    sfSprite_setTextureRect(SP_COMBAT[0], R_COMBAT[0]);
    sfText_setString(TXT_COMBAT[0],
    get_attack(m, 1, 15));
    sfText_setString(TXT_COMBAT[1],
    get_attack(m, 1, 28));
    sfText_setString(TXT_COMBAT[8],
    get_attack(m, 1, 41));
    sfText_setString(TXT_COMBAT[9],
    get_attack(m, 1, 53));
    sfText_setString(TXT_COMBAT[10], " ");
    sfText_setString(TXT_COMBAT[11], " ");
    sfSprite_setPosition(SP_COMBAT[4], (sfVector2f){50, 480});
    COMBAT_SCENE = 2;
    clo = 0;
}

void combat_event_enter_scene_one(main_t *m)
{
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyEnter
        && get_rect(m, SP_COMBAT[4]).top == resize_top(m, 480)
        && get_rect(m, SP_COMBAT[4]).left == resize_left(m, 437))
        set_two(m);
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyEnter
    && get_rect(m, SP_COMBAT[4]).top == resize_top(m, 480)
    && get_rect(m, SP_COMBAT[4]).left == resize_left(m, 662)) {
        OLD_GAME_SCENE = GAME_SCENE;
        GAME_SCENE = 7;
    }
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyEnter
    && get_rect(m, SP_COMBAT[4]).top == resize_top(m, 520)
    && get_rect(m, SP_COMBAT[4]).left == resize_left(m, 437)) {
        OLD_GAME_SCENE = GAME_SCENE;
        GAME_SCENE = 8;
    }
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyEnter
    && get_rect(m, SP_COMBAT[4]).top == resize_top(m, 520)
    && get_rect(m, SP_COMBAT[4]).left == resize_left(m, 662)) {
        if (m->game->fight_npc == false) {
            m->my_game->fight = false;
            m->game->fight_npc = false;
            combat_event_enter_scene_one_2(m);
            sfMusic_play(m->intro->song_game);
            m->game->fight_npc = false;
            GAME_SCENE = 2;
        }
    }
}

void combat_event_enter_scene_two(main_t *m)
{
    clo += TIME;
    if (clo > 0.05) {
        if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyEnter
            && get_rect(m, SP_COMBAT[4]).top == resize_top(m, 480)
            && get_rect(m, SP_COMBAT[4]).left == resize_left(m, 50))
            attack_choice(m, 1, 15);
        if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyEnter
            && get_rect(m, SP_COMBAT[4]).top == resize_top(m, 480)
            && get_rect(m, SP_COMBAT[4]).left == resize_left(m, 270))
            attack_choice(m, 1, 41);
        if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyEnter
            && get_rect(m, SP_COMBAT[4]).top == resize_top(m, 520)
            && get_rect(m, SP_COMBAT[4]).left == resize_left(m, 50))
            attack_choice(m, 1, 28);
        if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyEnter
            && get_rect(m, SP_COMBAT[4]).top == resize_top(m, 520)
            && get_rect(m, SP_COMBAT[4]).left == resize_left(m, 270))
            attack_choice(m, 1, 53);
    }
}
