/*
** st.c for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/corewar
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar 23 17:02:39 2017 Nicolas Polomack
** Last update Fri Mar 24 13:25:19 2017 Nicolas Polomack
*/

#include "corewar.h"
#include "my.h"

void	st(t_game *g, t_heads *h, t_ins *in)
{
  int	pos;

  pos = in->val[0] + ((in->type[0] == 3) ? h->pos : 0);
  my_strncpy(g->arena + pos, (char *)&h->reg[in->val[1] - 1], REG_SIZE);
}
