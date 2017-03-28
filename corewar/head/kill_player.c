/*
** kill_player.c for kill_player in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar 23 15:26:05 2017 Arthur Knoepflin
** Last update Tue Mar 28 16:24:45 2017 Arthur Knoepflin
*/

#include "corewar.h"

void		kill_player(t_game *g, int id)
{
  t_heads	*tmp;
  t_heads	*next;

  while (g->read && g->read->id == id)
    g->read = g->read->next;
  tmp = g->heads;
  while (tmp)
    {
      if (tmp->id == id)
	{
	  next = tmp->next;
	  delete_heads(tmp, &g->heads);
	  tmp = next;
	}
      else
	tmp = tmp->next;
    }
}
