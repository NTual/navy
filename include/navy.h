/*
** navy.h for  in /home/hugo.tallineau/PSU_2016_navy
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Mon Jan 30 17:47:17 2017 Hugo Tallineau
** Last update Thu Feb  9 17:19:30 2017 Hugo Tallineau
*/

#ifndef NAVY_H
# define NAVY_H

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>

# define EXIT_SUCCESS 0

int	g_global[3];

void	my_putchar(char);
void	my_putstr(char*);
void	usage(void);
char	*my_xmalloc(int);
char	**my_str_to_wordtab(char*);
char	**read_map(char*);
void	my_xfree(char*);
void	disp_map(char**);
char	**check_map(char**);
char	**check_cross(char**);
int	exec_j1(int, char**);
void	disp_my_board(char**);
void	my_putnbr(int);
char	**set_map(void);
void	disp_maps(char**, char**);
int	is_hitten(char**, int, int);
int	try_attack(char**, int, int, int);
void	get_order(int*, int*, int, char**);
char	*get_next_line(int);
int	check_win(char**, char**, int);
int	exec_j2(int, char**);
pid_t	get_j2_pid(void);
void	receive(int, char**);
int	my_getnbr(char*);
void	my_send(int, int, int, char**);
void	disp_pid(void);
size_t	my_strlen(char*);
void	my_strcapitalize(char*);
int	my_check_pos(char*);
char	**check_position(char**);
char	**check_order(char**);
int	is_num(char);
char	**my_sort_array(char**);
void	set_global(char**, int, int);
int	do_stuff_j1(char**);
int	do_stuff_j2(char**);

#endif /* NAVY_H */
