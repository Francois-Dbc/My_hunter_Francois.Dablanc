/*
** EPITECH PROJECT, 2025
** bootV2.c
** File description:
** The game function
*/
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "duck.h"
#include "sprite.h"


static void duck(struct create_duck *e, sfEvent event, sfRenderWindow
    *window, float speed)
{
    if (e->Pv <= 0)
        return;
    if (duck_move(e, 10, 1920, speed) == 1) {
    }
    move_duck_rect(e, 542, 15176);
}

static void test_touch(sfRenderWindow *window, sfEvent *event,
    duck_list_t *list)
{
    for (int i = 0; i < list->count; i++)
        if (touch_duck(list->ducks[i], *event, window))
            return;
}

static void analyse_events(sfRenderWindow *window, sfEvent *event,
    duck_list_t *list)
{
    int all_dead = 1;

    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            test_touch(window, event, list);
    }
    for (int i = 0; i < list->count; i++) {
        if (list->ducks[i]->Pv > 0)
            all_dead = 0;
    }
    if (all_dead == 1)
        next_level(list, window);
    if (list->count == MAX_DUCKS) {
        sfRenderWindow_close(window);
    }
}

static void init(struct create_duck *background, duck_list_t *list,
    struct create_sprite *solair, struct create_sprite *boss)
{
    init_solair(solair);
    init_boss(boss);
    background->rect = (sfIntRect){10, 155, 1900, 1000};
    sfSprite_setTextureRect(background->sprite, background->rect);
    sfSprite_setScale(background->sprite, (sfVector2f){1.0f, 1.0f});
    list->count = 1;
    list->speed = 0.05;
    list->ducks[0] = init_duck("sprite/enemie.png");
}

static void render(sfRenderWindow *window, sfEvent event, duck_list_t *list,
    struct create_duck *background)
{
    analyse_events(window, &event, list);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, background->sprite, NULL);
}

static void destroy(struct create_duck *background,
    duck_list_t *list, struct create_sprite *solair, sfMusic *music)
{
    destroy_music(music);
    destroy_sprite(solair);
    destroy_duck(background);
    destroy_duck_list(list);
    if (game_over() == 1)
        menu();
}

static void init_all(duck_list_t *list, sfEvent event, sfRenderWindow *window)
{
    for (int i = 0; i < list->count; i++) {
        duck(list->ducks[i], event, window, list->speed);
        sfRenderWindow_drawSprite(window, list->ducks[i]->sprite, NULL);
    }
}

static void int_other(struct create_sprite *mouse,
    struct create_text *text, sfMusic *music)
{
    init_mouse(mouse);
    init_text("Level", text);
    init_music(music);
}

static void render_other(sfEvent event, sfRenderWindow *window,
    struct create_sprite *mouse, struct create_text *text)
{
    mose(window, event, mouse);
    sfRenderWindow_drawText(window, text->text, NULL);
    sfRenderWindow_display(window);
}

void game_function(sfEvent event, sfRenderWindow *window)
{
    struct create_sprite *boss = init_sprite("sprite/das_boss.png");
    struct create_sprite *mouse = init_sprite("sprite/mouse.png");
    struct create_sprite *solair = init_sprite("sprite/solair_sprite.png");
    struct create_duck *background = init_duck("sprite/background_game2.png");
    struct create_text *text = malloc(sizeof(struct create_text));
    sfMusic *music = sfMusic_createFromFile("sprite/Gravelord Nito.ogg");
    duck_list_t list;
    char buffer[64];

    init(background, &list, solair, boss);
    int_other(mouse, text, music);
    while (sfRenderWindow_isOpen(window)) {
        change_level_number(&list, buffer, text);
        render(window, event, &list, background);
        init_all(&list, event, window);
        solair_sprite(window, solair, boss);
        render_other(event, window, mouse, text);
    }
    destroy_text(text);
    destroy(background, &list, solair, music);
}
