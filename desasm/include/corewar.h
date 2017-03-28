/*
** corewar.h for corewar in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Thu Mar  9 19:04:34 2017 Arthur Knoepflin
** Last update Tue Mar 28 17:55:31 2017 
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# define BUF_SIZE	2048

# include "op.h"

typedef struct	s_ins
{
  int		nb_arg;
  int		cmd;
  int		type[4];
  long		val[4];
  int		tot_byte;
}		t_ins;

/*
** instruct/get_arg.c
*/

int	extract_val(unsigned char *, int);
int	get_arg(unsigned char *, int, t_ins *);
/*
** instruct/get_desc.c
*/

int	get_desc(unsigned int, t_ins *);

/*
** instruct/get_instruc.c
*/

t_ins	*get_instruc(unsigned char *, int);

/*
**str.c
*/
int	my_cstrnlen(char *str, char c);
int	my_strnlen(char *str, char *c);
char	*my_strndup(char *str, int len);
int	composed_of(char *str, char *only_composed);

/*
**file.c
*/
int	read_header(int fd, t_header *head);
void	write_instructs(t_header *head, char *file, int fd);

/*
**put.c
*/
void	my_fputchar(int fd, char c);
void	my_fputstr(int fd, char *str);
void	my_fputnbr(int fd, long nb);

/*
**args_write.c
*/
void	write_arg(int fd, t_ins *current, int arg);

#endif /* !COREWAR_H_ */
