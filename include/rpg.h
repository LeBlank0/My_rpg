/*
** EPITECH PROJECT, 2018
** my_rpg_2018
** File description:
** my_rpg.h
*/

#ifndef RPG_H_
#define RPG_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdbool.h>

#define TX_INTRO            m->intro->texture
#define SP_INTRO            m->intro->sprite
#define INTRO_SC            m->intro->i

#define TX_MENU_INTRO       m->menu_intro->texture
#define SP_MENU_INTRO       m->menu_intro->sprite
#define FONT                m->menu_intro->font
#define TEXT                m->menu_intro->text
#define TEXT_BAG            m->bag->text
#define RECT_ITEM           m->inv->rect_item

#define SCENE_TEXT          m->game->scene_text
#define EVENT               m->game->event
#define MAP                 m->game->map
#define TIME                m->game->sec
#define LIST                m->game->list
#define WINDOW              m->game->window
#define OLD_GAME_SCENE      m->game->old_scene
#define GAME_SCENE          m->game->scene
#define VER                 m->game->vertical
#define VER_SAVE            m->game->vertical_save
#define VER_SAVE_2          m->game->vertical_save_2
#define HOR                 m->game->horizontal
#define HOR_SAVE            m->game->horizontal_save
#define HOR_SAVE_2          m->game->horizontal_save_2
#define STATE_GAME          m->game->state

#define MOVE_MOBS           m->my_game->move_mobs
#define TX_MOBS             m->my_game->mobs_texture
#define SP_MOBS             m->my_game->mobs_sprite

#define R_COMBAT            m->combat->rect
#define TXT_COMBAT          m->combat->text
#define COMBAT_SCENE        m->combat->scene
#define TX_COMBAT           m->combat->texture
#define SP_COMBAT           m->combat->sprite

#define SP_INVENTORY        m->inv->sprite
#define TX_INVENTORY        m->inv->texture

#define SP_BAG              m->bag->sprite
#define TX_BAG              m->bag->texture

#define X                   m->settings->x
#define FPS                 m->settings->fps
#define COORD               m->settings->coord
#define P1                  m->settings->place_1
#define P2                  m->settings->place_2
#define STATE               m->settings->state_option
#define VOLUME              m->settings->volume

#define Y_BAG               m->bag->y
#define X_BAG               m->bag->x

#define NB_MOBS             10
#define NB_INVENTORY        3
#define NB_SP_COMBAT        9
#define NB_SP_INTRO         2
#define NB_SP_MENU_INTRO    6
#define NB_TEXT_OPTION      15
#define NB_SP_BAG           6
#define NB_INFO_BAG         6

typedef struct game_s {
    sfIntRect *rect_box;
    int *fighted;
    char **list;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    char **map;
    sfTexture *tx_textbox;
    sfSprite *sp_textbox;
    sfTexture *tx_choice;
    sfSprite *sp_choice;
    sfSprite *pokemon_choice;
    sfTexture *tx_arrow;
    sfSprite *sp_arrow;
    sfIntRect rect_pokemon;
    sfVector2f move_arrow;
    sfText *bloc;
    char *str;
    char old_direction;
    char direction;
    int the_move;
    int pnj;
    int chat;
    int vertical;
    int vertical_save;
    int vertical_save_2;
    int horizontal;
    int horizontal_save;
    int horizontal_save_2;
    int old_scene;
    int scene;
    float sec;
    float coord;
    int pos;
    char save;
    bool swim;
    bool scene_text;
    bool state;
    bool talk_professor;
    bool fight_npc;
} game_t;

typedef struct settings_s {
    float coord;
    float x;
    int state_option;
    int place_1;
    int place_2;
    unsigned int fps;
    float volume;
} settings_t;

typedef struct menu_intro_s {
    sfVector2i pos_mous;
    sfIntRect rect;
    sfTexture **texture;
    sfSprite **sprite;
    sfFont *font;
    sfText **text;
} menu_intro_t;

typedef struct txbag_s {
    sfSprite *sprite;
    sfIntRect rect;
    int id_pokemon;
    sfText *name;
    sfText *pv_max;
    sfText *pv;
    sfText *lvl;
} txbag_t;

typedef struct bag_s {
    txbag_t **txbag;
    sfSprite **sprite;
    sfTexture **texture;
    sfFont *font;
    sfText **text;
    float y;
    float x;
} bag_t;

typedef struct intro_s {
    sfIntRect rect;
    sfMusic *song;
    sfMusic *song_fight;
    sfMusic *song_game;
    sfMusic *song_rayquaza;
    sfTexture **texture;
    sfSprite **sprite;
    bool i;
} intro_t;

