/*
** EPITECH PROJECT, 2025
** boos.c
** File description:
** create the boss
*/
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "duck.h"
#include "sprite.h"

void init_boss(struct create_sprite *boss)
{
    boss->rect = (sfIntRect){0, 0, 400, 300};
    sfSprite_setTextureRect(boss->sprite, boss->rect);
    sfSprite_setScale(boss->sprite, (sfVector2f){1.5f, 1.5f});
    sfSprite_setPosition(boss->sprite, (sfVector2f){0, 400});
}

void boss_sprite(sfRenderWindow *window, struct create_sprite *boss)
{
    move_sprite_rect(boss, 300, 6900);
    sfSprite_setTextureRect(boss->sprite, boss->rect);
    sfRenderWindow_drawSprite(window, boss->sprite, NULL);
}
