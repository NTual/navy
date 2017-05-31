/*
** my_sort_array.c for  in /home/hugo.tallineau/PSU_2016_navy
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Wed Feb  1 22:45:50 2017 Hugo Tallineau
** Last update Sat Feb  4 17:17:51 2017 Hugo Tallineau
*/

#include "navy.h"

int	is_sorted(char **map)
{
  if (map[0][0] == '2' && map[1][0] == '3' && map[2][0] == '4'
      && map[3][0] == '5')
    return (0);
  else
    return (1);
}

char	*my_strcpy(char *str)
{
  char	*s;
  int	i;

  i = 0;
  if ((s = my_xmalloc(my_strlen(str))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      s[i] = str[i];
      i++;
    }
  s[i] = '\0';
  return (s);
}

int	swap_lines(char **map, int x)
{
  char	*s;

  s = malloc(sizeof(char) * (my_strlen(map[x]) + 1));
  if ((s = my_strcpy(map[x])) == NULL)
    return (1);
  if ((map[x] = my_strcpy(map[x + 1])) == NULL)
    return (1);
  if ((map[x + 1] = my_strcpy(s)) == NULL)
    return (1);
  my_xfree(s);
  return (0);
}

char	**my_sort_array(char **map)
{
  int	x;

  while (is_sorted(map) != 0)
    {
      x = 0;
      while (map[x + 1] != NULL)
	{
	  if (map[x][0] > map[x + 1][0])
	    if ((swap_lines(map, x)) == 1)
	      {
		map[0] = NULL;
		return (map);
	      }
	  x++;
	}
    }
  return (map);
}
