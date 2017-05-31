/*
** try_attack.c for  in /home/hugo.tallineau/PSU_2016_navy/src
**
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
**
** Started on  Tue Jan 31 12:19:36 2017 Hugo Tallineau
** Last update Thu Feb  9 16:46:57 2017 Hugo Tallineau
*/

#include "navy.h"

int	try_attack(char **foe_map, int y, int x, int hit)
{
  my_putchar(y + 64);
  my_putnbr(x);
  my_putstr(": ");
  if (hit == 1)
    {
      my_putstr("hit\n\n");
      foe_map[x - 1][y - 1] = 'x';
      return (1);
    }
  else
    {
      my_putstr("missed\n\n");
      if (foe_map[x - 1][y - 1] != 'x')
	foe_map[x - 1][y - 1] = 'o';
      return (0);
    }
}
