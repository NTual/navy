/*
** check_hit.c for  in /home/hugo.tallineau/PSU_2016_navy/src
**
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
**
** Started on  Tue Jan 31 11:39:06 2017 Hugo Tallineau
** Last update Fri Feb 10 14:19:41 2017 Feugueur Flavian
*/

#include "navy.h"

int	is_hitten(char **map, int y, int x)
{
  my_putchar(y + 64);
  my_putnbr(x);
  my_putstr(": ");
  if (map[x - 1][y - 1] != '0' && map[x - 1][y - 1] != 'x') {
      my_putstr("hit\n\n");
      map[x - 1][y - 1] = 'x';
      return (1);
    }
  else
    my_putstr("missed\n\n");
  return (0);
}
