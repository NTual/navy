/*
** get_order.c for  in /home/hugo.tallineau/PSU_2016_navy/src
**
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
**
** Started on  Tue Jan 31 12:50:15 2017 Hugo Tallineau
** Last update Fri Feb 10 16:36:27 2017 Feugueur Flavian
*/

#include "navy.h"

void	manage_null(int **x, int **y, char *s)
{
  if (s != NULL)
    {
      **x = s[0] - 64;
      **y = s[1] - 48;
    }
  else
    {
      **x = 1;
      **y = 1;
    }
}

void	get_order(int *x, int *y, int pid, char **foe_map)
{
  char	*s;

  my_putstr("attack: ");
  if ((s = get_next_line(0)) == NULL)
    manage_null(&x, &y, s);
  else
    {
      my_strcapitalize(s);
      while (s == NULL || my_check_pos(s) == -1)
	{
	  my_putstr("wrong position\nattack: ");
	  free(s);
	  if ((s = get_next_line(0)) == NULL)
	    break;
	  my_strcapitalize(s);
	}
      manage_null(&x, &y, s);
    }
  my_xfree(s);
  my_send(*x, *y, pid, foe_map);
}
