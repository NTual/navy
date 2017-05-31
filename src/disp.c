/*
** disp.c for  in /home/hugo.tallineau/PSU_2016_navy/src
**
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
**
** Started on  Tue Jan 31 11:36:59 2017 Hugo Tallineau
** Last update Wed Feb  1 15:56:58 2017 Feugueur Flavian
*/

#include "navy.h"

void	disp_maps(char **map, char **foe_map)
{
  my_putstr("my positions:\n");
  disp_my_board(map);
  my_putstr("enemy's positions:\n");
  disp_my_board(foe_map);
}

void	disp_pid(void)
{
  my_putstr("my_pid:\t");
  my_putnbr(getpid());
  my_putchar('\n');
}
