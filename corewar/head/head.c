/*
** head.c for head in /home/Maxime/delivery/CPE/CPE_2016_corewar/corewar/head/
**
** Made by Maxime Jenny
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Mon Mar 20 12:52:28 2017 Maxime Jenny
** Last update Tue Mar 21 23:10:27 2017 
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
  elem->head_id = id;
  elem->next = NULL;
  if ((*list) == NULL)
    {
      (*list) = elem;
      return (0);
    }
  tmp = (*list);
  while ((*list)->next != NULL)
    (*list) = (*list)->next;
  (*list)->next = elem;
  (*list) = tmp;
  return (0);
}

int		delete_heads(t_heads *index, t_heads **list)
{
  t_heads *tmp;

  tmp = *list;
  if (*list == index)
    *list = (*list)->next;
  while (tmp && tmp->next != index && tmp != index)
    tmp = tmp->next;
  if (index && tmp)
    tmp->next = index->next;
  free(index);
  return (0);
}

int		delete_heads_fulllist(t_heads **heads)
{
  while (*heads)
    delete_heads(heads, heads);
}
