/*
** EPITECH PROJECT, 2025
** text.c
** File description:
** create a text with a font that i already choose
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

void destroy_text(struct create_text *text)
{
    sfText_destroy(text->text);
    free(text);
}

void init_text(char *string, struct create_text *text)
{
    text->font = sfFont_createFromFile("sprite/celt.TTF");
    text->text = sfText_create();
    sfText_setString(text->text, "level");
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, (sfVector2f){0, 0});
    sfText_setScale(text->text, (sfVector2f){1.0, 1.0});
}

static char *my_strcat(char *dest, char src)
{
    int i = 0;

    while (dest[i] != '\0')
        i++;
    dest[i] = src;
    dest[i + 1] = '\0';
    return dest;
}

char *int_to_str(int nb, char *str)
{
    if (nb < 0) {
        my_strcat(str, '-');
        return int_to_str(-nb, str);
    }
    if (nb > 9) {
        int_to_str(nb / 10, str);
    }
    my_strcat(str, (nb % 10) + '0');
    return str;
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0'){
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return dest;
}

void change_level_number(duck_list_t *list, char *buffer,
    struct create_text *text)
{
    my_strcpy(buffer, "Level ");
    int_to_str(list->count, buffer);
    sfText_setString(text->text, buffer);
}
