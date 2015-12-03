/*
** my_put.c for BSQ in /CPE_2015_bsq
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Nov 26 10:19:49 2015 Antoine Baché
** Last update Thu Dec  3 09:33:50 2015 Antoine Baché
*/

#include "my.h"

void	my_putstr_err(char *str)
{
  write(2, str, my_strlen(str));
}
