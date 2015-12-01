/*
** my.h for BSQ in /CPE_2015_bsq
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Thu Nov 26 10:17:03 2015 Antoine Baché
** Last update Tue Dec  1 01:43:36 2015 Antoine Baché
*/

#ifndef MY_H_
# define MY_H_
# define BUFF_SIZE 4096

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

void	show_map(char *, int *, int, int);
void	my_putstr(char *);
void	my_putstr_err(char *);
int	get_min(int, int, int);
int	check_lowest(int *, int, int);
int	*update_max(int *, int, int);
int	*prepare_tab(char *, int, int *, int);
int	get_firstline(char *);
int	*set_max();
char	*parse_file(int, int *);
char	*my_realloc(char *, char *, int, int *);
int	my_strlen(char *);
int	exit_main(int, char *, int *);
int	*exit_prepare_tab(int *, int *);
int	*prepare_my_size(int *);

#endif /* !MY_H_ */
