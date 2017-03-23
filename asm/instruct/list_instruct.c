/*
** module_list.c for module_list in /home/cedric/Desktop/pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Nov 21 12:15:25 2016 Cédric Thomas
** Last update Mon Mar 20 18:42:33 2017 
*/
#include <stdlib.h>
#include "my_printf.h"
#include "my.h"
#include "op.h"
#include "asm.h"

int		my_put_list_instruct(t_instruct **ll, char *raw)
{
  t_instruct	*elem;
  t_instruct	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    exit(84);
  if ((elem->op = malloc(sizeof(t_op))) == NULL)
    exit(84);
  my_memset((char *)elem->op, 0, sizeof(t_op));
  elem->raw = raw;
  if (*ll == NULL)
    {
      elem->next = NULL;
      elem->prev = NULL;
      *ll = elem;
    }
  else
    {
      tmp = *ll;
      while (tmp->next != NULL)
	tmp = tmp->next;
      elem->prev = tmp;
      elem->next = NULL;
      tmp->next = elem;
    }
  return (0);
}

int		my_show_instruct(t_instruct *ll)
{
  int		i;

  i = 0;
  while (ll != NULL)
    {
      i += 1;
      my_printf("line %d : %s\n", i, ll->raw);
      ll = ll->next;
    }
  return (0);
}

int		my_del_list_instruct(t_instruct **ll, t_instruct *elem)
{
  if (*ll == elem)
    {
      if ((*ll)->next != NULL)
	*ll = (*ll)->next;
      else if ((*ll)->prev != NULL)
	*ll = (*ll)->prev;
      else
	*ll = NULL;
    }
  if (elem->next != NULL)
    elem->next->prev = elem->prev;
  if (elem->prev != NULL)
    elem->prev->next = elem->next;
  free(elem->op->mnemonique);
  free(elem->op);
  free(elem->raw);
  free_tab(elem->args);
  free(elem);
  return (0);
}

int		my_free_instruct(t_instruct **ll)
{
  while (*ll != NULL)
    my_del_list_instruct(ll, *ll);
  *ll = NULL;
  return (0);
}
