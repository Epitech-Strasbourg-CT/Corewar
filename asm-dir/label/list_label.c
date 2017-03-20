/*
** module_list.c for module_list in /home/cedric/Desktop/pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Nov 21 12:15:25 2016 Cédric Thomas
** Last update Mon Mar 13 18:37:52 2017 Cédric Thomas
*/
#include <stdlib.h>
#include "my_printf.h"
#include "my.h"
#include "asm.h"

int		my_put_list_label(t_label **ll, char *name, char *line)
{
  t_label	*elem;
  t_label	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    exit(84);
  elem->name = name;
  elem->line = line;
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

int		my_show_label(t_label *ll)
{
  while (ll != NULL)
    {
      my_printf("Name : %s,\n%s\n\n", ll->name, ll->line);
      ll = ll->next;
    }
  return (0);
}

int		my_del_list_label(t_label **ll, t_label *elem)
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
  free(elem);
  return (0);
}

int		my_free_label(t_label **ll)
{
  while (*ll != NULL)
    my_del_list_label(ll, *ll);
  *ll = NULL;
  return (0);
}
