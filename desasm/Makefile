##
## Makefile for Makefile in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
## 
## Made by Arthur Knoepflin
## Login   <arthur@epitech.net>
## 
## Started on  Thu Mar  9 18:45:29 2017 Arthur Knoepflin
## Last update Tue Mar 28 16:25:03 2017 
##

SRC	=	instruct/get_arg.c		\
		instruct/get_desc.c		\
		instruct/get_instruct.c		\
		args_write.c			\
		main.c				\
		file.c				\
		put.c				\
		op.c				\

OBJ	=	$(SRC:.c=.o)

NAME	=	desasm

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
