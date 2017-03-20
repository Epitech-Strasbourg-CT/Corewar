/*
** write_args.c for asm in /home/cedric/delivery/CPE/CPE_2016_corewar/asm
**
** Made by
** Login   <cedric.thomas@epitech.eu>
**
** Started on  Fri Mar 17 13:02:48 2017
** Last update Mon Mar 20 13:57:56 2017 Nicolas Polomack
*/
#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"
#include "op.h"
#include "asm.h"
#include "my.h"

static void	fill_fct(void (*fct[16])(t_instruct *current, t_asm *myasm))
{
  fct[0x0] = &write_live_instruct;
  fct[0x1] = &write_standard_mod;
  fct[0x2] = &write_standard_mod;
  fct[0x3] = &write_math_instruct;
  fct[0x4] = &write_math_instruct;
  fct[0x5] = &write_logic_instruct;
  fct[0x6] = &write_logic_instruct;
  fct[0x7] = &write_logic_instruct;
  fct[0x8] = &write_simple_instruct;
  fct[0x9] = &write_standard_mod;
  fct[0xa] = &write_standard_mod;
  fct[0xb] = &write_simple_instruct;
  fct[0xc] = &write_standard;
  fct[0xd] = &write_standard;
  fct[0xe] = &write_simple_instruct;
  fct[0xf] = &write_standard;
}

static int	write_args(t_instruct *current, t_asm *myasm,
			   void (*fct[MAX_OPCODE])(t_instruct *current, t_asm *myasm))
{
  int		i;

  i = -1;
  while (++i < MAX_OPCODE)
    {
      if (!my_strcmp(current->op->mnemonique, g_op_tab[i].mnemonique))
	if (fct[i])
	  fct[i](current, myasm);
    }
  return (0);
}

int		write_instructs(t_instruct *instructs, t_asm *myasm)
{
  void		(*fct[MAX_OPCODE])(t_instruct *current, t_asm *myasm);
  t_op		*current;
  t_instruct	*tmp;

  tmp = instructs;
  fill_fct(fct);
  while (tmp)
    {
      current = tmp->op;
      write(myasm->fd, &current->code, sizeof(char));
      write_args(tmp, myasm, fct);
      tmp = tmp->next;
    }
  return (0);
}
