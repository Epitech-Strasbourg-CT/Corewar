/*
** header.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Wed Mar  1 19:36:44 2017 Nicolas Polomack
** Last update Mon Mar 20 19:09:48 2017 
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "my.h"
#include "op.h"
#include "my_printf.h"

void	suppress_line(char **file, int i)
{
  free(file[i]);
  file[i] = NULL;
  while (file[++i])
    file[i - 1] = file[i];
  file[i - 1] = NULL;
}

void	parse_name(t_asm *a, int *i, int j, int *indic)
{
  int   l;
  int   t;
  char  quote;

  l = 0;
  while (a->file[*i][j + l] && (a->file[*i][j + l] == ' ' ||
                               a->file[*i][j + l] == '\t'))
    l += 1;
  quote = a->file[*i][j + l];
  if (quote != '"' && quote != '\'')
    exit(84 + 0 * my_printf("%sERROR%s:%d:%d: Invalid character\n",
			    GREEN, RESET, *i, j + l));
  t = ++l;
  while (a->file[*i][j + t] && a->file[*i][j + t] != quote)
    t += 1;
  if (a->file[*i][j + t] != quote || a->file[*i][j + t + 1] != 0)
    exit(84 + 0 * my_printf("%sERROR%s:%d:%d: Invalid quotes.\n",
			    GREEN, RESET, *i, j + l));
  a->header.name = my_strndup(&(a->file[*i][j + l]), t - l);
  suppress_line(a->file, *i);
  *i = -1;
}

void	parse_comment(t_asm *a, int *i, int j, int *indic)
{
  int	l;
  int	t;
  char	quote;

  l = 0;
  while (a->file[*i][j + l] && (a->file[*i][j + l] == ' ' ||
                               a->file[*i][j + l] == '\t'))
    l += 1;
  quote = a->file[*i][j + l];
  if (quote != '"' && quote != '\'')
    exit(84 + 0 * my_printf("%sERROR%s:%d:%d: Invalid character\n",
			    GREEN, RESET, *i, j + l));
  t = ++l;
  while (a->file[*i][j + t] && a->file[*i][j + t] != quote)
    t += 1;
  if (a->file[*i][j + t] != quote || a->file[*i][j + t + 1] != 0)
    exit(84 + 0 * my_printf("%sERROR%s:%d:%d: Invalid quotes.\n",
			    GREEN, RESET, *i, j + l));
  a->header.comment = my_strndup(&(a->file[*i][j + l]), t - l);
  suppress_line(a->file, *i);
  *i = -1;
}

static void	logic(t_asm *a, int *name, int *comment)
{
  int		i;
  int		j;

  i = -1;
  while (a->file[++i])
    {
      j = 0;
      while (a->file[i][j] && (a->file[i][j] == ' ' ||
                               a->file[i][j] == '\t'))
        j += 1;
      if (my_strncmp(&(a->file[i][j]), NAME_CMD_STRING,
		     5) == 0 && (*name)++ == 0)
        parse_name(a, &i, j + 5, name);
      else if (my_strncmp(&(a->file[i][j]), COMMENT_CMD_STRING,
			  8) == 0 && (*comment)++ == 0)
        parse_comment(a, &i, j + 8, comment);
      else if (*name == 2 || *comment == 2)
        error_header(i, j, (*name == 2) ? 1 : 0);
	  else
	  	a->file[i] = my_epurnstr(a->file[i], 1, " \t", ' ');
      j += 1;
    }
}

void	parse_headers(t_asm *a)
{
  int	name;
  int	comment;

  name = 0;
  comment = 0;
  logic(a, &name, &comment);
  if (a->header.name == NULL || a->header.comment == NULL)
    exit(84 + 0 * my_printf("%sERROR%s: No '%s' found.\n",
			    GREEN, RESET,
			    (!name) ? NAME_CMD_STRING : COMMENT_CMD_STRING));
}
