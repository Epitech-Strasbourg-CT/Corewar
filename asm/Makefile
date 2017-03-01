##
## Makefile for Makefile in /home/cedric/lib
## 
## Made by Cédric Thomas
## Login   <cedric@epitech.net>
## 
## Started on  Sat Oct 22 10:37:32 2016 Cédric Thomas
## Last update Wed Mar  1 10:57:43 2017 
##

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

LIB_F	=	./lib/

LIB	=	-lmy -lmyprintf -lgnl

INCLUDE	=	-I./include/

CFLAGS	+=	 $(INCLUDE) -g	


all:		$(NAME)

$(NAME):	$(OBJ)
		make -sC lib/GNL
		make -sC lib/my
		make -sC lib/my_printf
		gcc -o $(NAME) $(OBJ) -L$(LIB_F) $(LIB)

clean:
		make -sC lib/GNL fclean
		make -sC lib/my fclean
		make -sC lib/my_printf fclean
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
