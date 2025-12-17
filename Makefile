##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## the Makefile
##

SRC =	src/main.c	\
	src/bootV2.c	\
	src/sprite_duck.c	\
	src/sprite_duck2.c	\
	src/sprite.c	\
	src/gameover.c	\
	src/mouse.c	\
	src/boss.c	\
	src/text.c	\
	src/music.c	\
	src/next_level.c	\
	src/solair.c

NAME = my_hunter
all:
	epiclang -o $(NAME) $(SRC)  -l csfml-graphics -l csfml-audio -l csfml-window -l csfml-system -Iinclude/my.h -I./duck.h -I./sprite.h
clean:
	find -type f \( -name '*~' -or -name '#*#' \) -delete

fclean:	clean
	rm -f $(NAME)

re:	fclean	all	clean
