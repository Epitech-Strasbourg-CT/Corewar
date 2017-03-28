/*
** args_write.c for args_write in /home/cedric/CPE_2016_corewar/desasm
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Tue Mar 28 14:48:07 2017 
** Last update Tue Mar 28 17:56:17 2017 
*/
#include "corewar.h"

static void	write_reg(int fd, long value)
{
  my_fputstr(fd, "r");
  my_fputnbr(fd, value);
}

static void	write_ind(int fd, long value)
{
  my_fputnbr(fd, value);
}

static void	write_dir(int fd, long value)
{
  my_fputstr(fd, "%");
  my_fputnbr(fd, value);
}

void	write_arg(int fd, t_ins *current, int args)
{
  if (current->type[args] == 1)
    write_reg(fd, current->val[args]);
  else if (current->type[args] == 2)
    write_dir(fd, current->val[args]);
  else if (current->type[args] == 3)
    write_ind(fd, current->val[args]);
}
