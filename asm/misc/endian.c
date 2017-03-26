/*
** main.c for main.c in /home/cedric/delivery/ex
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Sun Mar 26 16:57:44 2017 Nicolas Polomack
*/
#include <stdlib.h>
#include "my_printf.h"
#include "asm.h"

void		swap_endian(void *raw, int size)
{
  unsigned char	*converted;
  unsigned char	c;
  int	i;
  int	j;

  converted = (unsigned char *)raw;
  i = -1;
  j = size - 1;
  while (++i < j)
    {
      c = converted[i];
      converted[i] = converted[j];
      converted[j] = c;
      j -= 1;
    }
}

void	check_nb_args(char *expr, char **split, int idx)
{
  int	i;
  int	nb_comma;
  int	nb_args;

  i = -1;
  while (split[++i]);
  nb_args = i;
  i = -1;
  nb_comma = 0;
  while (expr[++i])
    if (expr[i] == ',')
      nb_comma += 1;
  if (nb_args != nb_comma + 1)
    {
      my_printf("%sERROR%s: Bad arguments number for instruct %d\n",
		YELLOW, RESET, idx);
      exit(84);
    }
}
