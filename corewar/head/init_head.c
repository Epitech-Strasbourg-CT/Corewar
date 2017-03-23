/*
** init_head.c for init_head in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Mar 21 22:52:43 2017 Arthur Knoepflin
** Last update Thu Mar 23 22:36:34 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"
#include "op.h"

void		init_head(t_game *game)
{
  t_ins		*ins;
  t_heads	val;
  t_heads	*tmp;
  int		i;

  i = -1;
  game->heads = NULL;
  while (++i < game->parse->nb_champ)
    {
      val.id = game->parse->champ[i]->id;
      my_memset(val.reg, 0, REG_NUMBER);
      val.reg[0] = val.id;
      val.carry = 0;
      ins = get_instruc(game, game->parse->champ[i]->load_addr);
      if (ins)
	{
	  val.ctn_cycle = g_op_tab[ins->cmd - 1].nbr_cycles;
	  free(ins);
	}
      else
	val.ctn_cycle = 0;
      val.pos = game->parse->champ[i]->load_addr;
      new_head(val, &(game->heads));
    }
}

