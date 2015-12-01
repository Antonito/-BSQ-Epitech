/*
** my_realloc.c for BSQ in /CPE_2015_bsq
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Thu Nov 26 13:00:13 2015 Antoine Baché
** Last update Tue Dec  1 01:43:20 2015 Antoine Baché
*/

#include "../include/my.h"

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
  int	i;
  int	j;
  int	lens1;

  if (size[0] == 0)
    size[0] = my_strlen(s1);
  lens1 = size[0];
  size[0] += reader;
  i = 0;
  j = 0;
  if ((s3 = malloc(sizeof(char) * (size[0] + 2))) == NULL)
    return (NULL);
  while (j < lens1)
    s3[i++] = s1[j++];
  j = 0;
  while (j < reader)
    s3[i++] = s2[j++];
  free(s1);
  s3[i] = '\0';
  return (s3);
}
