/*
** instruct.c for asm in /home/cedric/delivery/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Tue Mar 14 14:32:36 2017 
** Last update Sat Mar 18 22:01:00 2017 
*/
#include <unistd.h>
#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my.h"

int	get_arg_size(char type)
{ 
  if (type == T_REG)
    return (REG_SIZE);
  else if ((type & T_IND) == T_IND)
    return (IND_SIZE);
  else if ((type & T_DIR) == T_DIR)
    return (DIR_SIZE);
}

static char	get_arg_mask(char type)
{
  if (type == T_REG)
    return (1);
  else if ((type & T_IND) == T_IND)
    return (3);
    else if ((type & T_DIR) == T_DIR)
    return (2);
}

int	get_instruct_size(t_instruct *instruct)
{
  int	i;
  int	size;
  t_op	*my_op;

  size = 1;
  if (instruct->op == NULL)
    return (0);
  my_op = instruct->op;
  i = -1;
  if (my_op->nbr_args > 1)
    size += my_op->nbr_args / 4 + (my_op->nbr_args % 4 ? 1 : 0);
  printf("size 1: %d, %d\n", size);
  while (++i < my_op->nbr_args)
    size += get_arg_size(my_op->type[i]);
  printf("size f: %d\n", size);
  return (size);
}

int	write_args_type(t_instruct *instruct, int fd)
{
  char	current;
  int	args;
  int	i;
  t_op	*my_op;

  my_op = instruct->op;
  if (my_op->nbr_args == 1)
    return (0); 
  args = -1;
  while (++args < my_op->nbr_args)
    {
      i = -1;
      current = 0;
      while (++i < 4)
	if (args < my_op->nbr_args)
	  {
	    current += get_arg_mask(my_op->type[args]) << (6 - i * 2);
	    args += 1;
	  }
      write(fd, &current, 1);
    }
  return (0);
}

int	load_instruct(t_asm *myasm)
{
  int	i;

  i = -1;
  myasm->instructs = NULL;  
  while (myasm->file[++i])
    my_put_list_instruct(&myasm->instructs, myasm->file[i]);
  free(myasm->file);
  myasm->file = NULL;
  return (0);
}
