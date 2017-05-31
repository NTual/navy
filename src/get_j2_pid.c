/*
** get_j2_pid.c for  in /home/hugo.tallineau/PSU_2016_navy/src
**
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
**
** Started on  Tue Jan 31 15:06:02 2017 Hugo Tallineau
** Last update Thu Feb  9 16:04:57 2017 Hugo Tallineau
*/

#include "navy.h"

void	handle_usr1()
{
  g_global[0] = g_global[0] + 1;
}

void	sig_handler(int signal, siginfo_t *siginfo, void *lol)
{
  g_global[2] = siginfo->si_pid;
  kill(g_global[2], SIGUSR1);
  signal++;
  lol = lol;
}

pid_t	get_j2_pid(void)
{
  struct sigaction act;

  my_putstr("waiting for enemy connexion...\n");
  act.sa_sigaction = &sig_handler;
  act.sa_flags = SA_SIGINFO;
  sigemptyset(&act.sa_mask);
  sigaction(SIGUSR1, &act, NULL);
  while (g_global[2] == 0);
  my_putstr("enemy connected\n\n");
  act.sa_sigaction = &handle_usr1;
  sigaction(SIGUSR1, &act, NULL);
  return (g_global[2]);
}
