/*
** bsq.c for BSQ in /CPE_2015_bsq
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Nov 26 10:19:13 2015 Antoine Baché
** Last update Tue Dec  8 10:34:43 2015 Antoine Baché
*/

#include "my.h"

void	show_map(char *file, int *biggest, int width, int j)
{
  int	k;
  int	tmp;
  int	tmp_less;
  int	biggest_mult;

  tmp = biggest[1] - (width * (biggest[0] - 1)) - ((biggest[0] - 1) << 1);
  tmp_less = biggest[0] - width - 1;
  biggest_mult = biggest[0] * biggest[0] + biggest[0];
  k = 0;
  while (*file++ != '\n');
  while (k++ < biggest_mult)
    if (++j < biggest[0])
      file[tmp++] = 'x';
    else
      {
	tmp -= tmp_less;
	j = -1;
      }
  write(1, file, my_strlen(file));
}

int	exit_main(int fd, char *file, int *biggest, char *buff)
{
  close(fd);
  free(biggest);
  free(file);
  free(buff);
  return (1);
}

int	free_main(int *biggest, char *file, char *buff)
{
  free(biggest);
  free(file);
  free(buff);
  return (0);
}

int	wrong_nb_arg()
{
  my_putstr_err("usage : ./bsq file\n");
  return (1);
}

int	main(int ac, char **av)
{
  int	fd;
  int	i[3];
  int	*biggest;
  char	*buff;
  char	*file;

  biggest = NULL;
  if (ac != 2)
    return (wrong_nb_arg());
  else if ((fd = open(av[1], O_RDONLY)) == -1)
    return (1);
  if ((buff = malloc(BUFF_SIZE)) == NULL)
    return (0);
  if ((file = parse_file(fd, i, buff)) == NULL)
    return (1);
  if ((biggest = prepare_tab(file, i[0] - i[1], biggest, i[2])) == NULL)
    return (exit_main(fd, file, biggest, buff));
  if (file[0] > 0)
    show_map(file, biggest, i[0] - i[1], -1);
  else
    write(1, file, my_strlen(file));
  if (close(fd) == -1)
    return (1);
  return (free_main(biggest, file, buff));
}
