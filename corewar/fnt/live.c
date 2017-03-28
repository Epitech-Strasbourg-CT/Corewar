/*
** live.c for live in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Wed Mar 22 23:16:12 2017 Arthur Knoepflin
** Last update Tue Mar 28 16:42:03 2017 Arthur Knoepflin
*/

#include "corewar.h"

void	live(t_game *g, t_heads *h, t_ins *ins)
{
  if (ins->val[0] >= 1 && ins->val[0] <= 4)
    {
      /* printf("Le joueur %d est en vie\n", h->id); */
      g->live[ins->val[0] - 1] += 1;
    }
}
