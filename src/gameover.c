/*
** EPITECH PROJECT, 2025
** gameover.c
** File description:
** This is the game over screen
*/
#include "duck.h"
#include <unistd.h>
#include "sprite.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>

static int test_fin(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyR)) {
            sfRenderWindow_close(window);
            return 1;
        }
    }
    return 0;
}

static void init(struct create_sprite *mouse, struct create_sprite *end)
{
    init_mouse(mouse);
    end->rect = (sfIntRect){0, 0, 768, 358};
    sfSprite_setTextureRect(end->sprite, end->rect);
    sfSprite_setScale(end->sprite, (sfVector2f){2.5f, 2.65f});
}

static int render(sfRenderWindow *window, struct create_sprite *mouse,
    struct create_sprite *end, sfEvent event)
{
    int test;

    test = test_fin(window, event);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, end->sprite, NULL);
    move_sprite_rect(end, 358, 12888);
    mose(window, event, mouse);
    sfRenderWindow_display(window);
    return test;
}

int game_over(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(
        mode, "My_hunter", sfTitlebar | sfResize | sfClose, NULL);
    struct create_sprite *mouse = init_sprite("sprite/mouse.png");
    struct create_sprite *end = init_sprite("sprite/end.png");
    sfEvent event;
    int test;

    init(mouse, end);
    while (sfRenderWindow_isOpen(window)) {
        test = render(window, mouse, end, event);
    }
    sfRenderWindow_destroy(window);
    destroy_sprite(end);
    return test;
}
