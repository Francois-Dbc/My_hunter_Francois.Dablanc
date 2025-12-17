/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** the menu
*/
#include "duck.h"
#include <unistd.h>
#include "sprite.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>

static void test_fin(sfRenderWindow *window, sfMusic *musicmenu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyE))
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyP)) {
            destroy_music(musicmenu);
            game_function(event, window);
        }
    }
}

static void flag_h(int argc, char *argv[])
{
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        write(1, "This program is dark soul hunter were you shoot a creature"
            "and fight a boss\nThe input are:\n", 91);
        write(1, "-p\tlunch the game\n-esc\tquit the game"
            "\n-left-clik\tin the game kill the creature\n", 78);
        write(1, "-r\trelunch the game in the end menu\n-esc\tquit the game"
            " for good\n", 64);
    }
    if (argv[1][0] != '-')
        write(1, "Wrong command try with -h\n", 26);
    if (argv[1][0] == '-' && argv[1][1] != 'h')
        write(1, "Almost but wrong command try with -h\n", 37);
}

static void initi(struct create_sprite *menu, struct create_sprite *mouse)
{
    menu->rect = (sfIntRect){0, 0, 768, 384};
    init_mouse(mouse);
    sfSprite_setTextureRect(menu->sprite, menu->rect);
    sfSprite_setScale(menu->sprite, (sfVector2f){2.5f, 2.65f});
}

static void rendermain(sfEvent event, sfRenderWindow *window,
    struct create_sprite *menu, struct create_sprite *mouse)
{
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->sprite, NULL);
    move_sprite_rect(menu, 768, 10368);
    mose(window, event, mouse);
    sfRenderWindow_display(window);
}

void menu(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(
        mode, "My_hunter", sfTitlebar | sfResize | sfClose, NULL);
    struct create_sprite *menu = init_sprite("sprite/menu2.png");
    struct create_sprite *mouse = init_sprite("sprite/mouse.png");
    sfMusic *musicmenu = sfMusic_createFromFile("sprite/Menu.mp3");
    sfEvent event;

    initi(menu, mouse);
    init_music(musicmenu);
    while (sfRenderWindow_isOpen(window)) {
        test_fin(window, musicmenu);
        rendermain(event, window, menu, mouse);
    }
    sfRenderWindow_destroy(window);
    destroy_sprite(menu);
}

int main(int argc, char *argv[])
{
    if (argc != 1)
        flag_h(argc, argv);
    if (argc == 1)
        menu();
    return 1;
}
