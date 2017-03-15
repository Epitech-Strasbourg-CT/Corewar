/*
** commands.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Sun Mar 12 15:46:29 2017 Nicolas Polomack
** Last update Tue Mar 14 16:19:13 2017 
*/

#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my.h"

int	is_valid_command(char *command)
{
  int	i;

  i = -1;
  while (op_tab[++i].mnemonique != 0)
    if (my_strcmp(op_tab[i].mnemonique, command) == 0)
      return (1);
  return (0);
}

void  parse_types(t_op *cur, char **command)
{
  int i;

  i = 0;
  while (command[++i])
  {
    if (command[i][0] == DIRECT_CHAR)
      if (command[i][1] == LABEL_CHAR)
        cur->type[i - 1] += T_LAB;
      else
        cur->type[i - 1] += T_DIR;
    else if (command[i][0] == 'r')
      cur->type[i - 1] += T_REG;
    else if (command[i][0] >= '0' && command[i][0] <= '9')
      cur->type[i - 1] += T_IND;
    else
      exit(84);
  }
}

int are_same_type(t_op *cur, t_op *ref)
{
  int i;

  i = -1;
  while (++i < cur->nbr_args)
    if (cur->type[i] != ref->type[i])
      return (0);
  return (1);
}

int	check_command_args(char **command, int fd, t_op *op_cur)
{
  int	i;

  my_memset((char *)op_cur, 0, sizeof(t_op));
  op_cur->mnemonique = command[0];
  op_cur->nbr_args = -1;
  while(command[++(op_cur->nbr_args)]);
  op_cur->nbr_args -= 1;
  parse_types(op_cur, command);
  i = -1;
  while (op_tab[++i].mnemonique != 0)
    if (my_strcmp(op_tab[i].mnemonique, command[0]) == 0)
      {
        op_cur->code = op_tab[i].code;
        if (op_cur->nbr_args != op_tab[i].nbr_args ||
        !are_same_type(op_cur, op_tab + i))
          return (0);
        op_cur->nbr_cycles = op_tab[i].nbr_cycles;
        break;
      }
  //  write_command(op_cur, fd);
  return (1);
}

void		parse_commands(t_asm *a)
{
	t_instruct *t;
	char	**list;
	char	*arg;
	int		i;
  
  t = a->instructs;
  while (t)
  {
	  arg = my_strdup(t->raw);
	  i = 0;
	  while (arg[i] && arg[i] != ' ')
	  	i += 1;
	  arg = my_epurnstr(arg, 0, " ", ' ');
	  list = my_split(arg + i, ',');
	  if ((check_command_args(list, a->fd, t->op)) == 0)
	  	exit(84);
	  free(arg);
	  t->args = list;
	  t = t->next;
  }
}
