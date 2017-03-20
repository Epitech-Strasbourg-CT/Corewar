/*
** is_overlap.c for is_overlap in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Sun Mar 19 11:00:24 2017 Arthur Knoepflin
** Last update Mon Mar 20 14:02:09 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"

int	*get_tab_pos(t_parse *parse, int ecart)
{
  int	i;
  int	pos;
  int	*ret;

  if ((ret = malloc(sizeof(int) * (parse->nb_champ + 1))) == NULL)
    return (NULL);
  ret[parse->nb_champ] = -1;
  pos = 0;
  i = -1;
  while (++i < parse->nb_champ)
    {
      ret[i] = pos;
      pos += parse->champ[i]->size + ecart;
    }
  return (ret);
}

int	is_overlap_lock(t_parse *parse)
{
  int	i;
  int	j;

  i = -1;
  while (++i < parse->nb_champ)
    if (parse->champ[i]->load_addr != -1)
      {
	j = -1;
	while (++j < parse->nb_champ)
	  if (i != j && parse->champ[j]->load_addr != -1)
	    {
	      if (parse->champ[j]->load_addr + parse->champ[j]->size >
		  parse->champ[i]->load_addr && parse->champ[j]->load_addr <
		  parse->champ[i]->load_addr + parse->champ[i]->size)
		return (1);
	    }
      }
  return (0);
}
