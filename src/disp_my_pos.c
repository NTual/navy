/*
** disp_my_pos.c for  in /home/hugo.tallineau/PSU_2016_navy/src
**
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
**
** Started on  Tue Jan 31 02:14:09 2017 Hugo Tallineau
** Last update Thu Feb  9 16:44:36 2017 Hugo Tallineau
*/

#include "navy.h"

void	disp_it(char **map, int x, int y)
{
  if (map[x][y] == '0' && y != 7)
    my_putstr(". ");
  else if (map[x][y] == '0')
    my_putstr(".\n");
  if (map[x][y] != '0' && y != 7)
    {
      if (map[x][y] == 'x' || map[x][y] == 'o')
	my_putchar(map[x][y]);
      else
	my_putnbr(map[x][y] - 48);
      my_putchar(' ');
    }
  else if (map[x][y] != '0')
    {
      if (map[x][y] == 'x' || map[x][y] == 'o')
	my_putchar(map[x][y]);
      else
	my_putnbr(map[x][y] - 48);
      my_putchar('\n');
    }
}

void	disp_my_board(char **map)
{
  int	x;
  int	y;

  x = y = 0;
  my_putstr(" |A B C D E F G H\n-+----------------\n");
  while (x < 8)
    {
      my_putnbr(x + 1);
      my_putchar('|');
      while (map[x][y] != '\0')
	disp_it(map, x, y++);
      y = 0;
      x++;
    }
  my_putstr("\n");
}
