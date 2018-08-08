##
## Makefile for Makeifle in /home/jeremy.elkaim/PSU_2016_tetris
## 
## Made by jeremy elkaim
## Login   <jeremy.elkaim@epitech.net>
## 
## Started on  Tue Feb 21 09:56:21 2017 jeremy elkaim
## Last update Sun Mar 19 21:07:35 2017 Arnaud DEMANGE
##
CC	= gcc

RM	= rm -f

INC	= -Iincludes -lncurses

FLAGS	+= -Wall -Wextra -Werror -pedantic

NAME   = tetris

SRC    = srcs/tetris.c		\
	 srcs/movement_utils.c	\
	 srcs/count_map.c	\
	 srcs/windows_size.c	\
	 srcs/move_on_map.c	\
	 srcs/helps.c		\
	 srcs/check_open.c	\
	 srcs/get_next_line.c	\
	 srcs/main.c		\
	 srcs/parse_arg.c	\
	 srcs/display_debug.c	\
	 srcs/utils.c		\

OBJ    = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(INC) $(FLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
