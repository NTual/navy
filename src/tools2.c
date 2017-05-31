/*
** tools2.c for  in /home/flavian/PSU/PSU_2016_navy
**
** Made by Feugueur Flavian
** Login   <flavian.feugueur@epitech.eu>
**
** Started on  Wed Feb  1 14:28:16 2017 Feugueur Flavian
** Last update Thu Feb 16 12:30:01 2017 Hugo Tallineau
*/

#include "navy.h"

int     my_getnbr(char *str)
{
  int	i;
  int	neg;
  int	res;
  int	bool;

  bool = 0;
  neg = 0;
  res = 0;
  i = 0;
  while (str[i] != '\0' && bool != 1)
    {
      if (str[i] == '-' && (str[i + 1] < 58 || str[i] > 47))
	neg = 1;
      if (str[i] < 58 && str[i] > 47)
	res = res * 10 + (str[i] - 48);
      else if (res != 0)
	bool = 1;
      i++;
    }
  if (neg == 1)
    res = res * (-1);
  return (res);
}

void	my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i] != '\0')
      {
	if (str[i] >= 'a' && str[i] <= 'z')
	  str[i] -= 32;
	i++;
      }
}

int	my_check_pos(char *str)
{
  if (my_strlen(str) != 2)
    return (-1);
  else if (str[0] < 'A' || str[0] > 'H')
    return (-1);
  else if (str[1] <= '0' || str[1] > '8')
    return (-1);
  return (0);
}

size_t	my_strlen(char *str)
{
  size_t	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int     is_num(char c)
{
  if (c >= '1' && c <= '9')
    return (1);
  else
    return (0);
}
