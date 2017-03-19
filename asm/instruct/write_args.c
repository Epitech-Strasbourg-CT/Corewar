/*
** write_args.c for asm in /home/cedric/delivery/CPE/CPE_2016_corewar/asm
**
** Made by
** Login   <cedric.thomas@epitech.eu>
**
** Started on  Fri Mar 17 13:02:48 2017
** Last update Sun Mar 19 14:35:45 2017 
*/
#include <unistd.h>
#include "my_printf.h"
#include "op.h"
#include "asm.h"
#include "my.h"

static void		write_reg(char *reg, int fd)
{
  int			size;
  char			*byte_code;

  byte_code = my_char_int_to_bytes(reg + 1, &size);
  write(fd, byte_code, REG_SIZE);
}

static void	write_ind(t_instruct *current, int index, t_asm *myasm)
{
  char		*ind;
  int		size;
  char		*byte_code;
  char		str[IND_SIZE];

  size = index;
  ind = current->args[index];
  my_memset(str, 0, IND_SIZE);
  if ((current->op->type[index] & T_LAB) == T_LAB)
    ind = my_unsigned_to_char((unsigned int)label_to_addr(myasm, current, ind + 1, &size));
  if (size)
    my_printf("error : %d\n", size);
  printf("%s\n", ind);
  byte_code = my_char_int_to_bytes(ind, &size);
  my_strncpy(str + (IND_SIZE - size), byte_code, size);
  //  swap_endian(str, IND_SIZE);
  write(myasm->fd, str, IND_SIZE);
}

//int     label_to_addr(t_asm *myasm, t_instruct *current, char *name, int *error);


static void	write_dir(t_instruct *current, int index, t_asm *myasm)
{
  char		*dir;
  int		size;
  char		*byte_code;
  char		str[DIR_SIZE];

  size = index;
  dir = current->args[index];
  my_memset(str, 0, DIR_SIZE);
  if ((current->op->type[index] & T_LAB) == T_LAB)
    dir = my_unsigned_to_char((unsigned int)label_to_addr(myasm, current, dir + 2, &size));
  if (size)
    my_printf("error : %d\n", size);
  printf("%s\n", dir);
  byte_code = my_char_int_to_bytes(dir + (dir[0] == '%'), &size);
  my_strncpy(str + (DIR_SIZE - size), byte_code, size);
  //  swap_endian(str, DIR_SIZE);
  write(myasm->fd, str, DIR_SIZE);
}

static int	write_args(t_instruct *current, t_asm *myasm)
{
  int		i;
  char		**args;
  t_op		*op;

  i = -1;
  op = current->op;
  args = current->args;
  while (args[++i])
    {
      if (op->type[i] == T_REG)
	write_reg(args[i], myasm->fd);
      else if ((op->type[i] & T_IND) == T_IND)
      	write_ind(current, i, myasm);
      else if ((op->type[i] & T_DIR) == T_DIR)
      	write_dir(current, i, myasm);
    }
  return (0);
}

int		write_instructs(t_instruct *instructs, t_asm *myasm)
{
  t_op		*current;
  int		i;
  t_instruct	*tmp;

  i = 0;
  tmp = instructs;
  while (tmp && ++i)
    {
      current = tmp->op;
      write(myasm->fd, &current->code, sizeof(char));
      write_args_type(tmp, myasm->fd);
      write_args(tmp, myasm);
      tmp = tmp->next;
    }
}
