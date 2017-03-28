/*
** main.c for main in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Feb 28 18:47:35 2017 Arthur Knoepflin
** Last update Tue Mar 28 17:57:59 2017 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "corewar.h"
#include "my.h"

static char		*chang_ext(char *old_path, char *ext_base, char *ext_new)
{
  int			len;
  char			*new_path;
  char			*last;

  if ((len = my_strlen(old_path) - my_strlen(ext_base)) < 0)
    return (NULL);
  if (my_strcmp(old_path + len, ext_base))
    return (NULL);
  if ((new_path = my_strndup(old_path, len)) == NULL)
    return (NULL);
  last = my_strcatdup(new_path, ext_new);
  free(new_path);
  return (last);
}

static int	multi_open(int *wr, int *rd, t_header *head, char *path)
{
  char		*new_path;

  if ((new_path = chang_ext(path, ".cor", ".ds")) == NULL)
    {
      my_puterror("Error : Invalid extension\n");
      return (-1);
    }
  if ((*rd = open(path, O_RDONLY)) == -1)
    {
      my_puterror("Error : Open failed\n");
      return (-1);
    }
  if (read_header(*rd, head) == 84)
    {
      my_puterror("Error : Not a compatible .cor\n");
      return (-1);
    }
  if ((*wr = open(new_path, O_CREAT | O_TRUNC | O_WRONLY,
		  S_IRWXU | S_IRWXO | S_IRWXG)) == -1)
    {
      my_puterror("Error : creation of the .s failed\n");
      return (-1);
    }
  free(new_path);
  return (0);
}

static int	multi_close(int wr, int rd)
{
  close(wr);
  close(rd);
}

static char	*get_file(int rd, t_header *head)
{
  char		c;
  int		offset;
  char		*file;

  if ((file = malloc(sizeof(char) * (head->prog_size))) == NULL)
    return (NULL);
  if (read(rd, file, head->prog_size) < head->prog_size)
    {
      my_puterror("Error : Invalid file size (inf)\n");
      free(file);
      return (NULL);
    }
  if (read(rd, &c, 1) != 0)
    {
      my_puterror("Error : Invalid file size (sup)\n");
      free(file);
      return (NULL);
    }
  int i = -1;
  while (++i<head->prog_size)
    my_fputchar(2, file[i]);
  return (file);
}

int		main(int ac, char **av)
{
  t_header	header;
  int		fd_wr;
  int		fd_rd;
  char		*file;

  if (ac != 2)
    return (84);
  my_putstr("Check File Validity ...\n");
  if (multi_open(&fd_wr, &fd_rd, &header, av[1]) < 0)
    return (84);
  my_putstr("OK!\nCheck File Size and read ...\n");
  if ((file = get_file(fd_rd, &header)) == NULL)
    return (84);
  my_putstr("OK!\nWrite new file ...\n");
  write_instructs(&header, file, fd_wr);
  my_putstr("OK!\n");
  free(file);
  multi_close(fd_wr, fd_rd);
  return (0);
}
