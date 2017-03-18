/*
** write_args.c for asm in /home/cedric/delivery/CPE/CPE_2016_corewar/asm
**
** Made by
** Login   <cedric.thomas@epitech.eu>
**
** Started on  Fri Mar 17 13:02:48 2017
** Last update Sat Mar 18 16:06:47 2017 
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

static void	write_ind(char *ind, int fd, char type, t_instruct *instructs)
{
  
}

static void	write_dir(char *dir, int fd, char type, t_instruct *instructs)
{

}

static int	write_args(char **args, t_op *op, int fd, t_instruct *instructs)
{
  int		i;

  i = -1;
  while (args[++i])
    {
      if (op->type[i] == T_REG)
	write_reg(args[i], fd);
      else if (op->type[i] & T_IND == T_IND)
	write_ind(args[i], fd, op->type[i], instructs);
      else if (op->type[i] & T_DIR == T_DIR)
	write_dir(args[i], fd, op->type[i], instructs);
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
      write_args(tmp->args, tmp->op, myasm->fd, instructs);
      tmp = tmp->next;
    }
}
