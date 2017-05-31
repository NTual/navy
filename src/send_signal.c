/*
** send_signal.c for  in /home/flavian/PSU/PSU_2016_navy
**
** Made by Feugueur Flavian
** Login   <flavian.feugueur@epitech.eu>
**
** Started on  Tue Jan 31 13:39:21 2017 Feugueur Flavian
** Last update Thu Feb  9 15:07:49 2017 Hugo Tallineau
*/

#include "navy.h"

void	my_send(int x, int y, int pid, char **foe_map)
{
  int	i;

  i = 0;
  while (i < x)
    {
      kill(pid, SIGUSR1);
      i++;
      usleep(5000);
    }
  kill(pid, SIGUSR2);
  usleep(5000);
  i = 0;
  while (i < y)
    {
      kill(pid, SIGUSR1);
      i++;
      usleep(5000);
    }
  kill(pid, SIGUSR2);
  usleep(5000);
  while (g_global[0] == 0 && g_global[1] == 0);
  set_global(foe_map, x, y);
}
