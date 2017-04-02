/*
** get_name.c for get_name in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Fri Mar 31 21:34:43 2017 Arthur Knoepflin
** Last update Fri Mar 31 21:40:39 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"

char	*get_name(t_game *g, int id)
{
  int	i;

  i = -1;
  while (++i < g->parse->nb_champ)
    {
      if (g->parse->champ[i]->id == id)
	return (g->parse->champ[i]->name);
    }
  return (NULL);
}
