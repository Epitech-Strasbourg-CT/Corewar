/*
** error.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar  9 20:00:51 2017 Nicolas Polomack
** Last update Tue Mar 21 13:03:22 2017 
*/

#include <stdlib.h>
#include "my_printf.h"
#include "asm.h"

void	error_parse(char *str)
{
  my_printf("%sERROR%s: The argument \'%s\' doesn't match any type ",
	    YELLOW, RESET, str);
  exit(84);
}

void	error_header(int i, int j, int k)
{
  my_printf("%sERROR%s: %d:%d: Two %s defined.\n", GREEN, RESET, i, j,
            (k) ? "names" : "comments");
  exit(84);
}

int	error_double_label(t_label **my_label, char *name)
{
  my_printf("%sERROR%s: two labels (or more) have the name value: '%s'\n",
	    BLUE, RESET, name);
  my_free_label(my_label);
  exit(84);
}

int	error_write(int error_nb, char *info)
{
  my_printf("%sERROR%s: ", RED, RESET);
  if (error_nb == 1)
    my_printf("Undefined label '%s'\n", info);
  if (error_nb == 2)
    my_printf("Oups..., j'ai perdu la ligne '%s'\n", info);
  if (error_nb == 3)
    my_printf("Oups..., j'ai perdu la ligne '%s'\n", info);
  exit(84);
}
