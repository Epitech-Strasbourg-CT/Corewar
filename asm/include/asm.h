/*
** asm.h for asm_corware in /home/cedric/delivery/CPE/CPE_2016_corewar
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Wed Mar  1 09:59:16 2017 
** Last update Wed Mar  1 17:36:50 2017 Nicolas Polomack
*/
#ifndef ASM_H_
# define ASM_H_

typedef struct		s_label
{
  char			*name;
  int			instruct_nb;
  struct s_label	*prev;
  struct s_label	*next;
}			t_label;

typedef struct		s_header
{
  
}			t_header;

typedef struct		s_instruct
{
  struct s_instruct	*prev;
  struct s_instruct	*next;
}			t_instruct;

typedef struct		s_asm
{
  char			**file;
  t_header		header;
}			t_asm;

/*
** file.c
*/

void	display_file(char **);
char	**my_realloc(char **, char *, int);
int	read_file(t_asm *, char *);
int	check_dir(char *);

/*
**misc.c
*/

/*
**str.c
*/
int	my_strnlen(char *str, char *c);
char	*my_strndup(char *str, int len);

/*
**endian.c
*/
void		swap_endian(void *raw, int size);

/*
**epurstr.c
*/
char	*my_epurnstr(char *str, int nbspace, char *to_ep, char replace);

#endif /* !ASM_H_ */
