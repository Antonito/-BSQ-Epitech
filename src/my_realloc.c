/*
** my_realloc.c for BSQ in /CPE_2015_bsq
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Nov 26 13:00:13 2015 Antoine Baché
** Last update Tue Dec  8 08:45:27 2015 Antoine Baché
*/

#include "my.h"

int	*prepare_my_size(int *size)
{
  if ((size = malloc(sizeof(int))) == NULL)
    return (NULL);
  size[0] = 0;
  return (size);
}

char	*my_realloc(char *s1, char *s2, int reader, int *size)
{
  char	*s3;
  char	*tmp;
  int	j;
  int	lens1;

  if (size[0] == 0)
    size[0] = my_strlen(s1);
  lens1 = size[0];
  size[0] += reader;
  j = 0;
  if ((s3 = malloc(sizeof(char) * (size[0] + 2))) == NULL)
    return (NULL);
  tmp = s3;
  while (j < lens1)
    *s3++ = s1[j++];
  j = 0;
  while (j < reader)
    *s3++ = s2[j++];
  free(s1);
  *s3 = '\0';
  s3 = tmp;
  return (s3);
}
