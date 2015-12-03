/*
** bsq.c for BSQ in /CPE_2015_bsq
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Nov 26 10:19:13 2015 Antoine Baché
** Last update Thu Dec  3 09:33:37 2015 Antoine Baché
*/

#include "my.h"

void	show_map(char *file, int *biggest, int width, int j)
{
  int	i;
  int	k;
  int	tmp;
  int	tmp_less;
  int	biggest_mult;

  i = biggest[1] - (width + 1) * (biggest[0] - 1) - (biggest[0] - 1);
  tmp = i;
  tmp_less = biggest[0] - (width + 1);
  biggest_mult = biggest[0] * (biggest[0] + 1);
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

int	exit_main(int fd, char *file, int *biggest)
{
  close(fd);
  free(biggest);
  free(file);
  return (1);
}

int	free_main(int *biggest, char *file)
{
  free(biggest);
  free(file);
  return (0);
}

int	main(int ac, char **av)
{
  int	fd;
  int	i[3];
  int	*biggest;
  char	*file;

  biggest = NULL;
  if (ac != 2)
    {
      my_putstr_err("usage : ./bsq example\\_file\n");
      return (1);
    }
  else if ((fd = open(av[1], O_RDONLY)) == -1)
    return (1);
  if ((file = parse_file(fd, i)) == NULL)
    return (1);
  if ((biggest = prepare_tab(file, i[0] - i[1], biggest, i[2])) == NULL)
    return (exit_main(fd, file, biggest));
  if (file[0] > 0)
    show_map(file, biggest, i[0] - i[1], -1);
  else
    write(1, file, my_strlen(file));
  if (close(fd) == -1)
    return (1);
  return (free_main(biggest, file));
}
