/*
** standard.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Sun Mar 19 19:01:48 2017 Nicolas Polomack
** Last update Sun Mar 19 19:27:40 2017 
*/

#include <unistd.h>
#include "asm.h"
#include "my.h"
#include "op.h"

void	write_standard_reg(t_instruct *instruct, int index, t_asm *myasm)
{
  char	*reg;
  int	size;
  char	*byte_code;
  char	str[REG_SIZE];
  int	i;

  reg = instruct->args[index] + 1;
  my_memset(str, 0, REG_SIZE);
  byte_code = my_char_int_to_bytes(reg, &size);
  my_strncpy(str + (REG_SIZE - size), byte_code, size);
  write(myasm->fd, str, REG_SIZE);
}

void	write_standard_dir(t_instruct *instruct, int index, t_asm *myasm)
{
  char	*dir;
  int	size;
  char	*byte_code;
  char	str[DIR_SIZE];

  dir = instruct->args[index];
  my_memset(str, 0, 4);
  if ((instruct->op->type[0] & T_LAB) == T_LAB)
    dir = my_unsigned_to_char((unsigned int)
                              label_to_addr(myasm, instruct,
                                            dir + 2, &size));
  else
  	dir = my_unsigned_to_char(my_getnbr(dir + 1));
  if (size)
    my_printf("error : %d\n", size);
  byte_code = my_char_int_to_bytes(dir + (dir[0] == '%'), &size);
  my_strncpy(str + (DIR_SIZE - size), byte_code, size);
  write(myasm->fd, str, DIR_SIZE);
}

void	write_standard_ind(t_instruct *instruct, int index, t_asm *myasm)
{
  char	*ind;
  int	size;
  char	*byte_code;
  char	str[IND_SIZE];

  ind = instruct->args[index];
  my_memset(str, 0, IND_SIZE);
  if ((instruct->op->type[0] & T_LAB) == T_LAB)
    ind = my_unsigned_to_char((unsigned int)
                              label_to_addr(myasm, instruct,
                                            ind + 1, &size));
  else
  	ind = my_unsigned_to_char(my_getnbr(ind));
  if (size)
    my_printf("error : %d\n", size);
  byte_code = my_char_int_to_bytes(ind, &size);
  my_strncpy(str + (IND_SIZE - size), byte_code, size);
  write(myasm->fd, str, IND_SIZE);
}

void	write_standard(t_instruct *current, t_asm *myasm)
{
  int	i;
  t_op	*op;

  i = -1;
  op = current->op;
  while (++i < op->nbr_args)
    {
      if (op->type[i] == T_REG)
	write_standard_reg(current, i, myasm);
      else if ((op->type[i] & T_IND) == T_IND)
	write_standard_ind(current, i, myasm);
      else if ((op->type[i] & T_DIR) == T_DIR)
	write_standard_dir(current, i, myasm);
    }
}

