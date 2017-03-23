/*
** zjmp.c for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/corewar
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar 23 18:19:11 2017 Nicolas Polomack
** Last update Thu Mar 23 18:24:19 2017 Nicolas Polomack
*/

#include "corewar.h"

void	zjmp(t_game *g, t_heads *h, t_ins *in)
{
  if (h->carry)
    h->pos += in->val[0];
}
