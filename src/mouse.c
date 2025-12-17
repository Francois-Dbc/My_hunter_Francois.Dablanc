/*
** EPITECH PROJECT, 2025
** mouse.c
** File description:
** the mouse change
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "duck.h"
#include "sprite.h"

void init_mouse(struct create_sprite *mouse)
{
    mouse->rect = (sfIntRect){0, 0, 400, 300};
    sfSprite_setTextureRect(mouse->sprite, mouse->rect);
    sfSprite_setScale(mouse->sprite, (sfVector2f){0.25f, 0.25f});
    sfSprite_setPosition(mouse->sprite, (sfVector2f){0, 400});
}

void mose(sfRenderWindow *window, sfEvent event,
    struct create_sprite *mouse)
{
    sfVector2i mous = sfMouse_getPositionRenderWindow(window);

    sfSprite_setPosition(mouse->sprite,
        (sfVector2f){mous.x, mous.y});
    sfRenderWindow_drawSprite(window, mouse->sprite, NULL);
}
