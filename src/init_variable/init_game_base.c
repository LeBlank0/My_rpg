/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init_game_base
*/

#include "rpg.h"
#include "my.h"

static void init_mobs(main_t *m)
{
    TX_MOBS = sfTexture_createFromFile("./utils/Texture/perso.png", NULL);
    m->my_game->rect_mobs[0] = (sfIntRect){0, 42, 16, 20};
    m->my_game->rect_mobs[1] = (sfIntRect){16, 42, 16, 20};
    m->my_game->rect_flora = (sfIntRect){0, 0, 16, 20};
    m->my_game->rect_seko = (sfIntRect){0, 21, 16, 20};
    for (size_t i = 0; i != NB_MOBS; i++) {
        SP_MOBS[i] = sfSprite_create();
        sfSprite_setTexture(SP_MOBS[i], TX_MOBS, sfTrue);
        sfSprite_setScale(SP_MOBS[i], (sfVector2f){3.5, 3.5});
        if (i < 2) {
            sfSprite_setTextureRect(SP_MOBS[i], m->my_game->rect_mobs[0]);
        } else
            sfSprite_setTextureRect(SP_MOBS[i], m->my_game->rect_mobs[1]);
    }
    sfSprite_setTextureRect(SP_MOBS[2], m->my_game->rect_seko);
    sfSprite_setTextureRect(SP_MOBS[5], m->my_game->rect_flora);
    sfSprite_setTextureRect(SP_MOBS[6], (sfIntRect){0, 84, 16, 19});
    sfSprite_setTextureRect(SP_MOBS[7], (sfIntRect){17, 63, 16, 20});
    sfSprite_setTextureRect(SP_MOBS[8], (sfIntRect){0, 84, 16, 19});
    sfSprite_setTextureRect(SP_MOBS[9], (sfIntRect){0, 104, 16, 20});
}

static void init_ia(main_t *m)
{
    m->my_game->ia_sprite = sfSprite_create();
    m->my_game->ia_texture =
    sfTexture_createFromFile("./utils/Texture/perso.png", NULL);
    sfSprite_setTexture(m->my_game->ia_sprite, m->my_game->ia_texture, sfTrue);
    m->my_game->rect_ia = (sfIntRect){0, 63, 16, 20};
    sfSprite_setTextureRect(m->my_game->ia_sprite, m->my_game->rect_ia);
    sfSprite_setScale(m->my_game->ia_sprite, (sfVector2f){3.5, 3.5});
    sfSprite_setPosition(m->my_game->ia_sprite, (sfVector2f) {385, 350});
}

static void init_fight(main_t *m)
{
    m->my_game->sp_init_fight = sfSprite_create();
    m->my_game->tx_init_fight =
    sfTexture_createFromFile("./utils/Texture/launch_fight.png", NULL);
    sfSprite_setTexture(m->my_game->sp_init_fight,
    m->my_game->tx_init_fight, sfTrue);
    m->my_game->rect_init_fight = (sfIntRect){0, 0, 800, 600};
    sfSprite_setTextureRect(m->my_game->sp_init_fight,
    m->my_game->rect_init_fight);
}

static void init_sachaswim(main_t *m)
{
    m->my_game->tx_sacha_swim =
    sfTexture_createFromFile("./utils/Texture/26_31.png", NULL);
    m->my_game->sp_sacha_swim = sfSprite_create();
    sfSprite_setTexture(m->my_game->sp_sacha_swim,
    m->my_game->tx_sacha_swim, sfTrue);
    m->my_game->rect_sacha_swim = (sfIntRect){0, 0, 25, 31};
    sfSprite_setTextureRect(m->my_game->sp_sacha_swim,
    m->my_game->rect_sacha_swim);
    sfSprite_setScale(m->my_game->sp_sacha_swim, (sfVector2f){3.5, 3.5});
    sfSprite_setPosition(m->my_game->sp_sacha_swim, (sfVector2f) {385, 200});
}

void init_variable_game_base(main_t *m)
{
    init_map(m);
    init_map2(m);
    init_sacha(m);
    init_sachaswim(m);
    init_mobs(m);
    init_ia(m);
    init_fight(m);
}
