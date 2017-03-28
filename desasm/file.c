/*
** header.c for desasm in /home/cedric/CPE_2016_corewar/desasm
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Tue Mar 28 12:56:07 2017 
** Last update Tue Mar 28 17:18:58 2017 
*/
#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"
#include "my.h"

void		swap_endian(void *raw, int size)
{
  unsigned char	*converted;
  unsigned char	c;
  int	i;
  int	j;

  converted = (unsigned char *)raw;
  i = -1;
  j = size - 1;
  while (++i < j)
    {
      c = converted[i];
      converted[i] = converted[j];
      converted[j] = c;
      j -= 1;
    }
}

int	read_header(int fd, t_header *head)
{
  if (read(fd, head, sizeof(t_header)) < sizeof(t_header))
    return (84);
  swap_endian(&head->magic, sizeof(head->magic));
  swap_endian(&head->prog_size, sizeof(head->magic));
  if (head->magic != COREWAR_EXEC_MAGIC)
    return (84);
}

static void	write_header(t_header *head, int fd)
{
  write(fd, ".name \"", my_strlen(".name \""));
  write(fd, head->prog_name, my_strlen(head->prog_name));
  write(fd, "\"\n", 2);
  write(fd, ".comment \"", my_strlen(".comment \""));
  write(fd, head->comment, my_strlen(head->comment));
  write(fd, "\"\n\n", 3);
}

void	write_instructs(t_header *head, char *file, int fd)
{
  int	arg;
  t_ins	*current;
  int	max;
  int	index;

  max = head->prog_size;
  index = 0;
  write_header(head, fd);
  while (index < max)
    {
      if ((current = get_instruc(file, index)) == NULL)
	exit(42);
      my_fputstr(fd, g_op_tab[current->cmd - 1].mnemonique);
      my_fputstr(fd, " ");
      arg = -1;
      while (++arg < current->nb_arg)
	{
	  if (arg != 0)
	    my_fputstr(fd, ",");
	  write_arg(fd, current, arg);
	}
      my_fputstr(fd, "\n");
      index += current->tot_byte;
    }
}
