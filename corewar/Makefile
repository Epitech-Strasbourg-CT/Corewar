##
## Makefile for Makefile in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
## 
## Made by Arthur Knoepflin
## Login   <arthur@epitech.net>
## 
## Started on  Thu Mar  9 18:45:29 2017 Arthur Knoepflin
## Last update Tue Mar 14 17:15:43 2017 Arthur Knoepflin
##

SRC	=	main.c				\
		op.c				\
		endian.c			\
		parse/parse.c			\
		parse/parse_champ.c		\
		parse/parse_error.c		\
		parse/parse_error_2.c		\
		parse/parse_get_list_id.c	\
		parse/parse_file_champ.c	\
		parse/parse_file_header.c	\
		parse/read_file.c

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
