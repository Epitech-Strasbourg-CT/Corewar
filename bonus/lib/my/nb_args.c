/*
** nb_args.c for nb_args in /home/arthur/delivery/PSU/PSU_2016_tetris
** 
** Made by 
** Login   <arthur@epitech.net>
** 
** Started on  Tue Feb 21 10:50:36 2017 
** Last update Tue Feb 21 10:51:20 2017 
*/

int	nb_args(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i += 1;
  return (i);
}
