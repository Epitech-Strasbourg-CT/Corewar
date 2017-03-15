/*
** label.c for asm in /home/cedric/delivery/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Mon Mar 13 14:56:55 2017 
** Last update Tue Mar 14 15:43:13 2017 
*/
#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "op.h"

static char	*suppress_label(char *line, char *label)
{
  int		len;
  char		*new_line;

  len = my_strlen(label);
  if ((new_line = my_strdup(line + len + 1)) == NULL)
    return (NULL);
  free(line);
  return (new_line);
}

static char	*get_label(char *line)
{
  int		len;
  char		*label;

  if (!is_in(LABEL_CHAR, line))
    return (NULL);
  len = my_cstrnlen(line, LABEL_CHAR);
  if ((label = my_strndup(line, len)) == NULL)
    return (NULL);
  if (!is_only_composed_of(label, LABEL_CHARS))
    {
      free(label);
      return (NULL);
    }
  return (label);
}

static char	*set_next_valid_line(char *line, char **tab)
{
  int		i;

  i = -1;
  while (tab[++i] && tab[i] != line);
  i -= 1;
  while (tab[++i] && is_only_composed_of(tab[i], " \t"));
  return (tab[i]);
}

int		check_list(t_label **my_label)
{
  t_label	*tested;
  t_label	*temp;

  tested = *my_label;
  while (tested != NULL)
    {
      temp = *my_label;
      while (temp != NULL)
	{
	  if (temp != tested && !my_strcmp(temp->name, tested->name))
	    return (error_double_label(my_label, temp->name));
	  temp = temp->next;
	}
      tested = tested->next;
    }
  return (0);
}

int		change_label(t_asm *my_asm)
{
  t_label	*my_label;
  t_label	*temp;
  int		i;
  char		*label;

  i = -1;
  my_label = NULL;
  while (my_asm->file[++i])
    if ((label = get_label(my_asm->file[i])) != NULL)
      {
	my_asm->file[i] = suppress_label(my_asm->file[i], label);
	my_asm->file[i] = my_epurnstr(my_asm->file[i], 1, " \t", ' ');
	my_put_list_label(&my_label, label, my_asm->file[i]);
      }
  temp = my_label;
  while (temp != NULL)
    {
      temp->line = set_next_valid_line(temp->line, my_asm->file);
      temp = temp->next;
    }
  if (check_list(&my_label) == 84)
    return (84);
  my_asm->labels = my_label;
  my_asm->file = epurtab(my_asm);
  return (0);
}
