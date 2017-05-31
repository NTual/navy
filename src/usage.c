/*
** usage.c for  in /home/hugo.tallineau/PSU_2016_navy
**
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
**
** Started on  Mon Jan 30 17:36:55 2017 Hugo Tallineau
** Last update Wed Feb  1 16:01:11 2017 Feugueur Flavian
*/

#include "navy.h"

void	usage()
{
  my_putstr("USAGE\n\t\t");
  my_putstr("./navy [first_player_pid] navy_positions\n\n");
  my_putstr("DESCRIPTION\n\t\t");
  my_putstr("first_player_pid\tonly for the 2nd player.\t");
  my_putstr("pid of the first player.\n\t\t");
  my_putstr("navy_positions\tfile representing the positions of the ships.\n");
}
