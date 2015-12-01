/*
** prepare_tab.c for BSQ in /CPE_2015_bsq/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Mon Nov 30 16:20:09 2015 Antoine Baché
** Last update Tue Dec  1 01:23:34 2015 Antoine Baché
*/

#include "../include/my.h"

int	get_min(int a, int b, int c)
{
  if (a <= b && a <= c)
    return (a + 1);
  else if (b <= a && b <= c)
    return (b + 1);
  else if (c <= a && c <= b)
    return (c + 1);
  return (0);
}

int	check_lowest(int *tab, int width, int i)
{
  int	size_diag;

  ++width;
  size_diag = i - width;
  if (i <= width || tab[i - 1] <= 0 ||
      tab[size_diag] == 0 || tab[size_diag - 1] == 0)
    return (1);
  else
    return (get_min(tab[i - 1], tab[size_diag], tab[size_diag - 1]));
}

int	*update_max(int *max, int i, int tab)
{
  max[0] = tab;
  max[1] = i;
  return (max);
}

int	*exit_prepare_tab(int *tab, int *max)
{
  my_putstr_err("Invalid character\n");
  free(tab);
  if (max != NULL)
    free(max);
  return (NULL);
}

int	*prepare_tab(char *file, int width, int *max, int i)
{
  int	j;
  int	*tab;

  if ((tab = malloc(sizeof(int) * my_strlen(file))) == NULL)
    return (exit_prepare_tab(tab, NULL));
  max = set_max();
  j = 0;
  while (file[i++] != '\n');
  while (file[i] != '\0' && max[0] < width)
    {
      if (file[i] == '.')
	tab[j] = check_lowest(tab, width, j);
      else if (file[i] == 'o')
	tab[j] = 0;
      else if (file[i] == '\n' || file[i] == '\0')
	tab[j] = -1;
      else
	return (exit_prepare_tab(tab, max));
      if (tab[j++] > max[0])
	max = update_max(max, j - 1, tab[j - 1]);
      ++i;
    }
  free(tab);
  return (max);
}
