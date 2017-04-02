/*
** my_strcpy.c for my_strcpy in /home/nicolas.polomack/CPool_Day06
** 
** Made by Nicolas POLOMACK
** Login   <nicolas.polomack@epitech.net>
** 
** Started on  Mon Oct 10 09:09:04 2016 Nicolas POLOMACK
** Last update Fri Mar 31 21:04:57 2017 Arthur Knoepflin
*/

char	*my_strcpy(char *dest, char *src)
{
  int	count;

  count = -1;
  while (src[++count])
    dest[count] = src[count];
  return (dest);
}
