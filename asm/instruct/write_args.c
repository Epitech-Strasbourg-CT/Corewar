/*
** write_args.c for asm in /home/cedric/delivery/CPE/CPE_2016_corewar/asm
**
** Made by
** Login   <cedric.thomas@epitech.eu>
**
** Started on  Fri Mar 17 13:02:48 2017
** Last update Sat Mar 18 17:01:02 2017 Nicolas Polomack
*/
#include <unistd.h>
#include "my_printf.h"
#include "op.h"
#include "asm.h"

static void		write_reg(char *reg, int fd)
{
  int			size;
  char			*byte_code;

  byte_code = my_char_int_to_bytes(reg + 1, &size);
  swap_endian(byte_code, size);
  write(fd, byte_code, size);
}

static void	write_ind(char *ind, int fd, char type, t_asm *myasm)
{
  int		size;
  char		*byte_code;

  if (type & T_LAB == T_LAB)
    ind = my_int_to_char(label_to_addr(myasm, ind + 1, &size));
  //if (size)
    // error
  byte_code = my_char_int_to_bytes(ind, &size);
  swap_endian(byte_code, size);
  write(fd, byte_code, size);
}

static void	write_dir(char *dir, int fd, char type, t_asm *myasm)
{
  int		size;
  char		*byte_code;

  size = 0;
  if (type & T_LAB == T_LAB)
    dir = my_int_to_char(label_to_addr(myasm, dir + 2, &size));
  //if (size)
  // error
  byte_code = my_char_int_to_bytes(dir + (dir[0] == '%'), &size);
  swap_endian(byte_code, size);
  write(fd, byte_code, size);
}

static int	write_args(char **args, t_op *op, int fd, t_asm *myasm)
{
  int		i;

  i = -1;
  while (args[++i])
    {
      if (op->type[i] == T_REG)
	write_reg(args[i], fd);
      else if (op->type[i] & T_IND == T_IND)
	write_ind(args[i], fd, op->type[i], myasm);
      else if (op->type[i] & T_DIR == T_DIR)
	write_dir(args[i], fd, op->type[i], myasm);
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
      write_args(tmp->args, tmp->op, myasm->fd, myasm);
      tmp = tmp->next;
    }
}
