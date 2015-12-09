##
## Makefile for BSQ in /CPE_2015_bsq
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Thu Nov 26 10:50:20 2015 Antoine Baché
## Last update Wed Dec  9 17:56:58 2015 Antoine Baché
##

SRC=	src/bsq.c \
	src/my_put.c \
	src/parse.c \
	src/my_realloc.c \
	src/prepare_tab.c \
	src/my_strlen.c

NAME=	bsq


HEAD=	-Iinclude

CC=	gcc $(HEAD) -Wall -Wextra -Werror -ansi -pedantic

RM=	rm -f

OBJ=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: 	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
