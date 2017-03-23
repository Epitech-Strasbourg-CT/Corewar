/*
** my_memset.c for memset in /home/cedric
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Oct 31 16:15:04 2016 Cédric Thomas
** Last update Mon Oct 31 16:15:06 2016 Cédric Thomas
*/

void	my_memset(char *str, int c, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      str[i] = c;
      i += 1;
    }
}
