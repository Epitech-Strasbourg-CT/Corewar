##
## Makefile for corewar in /home/nicolaspolomack/cpe/2/CPE_2016_corewar
## 
## Made by Nicolas Polomack
## Login   <nicolas.polomack@epitech.eu>
## 
## Started on  Mon Mar 20 00:00:28 2017 Nicolas Polomack
## Last update Mon Mar 20 00:03:12 2017 Nicolas Polomack
##

MAKE	=	make -C asm-dir --no-print-directory

NAME	=	asm

all:	$(NAME)

$(NAME):
	@$(MAKE)

clean:
	@$(MAKE) clean

fclean:
	@$(MAKE) fclean

re:
	@$(MAKE) re
