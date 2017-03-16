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

  i = -1;
  while (command[++i])
  {
    if (command[i][0] == DIRECT_CHAR)
      if (command[i][1] == LABEL_CHAR)
        cur->type[i] = T_LAB;
      else
        cur->type[i] = T_DIR;
    else if (command[i][0] == 'r' && my_str_isnum(command[i] + 1) &&
	is_betw(1, my_getnbr(command[i] + 1), REG_NUMBER))
      cur->type[i] = T_REG;
    else if (my_str_isnum(command[i] + (command[i][0] == '-')))
      cur->type[i] = T_IND;
    else
	{
	  my_puterror(cur->mnemonique);
	  my_puterror(": Invalid types\n");
      exit(84);
	}
  }
}

int are_same_type(t_op *cur, t_op *ref)
{
  int i;

  i = -1;
  while (++i < cur->nbr_args)
    if ((cur->type[i] & ref->type[i]) == 0)
      return (0);
  return (1);
}

int	check_command_args(char **command, int fd, t_op *op_cur)
{
  int	i;

  op_cur->nbr_args = -1;
  while(command[++(op_cur->nbr_args)]);
  parse_types(op_cur, command);
  i = -1;
  while (op_tab[++i].mnemonique != 0)
    if (my_strcmp(op_tab[i].mnemonique, op_cur->mnemonique) == 0)
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
	  i = 0;
	  while (t->raw[i] && t->raw[i] != ' ')
	  	i += 1;
	  t->raw = my_epurnstr(t->raw, 0, " ", ' ');
	  list = my_split(t->raw + i, ',');
  	  my_memset((char *)t->op, 0, sizeof(t_op));
	  t->op->mnemonique = my_strndup(t->raw, i);
	  if ((check_command_args(list, a->fd, t->op)) == 0)
	  	{
		  my_puterror("Syntax error\n");
		  exit(84);
		}
	  t->args = list;
	  t = t->next;
  }
}
