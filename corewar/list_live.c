/*
** list_live.c for VM - corewar in /home/cedric/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Thu Mar 23 21:26:50 2017 
** Last update Thu Mar 23 21:38:52 2017 
*/

#include <stdlib.h>
#include "my.h"
#include "corewar.h"

int		my_put_list_live(t_live **ll, char *name)
{
  t_live	*elem;
  t_live	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    exit(84);
  elem->name = name;
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

int		my_show_live(t_live *ll)
{
  while (ll != NULL)
    {
      my_putstr(ll->name);
      my_putchar('\n');
      ll = ll->next;
    }
  return (0);
}

int		my_del_list_live(t_live **ll, t_live *elem)
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
  free(elem->name);
  free(elem);
  return (0);
}

int		my_free_live(t_live **ll)
{
  while (*ll != NULL)
    my_del_list_live(ll, *ll);
  *ll = NULL;
  return (0);
}
