/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** main
*/

#include "rpg.h"
#include "my.h"

static void create_window(main_t *m)
{
    const sfImage *logo = sfImage_createFromFile("./utils/Texture/logo.png");
    const sfUint8 *icon = sfImage_getPixelsPtr(logo);
    sfVideoMode mode = {800, 600, 32};
    WINDOW = sfRenderWindow_create(mode, "Pokemon", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(WINDOW, FPS);
    sfRenderWindow_setIcon(WINDOW, 256, 256, icon);
    sfRenderWindow_setMouseCursorVisible(WINDOW, sfFalse);
}

static int start(void)
{
    main_t *m = malloc(sizeof(*m));

    if (m == NULL)
        return (84);
    rpg_malloc(m);
    init_my_var(m);
    create_window(m);
    music_intro(m);
    return (game_loop(m));
}

int main(int ac, char **av)
{
    if (ac == 1)
        return (start());
    else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        tiret_h();
    else
        return (84);
    return (0);
}
