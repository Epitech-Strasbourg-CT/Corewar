/*
** head.c for head in /home/Maxime/delivery/CPE/CPE_2016_corewar/corewar/head/
**
** Made by Maxime Jenny
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Mon Mar 20 12:52:28 2017 Maxime Jenny
** Last update Wed Mar 22 23:22:54 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"
#include "op.h"

static void	my_assign(int *out, int *in)
{
  int		i;

  i = -1;
  while (++i < REG_NUMBER)
    out[i] = in[i];
}

int		new_head(t_heads in, t_heads **list)
{
  t_heads	*elem;
  t_heads	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (1);
  elem->carry = in.carry;
  my_assign(elem->reg, in.reg);
  elem->pos = in.pos;
  elem->id = in.id;
  elem->ctn_cycle = in.ctn_cycle;
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

int		delete_heads(t_heads **precedent_head, t_heads **head_to_del)
{
  if ((*precedent_head)->next == NULL)
    return (-1);
  (*precedent_head)->next = (*head_to_del)->next;
  free(head_to_del);
  return (0);
}
