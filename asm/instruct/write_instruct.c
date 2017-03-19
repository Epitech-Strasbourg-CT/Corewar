/*
** write_args.c for asm in /home/cedric/delivery/CPE/CPE_2016_corewar/asm
**
** Made by
** Login   <cedric.thomas@epitech.eu>
**
** Started on  Fri Mar 17 13:02:48 2017
** Last update Sun Mar 19 18:36:22 2017 
*/
#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"
#include "op.h"
#include "asm.h"
#include "my.h"

static void	fill_fct(void (*fct[16])(t_instruct *current, t_asm *myasm))
{
  fct[0] = NULL;
  fct[1] = NULL;
  fct[2] = NULL;
  fct[3] = NULL;
  fct[4] = NULL;
  fct[5] = NULL;
  fct[6] = NULL;
  fct[7] = NULL;
  fct[8] = NULL; 
  fct[9] = NULL;
  fct[10] = NULL;
  fct[11] = NULL;
  fct[12] = NULL;
  fct[13] = NULL;
  fct[14] = NULL;
  fct[15] = NULL;
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
  while (tmp)
    {
      current = tmp->op;
      write(myasm->fd, &current->code, sizeof(char));
      write_args(tmp, myasm, fct);
      tmp = tmp->next;
    }
  return (0);
}
