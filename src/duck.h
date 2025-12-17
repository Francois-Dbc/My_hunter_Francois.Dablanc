/*
** EPITECH PROJECT, 2025
** duck.h
** File description:
** Duck structure and functions
*/

#ifndef DUCK_H_
    #define DUCK_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
typedef struct create_duck {
    int pos_x;
    int pos_y;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock_sprite;
    sfClock *clock_move;
    int Pv;
} create_duck_t;

    #define MAX_DUCKS 16

typedef struct duck_list {
    struct create_duck *ducks[MAX_DUCKS];
    int count;
    float speed;
} duck_list_t;

void next_level(duck_list_t *list, sfRenderWindow *window);
void destroy_duck_list(duck_list_t *list);
int duck_move(struct create_duck *duck, int offset,
    int max_value, float speed);
void game_function(sfEvent event, sfRenderWindow *window);
int touch_duck(create_duck_t *duck, sfEvent event, sfRenderWindow *window);
create_duck_t *init_duck(const char *texture_path);
void move_duck_rect(create_duck_t *duck, int offset, int max_value);
void destroy_duck(create_duck_t *duck);

#endif
