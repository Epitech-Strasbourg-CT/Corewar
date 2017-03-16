/*
** corewar.h for corewar in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar  9 19:04:34 2017 Arthur Knoepflin
** Last update Thu Mar 16 21:15:49 2017 Arthur Knoepflin
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# define BUF_SIZE	2048

typedef struct	s_nchamp
{
  int		id;
  int		load_addr;
  char		*path;
  int		size;
  char		*name;
  char		*comment;
  char		*code;
}		t_nchamp;

typedef struct		s_parse
{
  unsigned int		dump;
  int			nb_champ;
  struct s_nchamp	*champ[4];
}			t_parse;

typedef struct	s_game
{
  t_parse	*parse;
  unsigned char	*arena;
  int		cycle;
}		t_game;

/*
** arena_create.c
*/

char	*arena_create(void);

/*
** load_champ.c
*/

void	load_champ(t_game *, t_nchamp *);

/*
** dump.c
*/

void	dump(t_game *);

/*
** endian.c
*/

void	swap_endian(void *, int);

/*
** game.c
*/

int	game(t_parse *);

/*
** parse.c
*/

t_parse	*get_parse(int, char **);

/*
** parse_champ.c
*/

int	parse_champ(t_parse *, int, char **);

/*
** parse_error.c
*/

int	is_an_arg(char *);
int	check_error(int, char **);

/*
** parse_error_2.c
*/

int	print_unknown_arg(char *);
int	check_valid_arg(int, char **);
int	check_nb_champ(int, char **);

/*
** parse_get_list_id.c
*/

char	*get_list_id(int, char **);
int	check_id(int, char **);

/*
** parse_file_champ.c
*/

int	parse_file_champ(t_parse *);

/*
** parse_file.c
*/

int	read_comment(int, char *, t_nchamp *);
int	read_name(int, char *, t_nchamp *);
int	check_magic_number(int, char *);
int	parse_header(int, char *, t_nchamp *);

/*
** read_file.c
*/

char	*read_file(int);

#endif /* !COREWAR_H_ */
