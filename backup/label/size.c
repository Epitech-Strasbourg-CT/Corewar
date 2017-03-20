/*
** size.c for asm in /home/cedric/delivery/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Sat Mar 18 16:18:30 2017 
** Last update Sun Mar 19 20:25:23 2017 
*/
#include <stdlib.h>
#include "my.h"
#include "asm.h"
#include "op.h"

static int	find_instruct_index(t_asm *myasm, t_instruct *current, int *error)
{
  int		index;
  t_instruct	*to_find;

  index = 0;
  to_find = myasm->instructs;
  while (to_find && to_find != current)
    {
      index += 1;
      to_find = to_find->next;
    }
  if (to_find == NULL)
    {
      *error = 3;
      return (-1);
    }
  return (index);
}

static t_instruct	*find_instruct(t_asm *myasm, char *name, int *index, int *error)
{
  t_label		*lab;
  t_instruct		*to_find;

  *index = 0;
  lab = myasm->labels;
  to_find = myasm->instructs;
  while (lab && my_strcmp(lab->name, name))
    lab = lab->next;
  if (lab == NULL)
    {
      *error = 1;
      return (NULL);
    }
  while (to_find && to_find->raw != lab->line)
    {
      *index += 1;
      to_find = to_find->next;
    }
  if (to_find == NULL)
    *error = 2;
  return (to_find);
}

int		calc_size(t_instruct *first, t_instruct *sec, int index, int mod)
{
  int		i;
  int		size;

  size = 0;
  /* if (mod == -1) */
  /*   { */
  /*     size += 1; */
  /*     if (sec->op->nbr_args > 1) */
  /*     	size += sec->op->nbr_args / 4 + (sec->op->nbr_args % 4 ? 1 : 0); */
  /*     i = -1; */
  /*     while (++i < index) */
  /* 	size += get_arg_size(sec->op->type[i]); */
  /*   } */
  /* else if (mod == 1) */
  /*   { */
  /*     i = index - 1; */
  /*     while (++i < first->op->nbr_args) */
  /* 	size += get_arg_size(first->op->type[i]); */
  /*   } */
  while (sec && first && first != sec)
    {
      size += get_instruct_size(first);
      first = first->next;
    }
  //  printf("size betw lab : %d\n", size);
  return (size * mod);
}

int		label_to_addr(t_asm *myasm, t_instruct *current, char *name, int *error)
{
  int		index;
  char		*line;
  t_instruct	*to_find;
  int		idx_find;
  int		idx_current;

  index = *error;
  *error = 0;
  if ((to_find = find_instruct(myasm, name, &idx_find, error)) == NULL)
    return (0);
  if ((idx_current = find_instruct_index(myasm, current, error)) == -1)
    return (0);
  //printf("ligne courante : %d, ligne trouvé : %d\n", idx_current, idx_find);
  if (idx_find < idx_current)
    return (calc_size(to_find, current, index, -1));
  else if (idx_find > idx_current)
    return (calc_size(current, to_find, index, 1));
  else
    return (0);
}
