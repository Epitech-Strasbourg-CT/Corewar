/*
** kill_player.c for kill_player in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar 23 15:26:05 2017 Arthur Knoepflin
** Last update Thu Mar 23 16:12:00 2017 Arthur Knoepflin
*/

#include "corewar.h"

void		kill_player(t_game *g, int id)
{
  t_heads	*tmp;
  t_heads	*next;

  tmp = g->heads;
  while (tmp)
    {
      if (tmp->id == id)
	{
	  next = tmp->next;
	  while (next && next->id == id)
	    next = next->next;
	  delete_heads(tmp, &g->heads);
	  tmp = next;
	}
      if (tmp)
	tmp = tmp->next;
    }
}
