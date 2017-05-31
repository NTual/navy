/*
** check_win.c for  in /home/hugo.tallineau/PSU_2016_navy/src
**
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
**
** Started on  Tue Jan 31 13:05:39 2017 Hugo Tallineau
** Last update Thu Feb  9 14:58:22 2017 Hugo Tallineau
*/

#include "navy.h"

int	disp_win(int nbr, int i)
{
  if (nbr >= 14)
    {
      if (i == 0)
	my_putstr("Enemy won\n");
      return (1);
    }
  else
    {
      if (i == 0)
	my_putstr("I won\n");
      return (0);
    }
}

int	check_foe(char **map_foe)
{
  int	x;
  int	y;
  int	nbr_foe;

  x = y = nbr_foe = 0;
  while (map_foe[x] != NULL)
    {
      while (map_foe[x][y] != '\0')
	{
	  if (map_foe[x][y] == 'x')
	    nbr_foe++;
	  y++;
	}
      y = 0;
      x++;
    }
  return (nbr_foe);
}

int	check_win(char **map, char **foe_map, int i)
{
  int	x;
  int	y;
  int	nbr;
  int	nbr_foe;

  x = y = nbr = 0;
  if (i == 0)
    disp_maps(map, foe_map);
  while (map[x] != NULL)
    {
      while (map[x][y] != '\0')
	{
	  if (map[x][y] == 'x')
	    nbr++;
	  y++;
	}
      y = 0;
      x++;
    }
  nbr_foe = check_foe(foe_map);
  if (nbr >= 14 || nbr_foe >= 14)
    return (disp_win(nbr, i));
  else
    return (42);
}
