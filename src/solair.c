/*
** EPITECH PROJECT, 2025
** solair.c
** File description:
** the hero solair
*/
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "duck.h"
#include "sprite.h"

void init_solair(struct create_sprite *solair)
{
    solair->rect = (sfIntRect){0, 0, 256, 256};
    sfSprite_setTexture(solair->sprite, solair->texture, sfTrue);
    sfSprite_setTextureRect(solair->sprite, solair->rect);
    sfSprite_setScale(solair->sprite, (sfVector2f){1.5f, 1.5f});
    sfSprite_setPosition(solair->sprite, (sfVector2f){1350, 450});
}

void solair_sprite(sfRenderWindow *window, struct create_sprite *solair,
    struct create_sprite *boss)
{
    move_sprite_rect(solair, 256, 6144);
    boss_sprite(window, boss);
    sfSprite_setTextureRect(solair->sprite, solair->rect);
    sfRenderWindow_drawSprite(window, solair->sprite, NULL);
}
