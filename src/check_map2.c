/*
** check_map2.c for  in /home/hugo.tallineau/PSU_2016_navy/src
**
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
**
** Started on  Mon Jan 30 19:30:20 2017 Hugo Tallineau
** Last update Sat Feb  4 17:12:26 2017 Hugo Tallineau
*/

#include "navy.h"

char	**set_map(void)
{
  char	**map;
  int	y;
  int	x;

  y = x = 0;
  if ((map = malloc(sizeof(char*) * 9)) == NULL)
    {
      map[0] = NULL;
      return (map);
    }
  map[8] = NULL;
  while (x < 8)
    {
      if ((map[x] = my_xmalloc(9)) == NULL)
	{
	  map[0] = NULL;
	  return (map);
	}
      map[x][8] = '\0';
      while (y < 8)
	map[x][y++] = '0';
      y = 0;
      x++;
    }
  return (map);
}

char	**fill_boat(char *boat, char **map)
{
  int	x;

  x = 0;
  if (boat[2] != boat[5])
    {
      while (x < boat[0] - 48)
	{
	  if (map[boat[3] - 48 - 1][boat[2] - 64 + x - 1] != '0')
	      map[0] = NULL;
	  map[boat[3] - 48 - 1][boat[2] - 64 + x - 1] = boat[0];
	  x++;
	}
    }
  else if (boat[3] != boat[6])
    {
      while (x < boat[0] - 48)
	{
	  if (map[boat[3] - 48 - 1 + x][boat[2] - 64 - 1] != '0')
	    map[0] = NULL;
	  map[boat[3] - 48 - 1 + x][boat[2] - 64 - 1] = boat[0];
	  x++;
	}
    }
  return (map);
}

char	**check_cross(char **boat)
{
  char	**map;
  int	x;
  int	y;

  x = y = 0;
  map = set_map();
  if (map[0] == NULL)
    return (map);
  while (boat[x] != NULL)
    {
      map = fill_boat(boat[x], map);
      if (map[0] == NULL)
	return (map);
      x++;
    }
  return (map);
}

char	**check_position(char **map)
{
  int	x;
  char	tamp;

  x = 0;
  while (map[x] != NULL)
    {
      if (is_num(map[x][2]) == 1 && is_num(map[x][3]) == 0)
	{
	  tamp = map[x][2];
	  map[x][2] = map[x][3];
	  map[x][3] = tamp;
	}
      else if (is_num(map[x][2]) == is_num(map[x][3]))
	map[0] = NULL;
      if (map[0] != NULL && is_num(map[x][5]) == 1 && is_num(map[x][6]) == 0)
	{
	  tamp = map[x][5];
	  map[x][5] = map[x][6];
	  map[x][6] = tamp;
	}
      else if (is_num(map[x][5]) == is_num(map[x][6]))
	map[0] = NULL;
      x++;
    }
  return (map);
}
