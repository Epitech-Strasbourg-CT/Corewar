/*
** add.h for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/corewar
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar 23 18:11:31 2017 Nicolas Polomack
** Last update Thu Mar 23 18:13:52 2017 Nicolas Polomack
*/

#include "corewar.h"

void	sub(t_game *g, t_heads *h, t_ins *in)
{
  h->reg[in->val[2]] = h->reg[in->val[0]] - h->reg[in->val[1]];
}

