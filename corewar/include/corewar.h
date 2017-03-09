/*
** corewar.h for corewar in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar  9 19:04:34 2017 Arthur Knoepflin
** Last update Thu Mar  9 23:24:32 2017 Arthur Knoepflin
*/

#ifndef COREWAR_H_
# define COREWAR_H_

typedef struct		s_nchamp
{
  int			id;
  int			load_addr;
  char			*path;
  struct s_nchamp	*next;
  struct s_nchamp	*prev;
}			t_nchamp;

typedef struct		s_parse
{
  unsigned int		dump;
  int			nb_champ;
  struct s_nchamp	*first;
  struct s_nchamp	*last;
}			t_parse;

/*
** parse.c
*/

t_parse	*get_parse(int, char **);

/*
** parse_error.c
*/

int	check_error(int, char **);

/*
** parse_error_2.c
*/

int	print_unknown_arg(char *);
int	check_valid_arg(int, char **);

#endif /* !COREWAR_H_ */
