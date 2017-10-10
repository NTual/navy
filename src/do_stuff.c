/*
** do_stuff.c for  in /home/hugo.tallineau/PSU_2016_navy/src
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Thu Feb  9 17:13:22 2017 Hugo Tallineau
** Last update Mon Feb 13 21:51:46 2017 Hugo Tallineau
*/

#include "navy.h"

int     do_stuff_j1(char **av)
{
  char	**map;

  disp_pid();
  if ((map = read_map(av[1])) == NULL)
    return (84);
  map = check_map(map);
  if (map[0] == NULL)
    {
      my_putstr("Invalid boat placement\n");
      return (84);
    }
  return (exec_j1(get_j2_pid(), map));
}

int     do_stuff_j2(char **av)
{
  char	**map;

  kill(my_getnbr(av[1]), SIGUSR1);
  usleep(5000);
  if (g_global[0] == 1)
    {
      g_global[0] = 0;
      disp_pid();
      if ((map = read_map(av[2])) == NULL)
	return (84);
      map = check_map(map);
      if (map[0] == NULL)
	{
	  my_putstr("Invalid boat placement\n");
	  return (84);
	}
      my_putstr("successfully connected\n\n");
      return (exec_j2(my_getnbr(av[1]), map));
    }
    return (84);
}
