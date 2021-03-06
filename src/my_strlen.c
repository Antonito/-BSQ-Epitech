/*
** my_strlen.c for BSQ in /CPE_2015_bsq
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Nov 26 13:13:01 2015 Antoine Baché
** Last update Thu Dec  3 09:34:13 2015 Antoine Baché
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (*str)
    {
      str++;
      i++;
    }
  return (i);
}
