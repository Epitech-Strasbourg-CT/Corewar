##
## Makefile for Makefile in /home/cedric/lib
## 
## Made by Cédric Thomas
## Login   <cedric@epitech.net>
## 
## Started on  Sat Oct 22 10:37:32 2016 Cédric Thomas
## Last update Sat Mar 18 17:50:01 2017 
##

SRC	=	main.c				\
		op.c				\
		my_int_to_char.c		\
		error_handling/error.c		\
		header/header.c			\
		instruct/parse.c		\
		instruct/misc.c			\
		instruct/write_args.c		\
		instruct/list_instruct.c	\
		label/label.c			\
		label/size.c			\
		label/list_label.c		\
		misc/file.c			\
		misc/str.c			\
		misc/tab.c			\
		misc/epurstr.c			\
		misc/bitshift.c			\
		misc/endian.c


OBJ	=	$(SRC:.c=.o)

NAME	=	asm

LIB_F	=	./lib/

LIB	=	-lmy -lmyprintf -lgnl

INCLUDE	=	-I./include/

CFLAGS	+=	 $(INCLUDE) -g

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
		@make -sC lib/GNL clean
		@make -sC lib/my clean
		@make -sC lib/my_printf clean
		@rm -f $(OBJ)

fclean:		clean
		@make -sC lib/GNL fclean
		@make -sC lib/my fclean
		@make -sC lib/my_printf fclean
		@rm -f $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
