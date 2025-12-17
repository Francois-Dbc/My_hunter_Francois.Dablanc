/*
** EPITECH PROJECT, 2025
** sprite_duck2.c
** File description:
** the second part of the function of duck
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "./duck.h"
void destroy_duck_list(duck_list_t *list)
{
    for (int i = 0; i < list->count; i++)
        destroy_duck(list->ducks[i]);
}
