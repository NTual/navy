/*
** read_map.c for  in /home/hugo.tallineau/PSU_2016_navy/src
**
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
**
** Started on  Mon Jan 30 18:03:21 2017 Hugo Tallineau
** Last update Mon Feb 13 21:48:12 2017 Hugo Tallineau
*/

#include "navy.h"

int     how_many_stuff(char *path)
{
  int   nbr;
  char  *tamp;
  int   fd;

  if ((tamp = my_xmalloc(1)) == NULL)
    return (-1);
  nbr = 0;
  if ((fd = open(path, O_RDONLY)) <= -1)
    return (-1);
  while (read(fd, tamp, 1) != 0)
    nbr++;
  close(fd);
  free(tamp);
  return (nbr);
}

int     my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] != '\0' && str2[i] != '\0')
    {
      if (str1[i] != str2[i])
	return (1);
      i++;
    }
  if (str1[i] != '\0' && str1[i] != ' ')
    return (1);
  if (str2[i] != '\0' && str2[i] != ' ')
    return (1);
  return (0);
}

int	a_kind_of_basic_function(char *str)
{
  if (my_strcmp(str, "/dev/urandom") == 0 || my_strcmp(str, "/dev/random") == 0)
    return (-1);
  else
    return (0);
}

char	**read_map(char *filename)
{
  int	fd;
  int	len;
  char	*buffer;
  char	**map;

  if (a_kind_of_basic_function(filename) == -1)
    return (NULL);
  if ((len = how_many_stuff(filename)) == -1)
    return (NULL);
  if ((buffer = my_xmalloc(len)) == NULL)
    return (NULL);
  if ((fd = open(filename, O_RDONLY)) <= -1)
    return (NULL);
  read(fd, buffer, len);
  buffer[len] = '\0';
  close(fd);
  my_strcapitalize(buffer);
  map = my_str_to_wordtab(buffer);
  my_xfree(buffer);
  return (map);
}
