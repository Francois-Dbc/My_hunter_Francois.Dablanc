/*
** EPITECH PROJECT, 2025
** music.c
** File description:
** the function for my music
*/
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "duck.h"
#include "sprite.h"

void init_music(sfMusic *music)
{
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 50);
    sfMusic_play(music);
}

void destroy_music(sfMusic *music)
{
    sfMusic_pause(music);
    sfMusic_stop(music);
    sfMusic_destroy(music);
}
