/*
** header.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Wed Mar  1 19:36:44 2017 Nicolas Polomack
** Last update Thu Mar  2 07:45:32 2017 Nicolas Polomack
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "my.h"
#include "my_printf.h"

void	error_header(int i, int j, int k)
{
  my_printf("ERROR:%d:%d: Two %s defined.\n", i, j,
	    (k) ? "names" : "comments");
  exit(84);
}

void	parse_name(t_asm *a, int i, int j, int *indic)
{
  int   l;
  int   t;
  char  quote;

  l = 0;
  while (a->file[i][j + l] && (a->file[i][j + l] == ' ' ||
                               a->file[i][j + l] == '\t'))
    l += 1;
  quote = a->file[i][j + l];
  if (quote != '"' && quote != '\'')
    {
      my_printf("ERROR:%d:%d: Invalid character\n", i, j + l);
      exit(84);
    }
  t = ++l;
  while (a->file[i][j + t] && a->file[i][j + t] != quote)
    t += 1;
  if (a->file[i][j + t] != quote || a->file[i][j + t + 1] != 0)
    {
      my_printf("ERROR:%d:%d: Invalid quotes.\n", i, j + l);
      exit(84);
    }
  a->header.name = my_strndup(&(a->file[i][j + l]), t - l);
}

void	parse_comment(t_asm *a, int i, int j, int *indic)
{
  int	l;
  int	t;
  char	quote;

  l = 0;
  while (a->file[i][j + l] && (a->file[i][j + l] == ' ' ||
                               a->file[i][j + l] == '\t'))
    l += 1;
  quote = a->file[i][j + l];
  if (quote != '"' && quote != '\'')
    {
      my_printf("ERROR:%d:%d: Invalid character\n", i, j + l);
      exit(84);
    }
  t = ++l;
  while (a->file[i][j + t] && a->file[i][j + t] != quote)
    t += 1;
  if (a->file[i][j + t] != quote || a->file[i][j + t + 1] != 0)
    {
      my_printf("ERROR:%d:%d: Invalid quotes.\n", i, j + l);
      exit(84);
    }
  a->header.comment = my_strndup(&(a->file[i][j + l]), t - l);
}

void	parse_headers(t_asm *a)
{
  int	i;
  int	j;
  int	name;
  int	comment;

  name = 0;
  comment = 0;
  i = -1;
  while (a->file[++i])
    {
      j = 0;
      while (a->file[i][j] && (a->file[i][j] == ' ' ||
			       a->file[i][j] == '\t'))
	j += 1;
      if (my_strncmp(&(a->file[i][j]), ".name", 5) == 0 && name++ == 0)
	parse_name(a, i, j + 5, &name);
      else if (my_strncmp(&(a->file[i][j]), ".comment", 8) == 0 && comment++ == 0)
	parse_comment(a, i, j + 8, &comment);
      else if (name == 2 || comment == 2)
	error_header(i, j, (name == 2) ? 1 : 0);
      j += 1;
    }
}
