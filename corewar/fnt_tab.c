/*
** fnt_tab.c for fnt_tab in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Wed Mar 22 23:08:40 2017 Arthur Knoepflin
** Last update Tue Mar 28 17:46:37 2017 Arthur Knoepflin
*/

#include "corewar.h"

void	get_fnt_tab(void (*fnt[16])(t_game *, t_heads *, t_ins *))
{
  fnt[0] = &live;
  fnt[1] = &ld;
  fnt[2] = &st;
  fnt[3] = &add;
  fnt[4] = &sub;
  fnt[5] = &and;
  fnt[6] = &or;
  fnt[7] = &xor;
  fnt[8] = &zjmp;
  fnt[9] = &ldi;
  fnt[10] = &sti;
  fnt[11] = &fork_head;
  fnt[12] = &ld;
  fnt[13] = &ldi;
  fnt[14] = &fork_head;
  fnt[15] = &aff;
}
