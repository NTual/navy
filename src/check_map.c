/*
** check_map.c for  in /home/hugo.tallineau/PSU_2016_navy/src
**
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
**
** Started on  Mon Jan 30 17:55:14 2017 Hugo Tallineau
** Last update Sat Feb  4 18:00:20 2017 Hugo Tallineau
*/

#include "navy.h"

int	check_size(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    i++;
  if (i != 4)
    return (1);
  else
    return (0);
}

char	**check_boat(char **map)
{
  int	x;

  x = map[0][0] + map[1][0] + map[2][0] + map[3][0] - (48 * 4);
  if (x != 14)
    {
      map[0] = NULL;
      return (map);
    }
  else
    map = my_sort_array(map);
  return (map);
}

int	check_len(char *str, int len)
{
  if ((str[2] == (str[5] - len + 1)) && str[3] == str[6])
    return (0);
  else if (str[2] == str[5] && (str[3] == (str[6] - len + 1)))
    return (0);
  else
    return (1);
}

int	check_correct(char **map)
{
  int	x;
  int	y;

  x = y = 0;
  while (map[x] != NULL)
    {
      while (map[x][y] != '\0')
	y++;
      if (y != 7)
	return (1);
      else if (map[x][y - 1] < '1' || map[x][y - 1] > '8')
	return (1);
      else if (map[x][y - 2] < 'A' || map[x][y - 2] > 'H')
	return (1);
      else if (map[x][y - 4] < '1' || map[x][y - 4] > '8')
	return (1);
      else if (map[x][y - 5] < 'A' || map[x][y - 5] > 'H')
	return (1);
      else if (check_len(map[x], x + 2) != 0)
	return (1);
      y = 0;
      x++;
    }
  return (0);
}

char	**check_map(char **map)
{
  int	x;

  x = 0;
  while (map[x] != NULL)
    {
      my_strcapitalize(map[x]);
      x++;
    }
  if (check_size(map) != 0)
    map[0] = NULL;
  if (map[0] != NULL)
    map = check_boat(map);
  if (map[0] != NULL)
    map = check_position(map);
  if (map[0] != NULL)
    map = check_order(map);
  if (map[0] != NULL && check_correct(map) != 0)
    map[0] = NULL;
  if (map[0] != NULL)
    map = check_cross(map);
  return (map);
}
