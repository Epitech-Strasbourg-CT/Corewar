/*
** epurstr.c for asm in /home/cedric/delivery/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Wed Mar  1 15:08:23 2017 
** Last update Mon Mar 13 17:27:59 2017 
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"

static int	my_epur_size(char *str, int nbspace, char *to_ep)
{
  int	size_word;
  int	size;
  int	i;

  i = -1;
  size = 0;
  while (is_in(str[++i], to_ep));
  while (my_strnlen(str + i, to_ep) > 0)
    {
      size_word = my_strnlen(str + i, to_ep);
      i += size_word;
      while (is_in(str[i], to_ep))
	i += 1;
      size += size_word;
      if (my_strnlen(str + i, to_ep) > 0)
	size += nbspace;
    }
  return (size);
}

static void	copy_space(char **epur, int *j, char replace, int nb_space)
{
  int		temp;

  temp = *j + nb_space;
  while (*j < temp)
    {
      (*epur)[*j] = replace;
      (*j)++;
    }
}

static void	go_next(char *str, int *i, char *to_ep)
{
  while (str[*i] && is_in(str[*i], to_ep))
    *i += 1;
}

static char	*my_freeit(char *str, char *epured)
{
  free(str);
  return (epured);
}

char	*my_epurnstr(char *str, int nbspace, char *to_ep, char replace)
{
  char	*epured;
  int	size;
  int	i;
  int	j;

  i = -1;
  size = my_epur_size(str, nbspace, to_ep);
  if ((epured = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  while (is_in(str[++i], to_ep));
  j = 0;
  while (str[i])
    {
      while (my_strnlen(str + i, to_ep) > 0)
	{
	  epured[j] = str[i];
	  j += 1;
	  i += 1;
	}
      if (j + nbspace  < size)
	copy_space(&epured, &j, replace, nbspace);
      go_next(str, &i, to_ep);
    }
  epured[j] = 0;
  return (my_freeit(str, epured));
}
