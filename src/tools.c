/*
** tools.c for  in /home/hugo.tallineau/PSU_2016_navy
**
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
**
** Started on  Mon Jan 30 17:45:45 2017 Hugo Tallineau
** Last update Thu Feb  9 15:19:51 2017 Hugo Tallineau
*/

#include "navy.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    my_putchar(str[i++]);
}

char	*my_xmalloc(int x)
{
  char	*str;
  int	i;

  i = 0;
  if ((str = malloc(sizeof(char) * (x + 1))) == NULL)
    exit(84);
  while (i < x + 1)
    str[i++] = '\0';
  return (str);
}

void	my_xfree(char *str)
{
  if (str != NULL)
    free(str);
}

void     my_putnbr(int nb)
{
  int	mod;
  int	stock;
  int	nb2;
  long	nblong;

  nblong = nb;
  nb2 = nblong / 10;
  mod = 1;
  while (nb2 != 0)
    {
      nb2 = nb2 / 10;
      mod = mod * 10;
    }
  if (nblong < 0)
    my_putchar('-');
  if (nblong < 0)
    nblong = nblong * -1;
  while (mod >= 1)
    {
      stock = nblong % mod;
      nblong = nblong / mod;
      my_putchar(nblong + 48);
      nblong = stock;
      mod = mod / 10;
    }
}
