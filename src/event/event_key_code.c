/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event_key_code
*/

#include "rpg.h"
#include "my.h"

void left_move_2(main_t *m)
{
    char *code_map[6] = {"0", "8", "n", "N", "9", NULL};
    void (*flag[5])(main_t *) = {cml_0, cml_8, cml_n, cml_nn, cml_9};

    for (int i = 0; code_map[i] != NULL; i += 1) {
        if (MAP[VER][HOR - 1] == code_map[i][0]) {
            flag[i](m);
            break;
        }
    }
}

void right_move_2(main_t *m)
{
    char *code_map[5] = {"0", "9", "F", "8", NULL};
    void (*flag[4])(main_t *) = {cmr_0, cmr_9, cmr_ff, cmr_8};

    for (int i = 0; code_map[i] != NULL; i += 1) {
        if (MAP[VER][HOR + 1] == code_map[i][0]) {
            flag[i](m);
            break;
        }
    }
}

void up_move_2(main_t *m)
{
    char *code_map[14] = {"0", "9", "2", "3", "4", "5", "6", "u", "U", "7", "d",
        "D", "8", NULL};
    void (*flag[13])(main_t *) = {cm_0, cm_9, cm_2, cm_3, cm_4, cm_5, cm_6,
        cm_u, cm_uu, cm_7, cm_d, cm_dd, cm_8};

    for (int i = 0; code_map[i] != NULL; i += 1) {
        if (MAP[VER - 1][HOR] == code_map[i][0]) {
            flag[i](m);
            break;
        }
    }
}

void down_move_2(main_t *m)
{
    char *code_map[11] = {"0", "9", "x", "L", "o", "O", "p", "S", "A", "8",
        NULL};
    void (*flag[10])(main_t *) = {cmd_0, cmd_9, cmd_x, cmd_l, cmd_l, cmd_l,
        cmd_l, cmd_l, cmd_l, cmd_8};
    for (int i = 0; code_map[i] != NULL; i += 1) {
        if (MAP[VER + 1][HOR] == code_map[i][0]) {
            flag[i](m);
            break;
        }
    }
}

void event_key_code(main_t *m)
{
    char *code_key[7] = {"71", "72", "73", "74", "4", NULL};
    void (*flag[6])(main_t *) = {left_move_2, right_move_2, up_move_2,
        down_move_2, key_e_move};
    for (int i = 0; code_key[i] != NULL; i += 1) {
        if (EVENT.type == sfEvtKeyPressed &&
        EVENT.key.code == atoi(code_key[i])) {
            flag[i](m);
            break;
        }
    }
}