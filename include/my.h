/*
** my.h for BSQ in /CPE_2015_bsq
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Nov 26 10:17:03 2015 Antoine Baché
** Last update Tue Dec  8 10:59:12 2015 Antoine Baché
*/

#ifndef MY_H_
# define MY_H_
# define BUFF_SIZE 50331648

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

void	show_map(char *, int *, int, int);
void	my_putstr_err(char *);
int	get_min(int, int, int);
int	check_lowest(int *, int, int);
int	*update_max(int *, int, int);
int	*prepare_tab(char *, int, int *, int);
int	get_firstline(char *);
int	*set_max();
char	*parse_file(int, int *, char *);
char	*my_realloc(char *, char *, int, int *);
int	my_strlen(char *);
int	exit_main(int, char *, int *, char *);
int	*exit_prepare_tab(int *, int *);
int	*prepare_my_size(int *);
int	free_main(int *, char *, char *);
int	wrong_nb_arg();

#endif /* !MY_H_ */
