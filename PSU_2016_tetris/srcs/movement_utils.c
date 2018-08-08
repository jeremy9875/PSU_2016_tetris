/*
** tetris2.c for tetris2 in /home/jeremy.elkaim/PSU_2016_tetris
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Wed Feb 22 14:18:31 2017 jeremy elkaim
** Last update Mon Mar 20 09:56:23 2017 jeremy elkaim
*/
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "includes/tetris.h"

void	mvleft(char *buffer, int ch)
{
  int	chars;

  if (ch == KEY_LEFT)
    {
      if (buffer[chars - 1] == ' ')
        {
          buffer[chars] = ' ';
          buffer[chars - 1] = ' ';
        }
      else
        my_putstr("Error");
    }
}

void	mvright(char *buffer, int ch)
{
  int	chars;

  if (ch == KEY_RIGHT)
    {
      if (buffer[chars + 1] == ' ')
        {
          buffer[chars] = ' ';
          buffer[chars + 1] = ' ';
        }
      my_putstr("Error");
    }
}

void	quit(int ch)
{
  if (ch == 'q')
    {
      flash();
      endwin();
      exit (0);
    }
  else
    my_putstr("error");
}
