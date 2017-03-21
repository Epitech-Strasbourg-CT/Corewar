/*
** get_instruct.c for get_instruct in /delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Mar 20 21:50:27 2017 Arthur Knoepflin
** Last update Mon Mar 20 23:51:52 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"

t_ins	*get_instruc(t_game *game, int index)
{
  t_ins	*ret;

  if ((ret = malloc(sizeof(t_ins))) == NULL)
    return (NULL);
  my_memset(ret->val, 0, 4);
  my_memset(ret->type, -1, 4);
  if (game->arena[index] > 16)
    return (NULL);
  ret->cmd = game->arena[index];
  if (game->arena[index] == 1 || game->arena[index] == 9 ||
      game->arena[index] == 12 || game->arena[index] == 15)
    ret->nb_arg = 1;
  else
    if (get_desc(game->arena[index + 1], ret))
      return (NULL);
  get_arg(game, index, ret);
  return (ret);
}
