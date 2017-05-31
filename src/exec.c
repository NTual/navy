/*
** exec.c for  in /home/hugo.tallineau/PSU_2016_navy/src
**
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
**
** Started on  Tue Jan 31 02:11:20 2017 Hugo Tallineau
** Last update Thu Feb  9 17:16:52 2017 Hugo Tallineau
*/

#include "navy.h"

void	set_global(char **foe_map, int x, int y)
{
  if (g_global[0] == 1)
    {
      try_attack(foe_map, x, y, 0);
      g_global[0] = 0;
    }

  else if (g_global[1] == 1)
    {
      try_attack(foe_map, x, y, 1);
      g_global[1] = 0;
    }
}

int	exec_j1(int pid, char **map)
{
  char	**foe_map;
  int	x;
  int	y;
  int	ret;

  x = y = ret = 0;
  foe_map = set_map();
  while ((ret = check_win(map, foe_map, 0)) == 42)
    {
      get_order(&x, &y, pid, foe_map);
      if ((ret = check_win(map, foe_map, 1)) == 42)
	receive(pid, map);
    }
  return (ret);
}

int	exec_j2(int pid, char **map)
{
  char	**foe_map;
  int	x;
  int	y;
  int	ret;

  x = y = ret = 0;
  foe_map = set_map();
  while ((ret = check_win(map, foe_map, 0)) == 42)
    {
      receive(pid, map);
      if ((ret = check_win(map, foe_map, 1)) == 42)
	get_order(&x, &y, pid, foe_map);
    }
  return (ret);
}
