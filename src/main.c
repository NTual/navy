/*
** main.c for  in /home/flavian/PSU/bootstrap/PSU_2016_navy
**
** Made by Feugueur Flavian
** Login   <flavian.feugueur@epitech.eu>
**
** Started on  Mon Jan 30 16:39:41 2017 Feugueur Flavian
** Last update Thu Feb  9 17:18:49 2017 Hugo Tallineau
*/

#include "navy.h"

void	sig_usr1()
{
  g_global[0] = g_global[0] + 1;
}

void	sig_usr2()
{
  g_global[1] = g_global[1] + 1;
}

void	init()
{
  g_global[0] = g_global[1] = g_global[2] = 0;
  signal(SIGUSR1, sig_usr1);
  signal(SIGUSR2, sig_usr2);
}

int	main(int ac, char **av)
{
  init();
  if (ac == 2 && av[1][0] != '-' && is_num(av[1][0]) == 0)
    return (do_stuff_j1(av));
  else if (ac == 3 && is_num(av[1][0]) == 1)
    return (do_stuff_j2(av));
  else if (ac == 2 && av[1][0] == '-')
    usage();
  return (0);
}
