/*
** my_xmalloc.c for  in /home/hugo.tallineau/PSU_2016_navy/src
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Sat Feb  4 17:05:38 2017 Hugo Tallineau
** Last update Sat Feb  4 17:08:00 2017 Hugo Tallineau
*/

#include "navy.h"

char	*my_xmalloc(int x)
{
  char	*str;

  if ((str = malloc(sizeof(char) * (x + 1))) == NULL)
    return (NULL);
  str[0] = '\0';
}

void	my_xfree(char *str)
{
  if (str != NULL)
    free(str);
}
