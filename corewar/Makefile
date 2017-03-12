##
## Makefile for Makefile in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
## 
## Made by Arthur Knoepflin
## Login   <arthur@epitech.net>
## 
## Started on  Thu Mar  9 18:45:29 2017 Arthur Knoepflin
## Last update Sun Mar 12 13:55:37 2017 Arthur Knoepflin
##

SRC	=	main.c				\
		parse/parse.c			\
		parse/parse_champ.c		\
		parse/parse_error.c		\
		parse/parse_error_2.c		\
		parse/parse_get_list_id.c

OBJ	=	$(SRC:.c=.o)

NAME	=	corewar

CFLAGS	+=	-Iinclude -g

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lmy -Llib

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