typedef struct my_game_s {
    sfTexture *tx_sacha_swim;
    sfSprite *sp_sacha_swim;
    sfIntRect rect_sacha_swim;
    sfTexture *tx_init_fight;
    sfSprite *sp_init_fight;
    sfIntRect rect_init_fight;
    sfTexture *map_texture;
    sfTexture *map_texture2;
    sfSprite *map_sprite;
    sfSprite *map_sprite2;
    sfTexture *sacha_texture;
    sfSprite *sacha_sprite;
    sfTexture *mobs_texture;
    sfSprite **mobs_sprite;
    sfIntRect rect_map;
    sfIntRect rect_sacha;
    sfIntRect rect_flora;
    sfIntRect *rect_mobs;
    sfIntRect rect_seko;
    int move_left_right;
    int move_top_bottom;
    int save_top;
    int save_side;
    int save_top_2;
    int save_side_2;
    int *move_mobs;
    int pers_move_restart;
    sfTexture *ia_texture;
    sfSprite *ia_sprite;
    sfIntRect rect_ia;
    bool fight;
} my_game_t;

typedef struct inventory_s {
    sfSprite **sprite;
    sfTexture **texture;
    int cas;
    sfIntRect rect_item;
    int coord;
} inventory_t;

typedef struct pokemon_s {
    int *pokemon;
    int *pokemon_lvl;
    int *pokemon_pv;
    int *pokemon_pv_max;
    int *pokemon_xp;
} pokemon_t;

typedef struct combat_s {
    float clock_anime;
    float clock_attack;
    int stat_anime_ball;
    float clock_anime_ball;
    float clock_scene_three;
    int pot;
    int scene;
    int pokemon_nbr;
    int pokemon_en;
    int pokemon_our;
    pokemon_t **pokemon;
    sfTexture **texture;
    sfSprite **sprite;
    sfIntRect *rect;
    sfFont *font;
    sfText **text;
} combat_t;

typedef struct main_s {
    game_t *game;
    intro_t *intro;
    menu_intro_t *menu_intro;
    settings_t *settings;
    my_game_t *my_game;
    combat_t *combat;
    inventory_t *inv;
    bag_t *bag;
} main_t;

