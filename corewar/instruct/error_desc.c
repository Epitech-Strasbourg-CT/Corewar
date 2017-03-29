/*
** error_desc.c for error_desc in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Mar 28 23:36:19 2017 Arthur Knoepflin
** Last update Wed Mar 29 17:35:48 2017 Arthur Knoepflin
*/

#include "corewar.h"

int	error_desc(t_ins *ret)
{
  int	i;

  i = -1;
  while (++i < ret->nb_arg)
    {
      if (ret->type[i] == 1 &&
	  (g_op_tab[ret->cmd - 1].type[i] & T_REG) != T_REG)
	return (1);
      if (ret->type[i] == 2 &&
	  (g_op_tab[ret->cmd - 1].type[i] & T_DIR) != T_DIR)
	return (1);
      if (ret->type[i] == 3 &&
	  (g_op_tab[ret->cmd - 1].type[i] & T_IND) != T_IND)
	return (1);
      if (ret->type[i] == 1 &&
	  (ret->val[i] < 1 || ret->val[i] > REG_NUMBER))
	return (1);
    }
  return (0);
}
