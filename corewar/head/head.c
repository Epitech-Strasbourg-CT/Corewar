/*
** head.c for head in /home/Maxime/delivery/CPE/CPE_2016_corewar/corewar/head/
**
** Made by Maxime Jenny
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Mon Mar 20 12:52:28 2017 Maxime Jenny
** Last update Mon Mar 20 13:08:02 2017 Maxime Jenny
*/

#include <stdlib.h>
#include "corewar.h"

int		new_head(int champion_id, int position, t_heads **list)
{
  t_heads	*elem;
  t_heads	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  elem->champion_id = champion_id;
  elem->pos = pos;
  elem->next = NULL;
  if ((*list) == NULL)
    {
      (*list) = elem;
      return (0);
    }
  tmp = (*list);
  while ((*list)->next != NULL)
    (*list) = (*list)->next;
  elem->head_id = id;
  (*list)->next = elem;
  (*list) = tmp;
  return (0);
}

int		delete_heads(t_heads **precedent_head, t_heads **head_to_del)
{
  if ((*precedent_head)->next == NULL)
    return (-1);
  (*precedent_head)->next = (*head_to_del)->next;
  free(head_to_del);
  return (0);
}
