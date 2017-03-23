/*
** tab.c for asm in /home/cedric/delivery/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Tue Mar 14 15:42:59 2017 
** Last update Thu Mar 23 21:14:27 2017 Nicolas Polomack
*/
#include <stdlib.h>
#include "asm.h"

char		**my_cpyrealloc(char **old, int new_size)
{
  char		**new;
  int		i;
  int		j;

  i = -1;
  j = 0;
  if ((new = malloc(sizeof(char *) * new_size)) == NULL)
    exit(84);
  while (++i < new_size)
    {
      if (old[j])
	{
	  new[i] = old[j];
	  j += 1;
	}
      else
	new[i] = NULL;
    }
  free(old);
  return (new);
}

char		**epurtab(t_asm *my_asm)
{
  char		**new_tab;
  int		i;
  int		j;

  i = -1;
  j = 0;
  if ((new_tab = malloc(sizeof(char *) * 2)) == NULL)
    exit(84);
  while (my_asm->file[++i])
    {
      if (!composed_of(my_asm->file[i], "\t "))
	{
	  new_tab[j] = my_asm->file[i];
	  j += 1;
	  new_tab[j] = NULL;
	  if ((new_tab = my_cpyrealloc(new_tab, j + 2)) == NULL)
	    exit(84);
	}
      else
	free(my_asm->file[i]);
    }
  free(my_asm->file);
  return (new_tab);
}

