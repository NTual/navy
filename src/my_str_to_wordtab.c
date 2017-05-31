/*
** my_str_to_wordtab.c for  in /home/hugo.tallineau/wolf3d/src
**
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
**
** Started on  Tue Dec 27 18:56:16 2016 Hugo Tallineau
** Last update Sat Feb  4 17:32:16 2017 Hugo Tallineau
*/

#include "navy.h"

int	how_many_lines(char *str)
{
  int	i;
  int	nbr;

  i = nbr = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] != '\n')
	nbr++;
      i++;
    }
  return (nbr + 1);
}

int	get_current_col(char *str, int x)
{
  int	i;
  int	nbr;
  int	loop;

  i = nbr = loop = 0;
  while (str[i] != '\0' && loop <= x)
    {
      if (str[i] == ' ')
	loop++;
      i++;
    }
  i = i - 2;
  while (i > 0 && str[i] != ' ')
    {
      i--;
      nbr++;
    }
  return (nbr + 1);
}

char	**my_str_to_wordtab(char *str)
{
  char	**map;
  int	i;
  int	x;
  int	y;

  i = x = y = 0;
  if ((map = malloc(sizeof(char *) * (how_many_lines(str) + 1))) == NULL)
    return (map);
  map[x] = my_xmalloc(get_current_col(str, x));
  while (str[i] != '\0' && map[0] != NULL)
    {
      while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
	map[x][y++] = str[i++];
      map[x][y] = '\0';
      if (str[i] != '\0')
	i++;
      y = 0;
      x++;
      if ((map[x] = my_xmalloc(get_current_col(str, x) + 1)) == NULL)
	map[0] = NULL;
    }
  map[x] = NULL;
  return (map);
}
