##
## EPITECH PROJECT, 2023
## my_sokoban
## File description:
## Makefile for my_printf
##

PROJECT_NAME	=	my_sokoban

SRC		=	fenetre.c	\
			main.c		\
			check_map.c	\
			check_move.c	\
			position_player.c

COMP	=	gcc

FLAGS	 =	-I./includes/ -L./lib/ -lmy -lncurses

all:	$(PROJECT_NAME)

$(PROJECT_NAME):
	make -C lib/my/
	$(COMP) -o $(PROJECT_NAME) $(SRC) $(FLAGS)

clean:
	make -C lib/my/ clean

fclean:	clean
	rm -f $(PROJECT_NAME)
	rm -f lib/libmy.a

re:	fclean	all
