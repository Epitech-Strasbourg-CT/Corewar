/*
** VM - Corewar for aff in /home/cedric/delivery/CPE/CPE_2016_corewar/corewar/fnt
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Thu Mar 23 18:10:13 2017 
** Last update Wed Mar 29 17:56:25 2017 Arthur Knoepflin
*/
#include "my.h"
#include "corewar.h"

void	aff(t_game *g, t_heads *h, t_ins *in)
{
  (void)g;
  my_putchar(h->reg[in->val[0] - 1] % 256);
}
  
