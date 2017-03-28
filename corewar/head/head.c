/*
** head.c for head in /home/Maxime/delivery/CPE/CPE_2016_corewar/corewar/head/
**
** Made by Maxime Jenny
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Mon Mar 20 12:52:28 2017 Maxime Jenny
** Last update Tue Mar 28 19:36:51 2017 Arthur Knoepflin
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
    {
      out[i] = in[i];
      /* printf("TEST : %d\n", in[i]); */
    }
}

int		new_head(t_heads in, t_heads **list)
{
  t_heads	*elem;
  t_heads	*tmp;

  /* printf("%d\n", in.reg[0]); */
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

int		delete_heads(t_heads *index, t_heads **list)
{
  t_heads	*tmp;

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
    delete_heads(*heads, heads);
}
