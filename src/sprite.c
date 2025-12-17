/*
** EPITECH PROJECT, 2025
** sprite.c
** File description:
** the function for the sprite
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "./sprite.h"

create_sprite_t *init_sprite(const char *texture_path)
{
    create_sprite_t *duck = malloc(sizeof(create_sprite_t));

    if (!duck)
        return NULL;
    duck->pos_x = 0;
    duck->pos_y = rand() % 500 - 100;
    duck->texture = sfTexture_createFromFile(texture_path, NULL);
    if (!duck->texture) {
        free(duck);
        return NULL;
    }
    duck->clock = sfClock_create();
    duck->sprite = sfSprite_create();
    sfSprite_setTexture(duck->sprite, duck->texture, sfTrue);
    duck->rect = (sfIntRect){0, 0, 110, 110};
    sfSprite_setTextureRect(duck->sprite, duck->rect);
    return duck;
}

void move_sprite_rect(create_sprite_t *duck, int offset, int max_value)
{
    sfTime time = sfClock_getElapsedTime(duck->clock);
    float seconds = time.microseconds / 1000000.0f;

    if (seconds > 0.15f) {
        duck->rect.top += offset;
        if (duck->rect.top >= max_value)
            duck->rect.top = 0;
        sfSprite_setTextureRect(duck->sprite, duck->rect);
        sfClock_restart(duck->clock);
    }
}

void destroy_sprite(create_sprite_t *duck)
{
    if (!duck)
        return;
    sfSprite_destroy(duck->sprite);
    sfTexture_destroy(duck->texture);
    free(duck);
}