/*******************************alloc**********************************/
void rpg_malloc(main_t *m);
/*******************************audio**********************************/
void music_intro(main_t *m);
/*******************************combat*********************************/
void set_combat(main_t *m, int *p1, int *p2, int nb);
int combat_nature(main_t *m);
void modifyfight(main_t *m);
/*******************************destroy********************************/
void my_destroy(main_t *m);
/********************************event*********************************/
void event_game(main_t *m);
void combat_event_scene_one(main_t *m);
void combat_event_scene_two(main_t *m);
void combat_event_scene_three(main_t *m);
void combat_event_enter_scene_one(main_t *m);
void combat_event_enter_scene_two(main_t *m);
void move_scale(main_t *m);
void change_set1(int set_1, main_t *m);
void change_set2(int set_2, main_t *m);
void change_game_scene_options(main_t *m);
void event_pause(main_t *m);
void move_sacha(main_t *m);
void event_scene_zero(main_t *m);
void event_pause(main_t *m);
void event_inventory(main_t *m);
/********************************game_play*****************************/
int game_play(main_t *m);
int choice_pokemon(main_t *m);
int bag(main_t *m);
/*******************************help***********************************/
void tiret_h(void);
void print_text(char *sen, main_t *m);
/**************************init_variable*******************************/
void init_my_var(main_t *m);
void init_variable_game_base(main_t *m);
void init_combat(main_t *m);
void init_inventory(main_t *m);
void init_choice(main_t *m);
int get_poke_nb(main_t *, int a);
void init_pokemon(main_t *m, int a);
void init_sprite_bag(main_t *m);
/*******************************intro**********************************/
int intro_emerald(main_t *m);
int menu_intro(main_t *m);
/*******************************options********************************/
void create_rand(void);
char *get_info(main_t *m, int line, int pos);
int option_display(main_t *m);
int how_to_play(main_t *m);
sfIntRect get_rect(main_t *m, sfSprite *sprite);
int resize_left(main_t *m, int nb);
int resize_top(main_t *m, int nb);
void select_set(main_t *m);
void check_set(main_t *m, int pos1, int pos2);
void ret_game(main_t *m);
/********************************loop.c*********************************/
int game_loop(main_t *m);
/*************************event_2.c******************************/
void event_scene_three(main_t *m);
void game_scene_four(main_t *m);
void game_scene_five(main_t *m);
void event_scene_one(main_t *m);
/*************************init.c******************************/
void init_variable_intro_menu(main_t *m);
void init_text(main_t *m);
void init_map_txt(main_t *m, const char *str);
void init_text_infos(main_t *m);
void init_text_combat(main_t *m);
/*************************move_sacha.c******************************/
void left_move(main_t *m);
void right_move(main_t *m);
void up_move(main_t *m);
void down_move(main_t *m);
char *get_attack(main_t *m, int pok, int nb);
void attack_choice(main_t *m, int pok, int nb);
/*************************event_key_code.c******************************/
void event_key_code(main_t *m);
/*************************inventory.c**********************************/
int inventory(main_t *m);
void set_four(main_t *m);
/*************************up_move_2.c******************************/
void cm_0(main_t *m);
void cm_9(main_t *m);
void cm_2(main_t *m);
void cm_3(main_t *m);
void cm_4(main_t *m);
/*************************up_move_2_2.c******************************/
void cm_5(main_t *m);
void cm_6(main_t *m);
void cm_u(main_t *m);
void cm_uu(main_t *m);
void cm_7(main_t *m);
/*************************up_move_2_3.c******************************/
void cm_d(main_t *m);
void cm_dd(main_t *m);
void cm_8(main_t *m);
/*************************left_move_2.c******************************/
void cml_0(main_t *m);
void cml_8(main_t *m);
void cml_n(main_t *m);
void cml_nn(main_t *m);
void cml_9(main_t *m);
/*************************right_move_2.c******************************/
void cmr_0(main_t *m);
void cmr_9(main_t *m);
void cmr_ff(main_t *m);
void cmr_8(main_t *m);
/*************************down_move_2.c******************************/
void cmd_0(main_t *m);
void cmd_9(main_t *m);
void cmd_x(main_t *m);
void cmd_l(main_t *m);
void cmd_8(main_t *m);
/*************************key_e_move.c******************************/
void key_e_move(main_t *m);
void set_pos_text(main_t *m);
void init_text_inventory(main_t *m);
/*************************fight_npc_func.c******************************/
void fight_npc_func(main_t *m, float *time_fight);
/*************************game.c******************************/
void launch_fight(main_t *m, float *timer, int *pokemon, int *lvl,
int nb);
/*************************fight_npc_func_2.c******************************/
void redirection_fight_npc_3(main_t *m, float *time_fight);
void redirection_fight_npc_6(main_t *m, float *time_fight);
void redirection_fight_npc_7(main_t *m, float *time_fight);
void redirection_fight_npc_8(main_t *m, float *time_fight);
void redirection_fight_npc_9(main_t *m, float *time_fight);
/*************************fight_npc_func_3.c******************************/
void redirection_fight_npc_10(main_t *m, float *time_fight);
void redirection_fight_npc_11(main_t *m, float *time_fight);
void redirection_fight_npc_12(main_t *m, float *time_fight);
void redirection_fight_npc_13(main_t *m, float *time_fight);
void redirection_fight_npc_98(main_t *m, float *time_fight);
/*************************game_2.c******************************/
int choice_pokemon(main_t *m);
void ia_move(main_t *m);
void menu_pause(main_t *m);
void move_up(main_t *m, float *timer);
void move_down(main_t *m, float *timer);
/*************************game_3.c******************************/
void modifyfight(main_t *m);
void game_play_bis(main_t *m);
void move_charac(main_t *m);
void move_left(main_t *m, float *timer);
void move_right(main_t *m, float *timer);
/*************************init_game_base_2.c******************************/
void init_sacha(main_t *m);
void init_map2(main_t *m);
void init_map(main_t *m);
/*************************combat_nature_2.c******************************/
void number_pokemon(main_t *m);
void anime_attack(main_t *m);
int anime_attack_if_2(main_t *m, int stat);
void anime_pokeball(main_t *m);
void reset_pokemon(main_t *m);
/*************************combat_nature_3.c******************************/
void player(main_t *m);
void animation_combat_scene_four(main_t *m);
void combat_scene_four_bis(main_t *m, int c);
void combat_scene_four(main_t *m);
void combat_scene_three_bis(main_t *m);
/*************************combat_nature_4.c******************************/
void combat_scene_three_4(main_t *m);
void combat_scene_three_5(main_t *m);
void combat_scene_three(main_t *m);
void pot(main_t *m);
void combat_scene_one_two(main_t *m);
/*************************combat_nature_5.c******************************/
void xp_1(main_t *m);
void hp_1(main_t *m);
void hp_2(main_t *m, int pv);
void combat_scene_zero_3(main_t *m);
void combat_scene_zero_5(main_t *m);
/*************************game_4.c******************************/
void menu_pause_2(int i, main_t *m);
void game_play_bis_2(main_t *m);
/*************************event_combat_3.c******************************/
void combat_event_enter_scene_one_2(main_t *m);
/*************************bag_2.c******************************/
void print_first_pokemon_2(main_t *m);
/*************************game_5.c******************************/
void game_play_bis_3(main_t *m);
void pnj_8_1(main_t *m);
void pnj_7_1(main_t *m);
void pnj_6_1(main_t *m);
void pnj_5_1(main_t *m);
/*************************game_6.c******************************/
void pnj_4_1(main_t *m);
void pnj_2_1(main_t *m);
void pnj_1_1(main_t *m);

#endif /* RPG_H_ */
