##
## Makefile for Makefile in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
## 
## Made by Arthur Knoepflin
## Login   <arthur@epitech.net>
## 
## Started on  Thu Mar  9 18:45:29 2017 Arthur Knoepflin
## Last update Thu Mar 23 21:37:36 2017 
##

SRC	=	arena/arena_create.c		\
		arena/average_champ.c		\
		arena/is_overlap.c		\
		arena/load_champ.c		\
		dump.c				\
		list_live.c			\
		fnt_tab.c			\
		fnt/live.c			\
		fnt/st.c			\
		fnt/ld.c			\
		fnt/sti.c			\
		fnt/ldi.c			\
		fnt/and.c			\
		fnt/or.c			\
		fnt/xor.c			\
		fnt/add.c			\
		fnt/sub.c			\
		fnt/aff.c			\
		fnt/zjmp.c			\
		game.c				\
		head/exec_head.c		\
		head/head.c			\
		head/init_head.c		\
		head/kill_player.c		\
		instruct/get_arg.c		\
		instruct/get_desc.c		\
		instruct/get_instruct.c		\
		live.c				\
		main.c				\
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
