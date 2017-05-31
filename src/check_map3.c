/*
** check_map3.c for  in /home/hugo.tallineau/PSU_2016_navy/src
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Wed Feb  1 21:58:49 2017 Hugo Tallineau
** Last update Thu Feb  2 14:32:02 2017 Hugo Tallineau
*/

#include "navy.h"

char	**check_order(char **map)
{
  int	x;
  char	tamp;

  x = 0;
  while (map[x] != NULL)
    {
      if (map[x][2] > map[x][5])
	{
	  tamp = map[x][2];
	  map[x][2] = map[x][5];
	  map[x][5] = tamp;
	}
      if (map[x][3] > map[x][6])
	{
	  tamp = map[x][3];
	  map[x][3] = map[x][6];
	  map[x][6] = tamp;
	}
      x++;
    }
  return (map);
}
