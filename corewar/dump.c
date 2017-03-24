/*
** dump.c for dump in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar 16 19:07:46 2017 Arthur Knoepflin
** Last update Fri Mar 24 15:55:30 2017 Arthur Knoepflin
*/

#include "corewar.h"
#include "op.h"
#include "my.h"

void	print_nb_line(int i)
{
  int	j;
  int	max;
  int	line;

  max = size_nb(MEM_SIZE, "0123456789ABCDEF");
  line = size_nb(i * 32, "0123456789ABCDEF");
  my_putnbr_base(i * 32, "0123456789ABCDEF");
  j = -1;
  while (++j < (max + 1) - line)
    my_putchar(' ');
  my_putstr(": ");
}

void	dump(t_game *game)
{
  int	i;
  int	j;

  i = -1;
  i = 0;
  /* while (++i < MEM_SIZE / 32) */
  /*   { */
      print_nb_line(i);
      j = -1;
      while (++j < 32)
	{
	  if (size_nb(game->arena[i * 32 + j], "0123456789ABCDEF") == 1)
	    my_putchar('0');
	  my_putnbr_base(game->arena[i * 32 + j], "0123456789ABCDEF");
	  if (j != 31)
	    my_putchar(' ');
	}
      my_putchar('\n');
    /* } */
}
