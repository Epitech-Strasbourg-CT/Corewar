/*
** main.c for main.c in /home/cedric/delivery/ex
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Mon Mar 13 23:33:35 2017 Arthur Knoepflin
*/

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
