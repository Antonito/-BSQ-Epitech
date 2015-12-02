/*
** parse.c for BSQ in /CPE_2015_bsq
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Nov 26 10:41:07 2015 Antoine Baché
** Last update Wed Dec  2 00:18:23 2015 Antoine Baché
*/

#include "../include/my.h"

int	*set_max()
{
  int	*max;

  if ((max = malloc(sizeof(int) * 2)) == NULL)
    return (NULL);
  max[0] = 0;
  max[1] = 0;
  return (max);
}

char	*parse_file(int fd, int *i)
{
  int	reader;
  char	*file;
  char	buff[BUFF_SIZE];
  int	*size;

  file = NULL;
  size = NULL;
  size = prepare_my_size(size);
  i[2] = 0;
  while ((reader = read(fd, buff, BUFF_SIZE - 1)) > 0)
    {
      i[0] = 0;
      file = my_realloc(file, buff, reader, size);
      while (i[0] < reader - 1)
	{
	  while (buff[i[0]++] != '\n' && i[0] < reader - 1 && buff[i[0]] != '\0');
	  if (buff[i[0] - 1] == '\n')
	    {
	      ++i[2];
	      i[1] = i[0];
	    }
	}
    }
  free(size);
  return (file);
}
