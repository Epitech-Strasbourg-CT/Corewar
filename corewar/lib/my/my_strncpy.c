/*
** my_strncpy.c for my_strncpy in /home/nicolas.polomack/CPool_Day06
** 
** Made by Nicolas POLOMACK
** Login   <nicolas.polomack@epitech.net>
** 
** Started on  Mon Oct 10 09:22:36 2016 Nicolas POLOMACK
** Last update Fri Mar 24 15:31:14 2017 Arthur Knoepflin
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	count;

  count = 0;
  while (n > 0)
    {
      dest[count] = src[count];
      count = count + 1;
      n = n - 1;
    }
  return (dest);
}
