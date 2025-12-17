/*
** EPITECH PROJECT, 2025
** sprite.c
** File description:
** the function for the sprite
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "./duck.h"
#include "./sprite.h"
create_duck_t *init_duck(const char *texture_path)
{
    create_duck_t *duck = malloc(sizeof(create_duck_t));

    if (!duck)
        return NULL;
    duck->pos_x = 0;
    duck->pos_y = rand() % 500 - 100;
    duck->texture = sfTexture_createFromFile(texture_path, NULL);
    if (!duck->texture) {
        free(duck);
        return NULL;
    }
    duck->clock_move = sfClock_create();
    duck->clock_sprite = sfClock_create();
    duck->sprite = sfSprite_create();
    sfSprite_setTexture(duck->sprite, duck->texture, sfTrue);
    duck->rect = (sfIntRect){0, 0, 545, 372};
    sfSprite_setTextureRect(duck->sprite, duck->rect);
    sfSprite_setScale(duck->sprite, (sfVector2f){0.25f, 0.25f});
    return duck;
}

void move_duck_rect(create_duck_t *duck, int offset, int max_value)
{
    sfTime time = sfClock_getElapsedTime(duck->clock_sprite);
    float seconds = time.microseconds / 1000000.0f;

    if (seconds > 0.1f) {
        duck->rect.left += offset;
        if (duck->rect.left >= max_value)
            duck->rect.left = 0;
        sfSprite_setTextureRect(duck->sprite, duck->rect);
        sfClock_restart(duck->clock_sprite);
    }
}

int touch_duck(create_duck_t *duck, sfEvent event, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f duck_pos = sfSprite_getPosition(duck->sprite);
    sfFloatRect duck_bounds = sfSprite_getGlobalBounds(duck->sprite);

    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
        if (mouse.x >= duck_pos.x && mouse.x <= duck_pos.x
            + duck_bounds.width &&
            mouse.y >= duck_pos.y && mouse.y <= duck_pos.y
            + duck_bounds.height) {
            duck->pos_x = -1100;
            duck->pos_y = rand() % 300 + 100;
            duck->Pv = 0;
            sfSprite_setPosition(duck->sprite,
                (sfVector2f){duck->pos_x, duck->pos_y});
            return 1;
        }
    }
    return 0;
}

int duck_move(struct create_duck *duck, int offset, int max_value, float speed)
{
    sfTime time = sfClock_getElapsedTime(duck->clock_move);
    float seconds = time.microseconds / 1000000.0f;

    if (seconds > speed) {
        duck->pos_x += offset;
        duck->pos_y -= ((rand() % 5) - 2);
        if (duck->pos_x >= max_value) {
            duck->pos_x = -110;
            return 1;
        }
        if (duck->pos_y <= 0)
            duck->pos_y = 90;
        sfSprite_setPosition(duck->sprite, (sfVector2f)
            {duck->pos_x, duck->pos_y});
        sfClock_restart(duck->clock_move);
    }
    return 0;
}

void destroy_duck(create_duck_t *duck)
{
    if (!duck)
        return;
    sfSprite_destroy(duck->sprite);
    sfTexture_destroy(duck->texture);
    sfClock_destroy(duck->clock_sprite);
    free(duck);
}
