/*
** EPITECH PROJECT, 2025
** duck.h
** File description:
** Duck structure and functions
*/

#ifndef SPRITE_H_
    #define SPRITE_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include "duck.h"

typedef struct create_sprite {
    int pos_x;
    int pos_y;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
} create_sprite_t;

typedef struct create_text {
    int pos_x;
    int pos_y;
    sfFont *font;
    sfText *text;
    sfVector2f scale;
} create_text_t;

void change_level_number(duck_list_t *list, char *buffer,
    struct create_text *text);
void destroy_text(struct create_text *text);
void mose(sfRenderWindow *window, sfEvent event,
    struct create_sprite *mouse);
char *my_strcpy(char *dest, char const *src);
char *int_to_str(int nb, char *str);
void init_text(char *string, struct create_text *text);
int game_over(void);
void destroy_music(sfMusic *music);
void init_music(sfMusic *music);
void init_mouse(struct create_sprite *mouse);
void menu(void);
void init_boss(struct create_sprite *solair);
void boss_sprite(sfRenderWindow *window, struct create_sprite *solair);
void init_solair(struct create_sprite *solair);
void solair_sprite(sfRenderWindow *window,
    struct create_sprite *solair, struct create_sprite *boss);
void boss(sfRenderWindow *window);
create_sprite_t *init_sprite(const char *texture_path);
void move_sprite_rect(create_sprite_t *duck, int offset, int max_value);
void destroy_sprite(create_sprite_t *duck);

#endif
