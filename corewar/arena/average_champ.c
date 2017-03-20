/*
** average_champ.c for average in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar/arena
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Sat Mar 18 12:16:48 2017 Arthur Knoepflin
** Last update Sun Mar 19 12:01:55 2017 Arthur Knoepflin
*/

#include "corewar.h"
#include "op.h"

static int	get_last_dist(t_parse *parse, int ecart)
{
  int		addr;
  int		i;

  i = 0;
  addr = 0;
  while (++i < parse->nb_champ)
    addr += parse->champ[i - 1]->size + ecart;
  return (MEM_SIZE - (addr + parse->champ[parse->nb_champ - 1]->size));
}

int	get_ecart(t_parse *parse)
{
  int	ecart;
  int	load;
  int	i;

  ecart = 0;
  while (ecart < get_last_dist(parse, ecart))
    ecart += 1;
  i = -1;
  load = 0;
  while (++i < parse->nb_champ)
    load += ecart + parse->champ[i]->size;
  return (ecart);
}
