/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init
*/

#include "rpg.h"
#include "my.h"

static char *intro_sprite[] = {
    "./utils/Texture/intro1.png",
    "./utils/Texture/intro2.png",
    NULL
};

static const char *combat_sprite[] = {
    "./utils/Texture/Combat/back.png",
    "./utils/Texture/Pokemon/pokemon.png",
    "./utils/Texture/Pokemon/pokemon.png",
    "./utils/Texture/anime.png",
    "./utils/Texture/Combat/back.png",
    "./utils/Texture/Combat/hp.png",
    "./utils/Texture/Combat/hp.png",
    "./utils/Texture/poke_nb.png",
    "./utils/Texture/Combat/xp.png",
};

static const int pos_combat[18] = {
    0,
    0,
    468,
    25,
    90,
    173,
    600,
    240,
    437,
    480,
    180,
    142,
    565,
    354,
    5,
    5,
    511,
    411,
};

static const sfIntRect combat_rect[9] = {
    {0, 0, 800, 600},
    {0, 0, 64, 64},
    {0, 0, 64, 64},
    {0, 0, 64, 64},
    {2400, 0, 18, 30},
    {0, 0, 159, 7},
    {0, 0, 159, 7},
    {0, 0, 72, 12},
    {0, 0, 215, 8},
};

static void init_sprite_combat(main_t *m)
{
    for (size_t i = 0; i < NB_SP_COMBAT; i++) {
        TX_COMBAT[i] = sfTexture_createFromFile(combat_sprite[i], NULL);
        SP_COMBAT[i] = sfSprite_create();
        sfSprite_setTexture(SP_COMBAT[i], TX_COMBAT[i], sfTrue);
        sfSprite_setPosition(SP_COMBAT[i],
        (sfVector2f){pos_combat[i * 2], pos_combat[(i * 2) + 1]});
        R_COMBAT[i] = combat_rect[i];
        sfSprite_setTextureRect(SP_COMBAT[i], R_COMBAT[i]);
    }
    sfSprite_setScale(SP_COMBAT[1], (sfVector2f){4, 4});
    sfSprite_setScale(SP_COMBAT[2], (sfVector2f){4, 4});
    sfSprite_setScale(SP_COMBAT[3], (sfVector2f){4, 4});
    sfSprite_setScale(SP_COMBAT[7], (sfVector2f){2, 2});
    init_text_combat(m);
}

static void init_variable_intro_start(main_t *m)
{
    m->intro->rect = (sfIntRect) {0, 0, 540, 540};
    m->menu_intro->rect = (sfIntRect) {0, 0, 800, 600};
    m->game->rect_pokemon = (sfIntRect) {0, 585, 64, 64};
    m->game->clock = sfClock_create();
    m->game->direction = 'n';
    m->game->talk_professor = false;
    m->game->the_move = 0;
    TIME = 0;
    m->game->swim = false;
    INTRO_SC = false;
    m->game->move_arrow = (sfVector2f){640, 348};
    m->game->chat = 0;
    m->my_game->fight = false;
    m->game->fight_npc = false;
    init_combat(m);
    GAME_SCENE = 0;
    X = 80;
    COORD = 185;
    STATE = 0;
    STATE_GAME = false;
    VOLUME = 100;
    FPS = 60;
    SCENE_TEXT = false;
    srand(time(NULL));
    for (size_t i = 0; i < 9; i++)
        m->game->fighted[i] = 0;
}

static void init_variable_intro(main_t *m)
{
    init_variable_intro_start(m);
    for (int i = 0; i < NB_SP_INTRO; i += 1) {
        TX_INTRO[i] = sfTexture_createFromFile(intro_sprite[i], NULL);
        SP_INTRO[i] = sfSprite_create();
        sfSprite_setTexture(SP_INTRO[i], TX_INTRO[i], sfTrue);
        sfSprite_setTextureRect(SP_INTRO[i], m->intro->rect);
        sfSprite_setScale(SP_INTRO[i], (sfVector2f) {1.481481481, 1.11111111});
    }
}

void init_pokemon(main_t *m, int a)
{
    m->combat->pokemon_our = 0;
    m->combat->pokemon[1]->pokemon[0] = a;
    m->combat->pokemon[1]->pokemon_lvl[0] = 5;
    m->combat->pokemon[1]->pokemon_pv[0] = (my_atoi(get_info(m, a, 11)) +
    m->combat->pokemon[1]->pokemon_lvl[0]);
    m->combat->pokemon[1]->pokemon_pv_max[0] = (my_atoi(get_info(m, a, 11)) +
    m->combat->pokemon[1]->pokemon_lvl[0]);
}

void init_my_var(main_t *m)
{
    init_variable_intro(m);
    init_variable_intro_menu(m);
    init_variable_game_base(m);
    init_sprite_combat(m);
    init_sprite_bag(m);
    init_text(m);
    init_inventory(m);
    init_map_txt(m, "./utils/map_txt/map_text");
    init_choice(m);
    init_text_infos(m);
}
