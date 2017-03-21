/*
** corewar.h for corewar in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Thu Mar  9 19:04:34 2017 Arthur Knoepflin
** Last update Tue Mar 21 20:52:42 2017 
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# define BUF_SIZE	2048

typedef struct		s_heads
{
  int			champion_id;
  int			pos;
  struct s_heads	*next;
}			t_heads;

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
** head/head.c
*/

int		new_head(int champion_id, int position, t_heads **list);
int		delete_heads(t_heads **precedent_head, t_heads **head_to_del);

/*
** arena_create.c
*/

char	*arena_create(void);
int	init_arena(t_game *);

/*
** average_champ.c
*/

int	get_ecart(t_parse *);

/*
** is_overlap.c
*/

int	*get_tab_pos(t_parse *, int);
int	is_overlap_lock(t_parse *);

/*
** load_champ.c
*/

int	nb_champ_with_addr(t_parse *);
int	load_champ(t_game *, t_nchamp *, int);
int	load_all_champ(t_game *, int);
int	load_champ_addr(t_game *, int);

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
