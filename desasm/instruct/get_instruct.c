/*
** get_instruct.c for get_instruct in /delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Mar 20 21:50:27 2017 Arthur Knoepflin
** Last update Tue Mar 28 17:55:01 2017 
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

static void	memset_int(void *tab, int val, int len, int mode)
{
  int		i;

  i = -1;
  while (++i < len)
    if (mode == 1)
      ((int *) tab)[i] = val;
    else
      ((long *) tab)[i] = val;
}

t_ins	*get_instruc(unsigned char *champ, int index)
{
  t_ins	*ret;

  if (champ[index] <= 0 || champ[index] > 16)
    return (NULL);
  if ((ret = malloc(sizeof(t_ins))) == NULL)
    return (NULL);
  memset_int(ret->val, 0, 4, 0);
  memset_int(ret->type, -1, 4, 1);
  ret->cmd = champ[index];
  if (champ[index] == 1 || champ[index] == 9 ||
      champ[index] == 12 || champ[index] == 15)
    ret->nb_arg = 1;
  else
    if (get_desc((unsigned int)champ[index + 1], ret))
      {
	free(ret);
	return (NULL);
      }
  get_arg(champ, index, ret);
  if (is_reg_valid(ret))
    {
      free(ret);
      return (NULL);
    }
  return (ret);
}
