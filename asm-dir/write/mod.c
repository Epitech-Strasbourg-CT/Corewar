/*
** mod.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm-dir
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Mon Mar 20 12:18:35 2017 Nicolas Polomack
** Last update Mon Mar 20 17:08:38 2017 Nicolas Polomack
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "my.h"
#include "my_printf.h"
#include "op.h"

void	write_standard_dir_mod(t_instruct *instruct, int index, t_asm *myasm)
{
  char	*dir;
  int	size;
  char	*byte_code;
  char	str[DIR_SIZE / 2];

  size = 0;
  dir = instruct->args[index];
  my_memset(str, 0, DIR_SIZE / 2);
  if ((instruct->op->type[index] & T_LAB) == T_LAB)
    dir = my_unsigned_to_char((unsigned int)
                              label_to_addr(myasm, instruct,
                                            dir + 2, &size));
  else
    dir = my_unsigned_to_char(my_getnbr(dir + 1));
  if (size)
    my_printf("error dir : %d\n", size);
  byte_code = my_char_int_to_bytes(dir + (dir[0] == '%'), &size);
  my_strncpy(str + ((DIR_SIZE / 2) - size), byte_code, size);
  write(myasm->fd, str, DIR_SIZE / 2);
}

void	write_standard_ind_mod(t_instruct *instruct, int index, t_asm *myasm)
{
  char	*ind;
  int	size;
  char	*byte_code;
  char	str[IND_SIZE / 2];

  ind = instruct->args[index];
  my_memset(str, 0, IND_SIZE / 2);
  size = 0;
  if ((instruct->op->type[index] & T_LAB) == T_LAB)
    ind = my_unsigned_to_char((unsigned int)
                              label_to_addr(myasm, instruct,
                                            ind + 1, &size));
  else
    ind = my_unsigned_to_char(my_getnbr(ind));
  if (size)
    my_printf("error ind : %d\n", size);
  byte_code = my_char_int_to_bytes(ind, &size);
  my_strncpy(str + ((IND_SIZE / 2) - size), byte_code, size);
  write(myasm->fd, str, IND_SIZE / 2);
}

void	write_standard_mod(t_instruct *current, t_asm *myasm)
{
  int	i;
  t_op	*op;

  i = -1;
  op = current->op;
  write_args_type(current, myasm->fd);
  while (++i < op->nbr_args)
    {
      if (op->type[i] == T_REG)
	write_standard_reg(current, i, myasm);
      else if ((op->type[i] & T_IND) == T_IND)
	write_standard_ind(current, i, myasm);
      else if ((op->type[i] & T_DIR) == T_DIR)
	write_standard_dir_mod(current, i, myasm);
    }
}
