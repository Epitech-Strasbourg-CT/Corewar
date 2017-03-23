/*
** get_instruct.c for get_instruct in /delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Mar 20 21:50:27 2017 Arthur Knoepflin
** Last update Thu Mar 23 17:05:44 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"
#include "op.h"

int	is_reg_valid(t_ins *ret)
{
  int	i;

  i = -1;
  while (++i < ret->nb_arg)
    {
      if (ret->type[i] == 1 &&
	  (ret->val[i] < 1 || ret->val[i] > REG_NUMBER))
	{
	  return (1);
	}
    }
      return (0);
}

t_ins	*get_instruc(t_game *game, int index)
{
  t_ins	*ret;

  if (game->arena[index] == 0 || game->arena[index] > 16)
    return (NULL);
  if ((ret = malloc(sizeof(t_ins))) == NULL)
    return (NULL);
  my_memset(ret->val, 0, 4);
  my_memset(ret->type, -1, 4);
  ret->cmd = game->arena[index];
  if (game->arena[index] == 1 || game->arena[index] == 9 ||
      game->arena[index] == 12 || game->arena[index] == 15)
    ret->nb_arg = 1;
  else
    if (get_desc(game->arena[index + 1], ret))
      {
	free(ret);
	return (NULL);
      }
  get_arg(game, index, ret);
  if (is_reg_valid(ret))
    {
      free(ret);
      return (NULL);
    }
  return (ret);
}
