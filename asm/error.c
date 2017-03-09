/*
** error.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar  9 20:00:51 2017 Nicolas Polomack
** Last update Thu Mar  9 20:01:11 2017 Nicolas Polomack
*/

void	error_header(int i, int j, int k)
{
  my_printf("ERROR:%d:%d: Two %s defined.\n", i, j,
            (k) ? "names" : "comments");
  exit(84);
}
