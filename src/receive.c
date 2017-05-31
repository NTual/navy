/*
** receive.c for  in /home/hugo.tallineau/PSU_2016_navy
**
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
**
** Started on  Tue Jan 31 18:44:02 2017 Hugo Tallineau
** Last update Thu Feb  2 15:26:26 2017 Hugo Tallineau
*/

#include "navy.h"

void	receive(int pid, char **map)
{
  int	x;
  int	y;
  int	ret;

  x = y = 0;
  my_putstr("waiting for enemy's attack...\n");
  while (g_global[1] == 0);
  x = g_global[0];
  g_global[0] = 0;
  while (g_global[1] == 1);
  y = g_global[0];
  g_global[0] = 0;
  g_global[1] = 0;
  ret = is_hitten(map, x, y);
  if (ret == 0)
    kill(pid, SIGUSR1);
  else if (ret == 1)
    kill(pid, SIGUSR2);
}
