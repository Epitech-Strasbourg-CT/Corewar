
##
## Makefile for Makefile in /home/cedric/lib
## 
## Made by Cédric Thomas
## Login   <cedric@epitech.net>
## 
## Started on  Sat Oct 22 10:37:32 2016 Cédric Thomas
## Last update Thu Mar  9 19:36:01 2017 Nicolas Polomack
##

SRC	=	main.c		\
		file.c		\
		header.c	\
		misc/str.c

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

LIB_F	=	./lib/

LIB	=	-lmy -lmyprintf -lgnl

INCLUDE	=	-I./include/

CFLAGS	+=	 $(INCLUDE)

all:		$(NAME)

$(NAME):	.SILENT

.SILENT:	$(OBJ)
		@echo -en "Compilation GNL...\t\t"
		@make -sC lib/GNL
		@echo "OK"
		@echo -en "Compilation libmy...\t\t"
		@make -sC lib/my
		@echo "OK"
		@echo -en "Compilation my_printf...\t"
		@make -sC lib/my_printf
		@echo "OK"
		@echo -en "Linking ASM compiler...\t\t"
		@gcc -o $(NAME) $(OBJ) -L$(LIB_F) $(LIB)
		@echo "OK"

clean:
		@make -sC lib/GNL fclean
		@make -sC lib/my fclean
		@make -sC lib/my_printf fclean
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
