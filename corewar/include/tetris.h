/*
** tetris.h for tetris in /home/nicolaspolomack/psu/2/PSU_2016_tetris
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Mon Feb 20 14:36:25 2017 Nicolas Polomack
** Last update Sat Feb 25 14:38:17 2017 Arthur Knoepflin
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# define SIZE_BUF_T 2048

#include <fcntl.h>
#include <termio.h>

typedef struct	s_controls
{
  char		*top;
  char		*drop;
  char		*left;
  char		*right;
  char		*quit;
  char		*pause;
}		t_controls;

typedef struct	s_tetra
{
  int		error;
  int		height;
  int		width;
  int		color;
  char		*name;
  char		**tetra;
}		t_tetra;

typedef struct	s_map
{
  char		**present;
  int		**color;
}		t_map;

typedef struct		s_tetris
{
  int			level;
  int			debug;
  int			without;
  int			help;
  int			width;
  int			height;
  int			score;
  int			h_score;
  int			pause;
  struct termio		old;
  char			*seq;
  char			**map;
  t_tetra		**tetra;
  t_controls		keys;
}			t_tetris;

/*
** free_parse.c
*/

int	free_tetra(t_tetra **);
int	free_tab(char **);

/*
** get_next_line.c
*/

char	*get_next_line(int);

/*
** debug.c
*/

void	debug_print(t_tetris *);

/*
** init.c
*/

void	init(t_tetris *);
void	init_keys(t_tetris *);

/*
** termcaps.c
*/

void	set_raw(t_tetris *);
int	play_game(t_tetris *);

/*
** misc.c
*/

void	handle_error(char *);
int	is_big_enough(t_tetris *, struct winsize *);
char	get_input();

/*
** events.c
*/

int	handle_events(t_tetris *);

/*
** display.c
*/

int	disp_guide();
void	display_all(t_tetris *, struct winsize *);
void	display_time(struct winsize *);

/*
** match.c
*/

int	match(char *, char *);

/*
** my_split.c
*/

char	**my_split(char *, char);

/*
** PARSE TETRA
** tetrimino/epurstrlen.c
*/

int	my_epurstrlen(char *);
int	nb_space(char *);
int	calc_width_bef(char **);
int	width_line(char *);

/*
** tetrimino/get_name.c
*/

char	*get_name(char *);

/*
** tetrimino/load_tetra.c
*/

char	**load_tetra(char *);

/*
** tetrimino/tetrimino.c
*/

int	nb_tetri(t_tetra **, int);
int	my_epurstrlen(char *);
t_tetra	**parse_tetraminoes(char *);

/*
** tetrimino/nb_tetra.c
*/

char	*cat_url(char *, char *);
int	nb_tetra(char *);

/*
** tetrimino/parse_header.c
*/

void	parse_header(t_tetra *, char **);

/*
** tetrimino/parse_tetri.c
*/

void	parse_tetri(t_tetra *, char **);

/*
** tetrimino/sort.c
*/

t_tetra	**sort_tetra(t_tetra **);

#endif /* !TETRIS_H_ */
