/*
** zjmp.c for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/corewar
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar 23 18:19:11 2017 Nicolas Polomack
** Last update Fri Mar 24 16:47:58 2017 Arthur Knoepflin
*/

#include "corewar.h"
#include "op.h"

void	zjmp(t_game *g, t_heads *h, t_ins *in)
{
  if (!h->carry)
    {
      h->pos += in->val[0];
      h->pos %= MEM_SIZE;
    }
}
