/*
** fnt_tab.c for fnt_tab in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Wed Mar 22 23:08:40 2017 Arthur Knoepflin
** Last update Thu Mar 23 00:00:18 2017 Arthur Knoepflin
*/

#include "corewar.h"

void	get_fnt_tab(void (*fnt[16])(t_game *, t_heads *, t_ins *))
{
  fnt[0] = &live;
}
