/*
** init_head.c for init_head in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Mar 21 22:52:43 2017 Arthur Knoepflin
** Last update Tue Mar 28 20:45:41 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"
#include "op.h"

static void	set_reg(t_heads *val, int id)
{
  int		i;

  i = -1;
  while (++i < REG_NUMBER)
    val->reg[i] = 0;
  val->reg[0] = id;
}

void		init_head(t_game *game)
{
  t_ins		*ins;
  t_heads	*val;
  t_heads	*tmp;
  int		i;
  int		j;

  game->heads = NULL;
  i = -1;
  while (++i < game->parse->nb_champ)
    {
      if ((val = malloc(sizeof(t_heads))) == NULL)
	return ;
      val->id = game->parse->champ[i]->id;
      set_reg(val, val->id);
      val->carry = 0;
      ins = get_instruc(game, game->parse->champ[i]->load_addr);
      if (ins)
	{
	  val->ctn_cycle = g_op_tab[ins->cmd - 1].nbr_cycles;
	  free(ins);
	}
      else
	val->ctn_cycle = 0;
      val->pos = game->parse->champ[i]->load_addr;
      new_head(*val, &(game->heads));
      free(val);
    }
}

