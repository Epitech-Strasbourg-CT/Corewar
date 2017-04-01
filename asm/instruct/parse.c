/*
** commands.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Sun Mar 12 15:46:29 2017 Nicolas Polomack
** Last update Sat Apr  1 01:57:24 2017 Nicolas Polomack
*/

#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my.h"
#include "my_printf.h"

int	is_valid_command(char *command)
{
  int	i;

  i = -1;
  while (g_op_tab[++i].mnemonique != 0)
    if (my_strcmp(g_op_tab[i].mnemonique, command) == 0)
      return (1);
  return (0);
}

int	parse_types(t_op *cur, char **command)
{
  int	i;

  i = -1;
  while (command[++i])
    if (command[i][0] == DIRECT_CHAR)
      {
	if (command[i][1] == LABEL_CHAR &&
	    composed_of(command[i] + 2, LABEL_CHARS))
	  cur->type[i] = T_LAB | T_DIR;
	else if (my_str_isnum(command[i] + 1 + (command[i][1] == '-')))
	  cur->type[i] = T_DIR;
      }
    else if (command[i][0] == LABEL_CHAR &&
	     composed_of(command[i] + 1, LABEL_CHARS))
      cur->type[i] = T_LAB | T_IND;
    else if (command[i][0] == 'r' && my_str_isnum(command[i] + 1) &&
	     is_betw(1, my_getnbr(command[i] + 1), REG_NUMBER))
      cur->type[i] = T_REG;
    else if (my_str_isnum(command[i] + (command[i][0] == '-')))
      cur->type[i] = T_IND;
    else
      error_parse(command[i]);
  return (0);
}

int	are_same_type(t_op *cur, t_op *ref)
{
  int	i;

  i = -1;
  while (++i < cur->nbr_args)
    if ((cur->type[i] & ref->type[i]) == 0)
      return (0);
  return (1);
}

int	check_command_args(char **command, t_op *op_cur)
{
  int	i;

  op_cur->nbr_args = -1;
  while (command[(int)++(op_cur->nbr_args)]);
  if (parse_types(op_cur, command) == 84)
    return (0);
  i = -1;
  while (g_op_tab[++i].mnemonique != 0)
    if (my_strcmp(g_op_tab[i].mnemonique, op_cur->mnemonique) == 0)
      {
        op_cur->code = g_op_tab[i].code;
        if (op_cur->nbr_args != g_op_tab[i].nbr_args ||
	    !are_same_type(op_cur, g_op_tab + i))
	  {
	    my_printf("%sERROR%s: Bad arguments for the opcode '%s' ",
		      YELLOW, RESET, g_op_tab[i].mnemonique);
	    return (0);
	  }
        op_cur->nbr_cycles = g_op_tab[i].nbr_cycles;
	return (1);
      }
  my_printf("%sERROR%s: Bad opcode for '%s' ", YELLOW, RESET,
	    op_cur->mnemonique);
  return (0);
}

void		parse_commands(t_asm *a)
{
  int		idx;
  t_instruct	*t;
  char		**list;
  char		*arg;
  int		i;

  t = a->instructs;
  idx = 0;
  while (t && ++idx)
    {
      i = 0;
      while (t->raw[i] && t->raw[i] != ' ')
	i += 1;
      arg = my_epurnstr(my_strdup(t->raw), 0, " ", ' ');
      list = my_split(arg + i, ',');
      check_nb_args( arg + i, list, idx);
      my_memset((char *)t->op, 0, sizeof(t_op));
      t->op->mnemonique = my_strndup(arg, i);
      if ((check_command_args(list, t->op)) == 0)
	exit(84 + 0 * my_printf("at instruct number %d\n", idx));
      free(arg);
      t->args = list;
      t = t->next;
    }
}
