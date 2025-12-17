/*
** EPITECH PROJECT, 2025
** next_level.c
** File description:
** The next level of the game
*/
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "duck.h"
#include "sprite.h"

static void add_duck(duck_list_t *list, sfRenderWindow *window)
{
    list->ducks[list->count] = init_duck("sprite/enemie.png");
    list->count++;
}

void next_level(duck_list_t *list, sfRenderWindow *window)
{
    add_duck(list, window);
    list->speed -= 0.0001;
    for (int i = 0; i < list->count; i++) {
        list->ducks[i]->Pv = 1;
        list->ducks[i]->pos_x = rand() % 300 - 610;
        list->ducks[i]->pos_y = rand() % 600 - 1;
        sfSprite_setPosition(list->ducks[i]->sprite,
            (sfVector2f){list->ducks[i]->pos_x, list->ducks[i]->pos_y});
    }
}
