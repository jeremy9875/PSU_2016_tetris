/*
** tetris5.c for tetris5 in /home/jeremy.elkaim/PSU_2016_tetris
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Wed Mar  1 10:17:33 2017 jeremy elkaim
** Last update Sun Mar 19 21:37:46 2017 Arnaud DEMANGE
*/
#include <stdlib.h>
#include <unistd.h>
#include "includes/tetris.h"

int	mvmenu(int ch, int place, int i)
{
  if (ch == 'q')
    {
      flash();
      quit(ch);
    }
  if (ch == KEY_UP)
    place = move(LINES / 2 - 3, COLS / 2 - 5);
  if (ch == KEY_DOWN)
    place = move(LINES / 2, COLS / 2 - 5);
  if (ch == '\n')
    i = i + 1;
  else if (ch != '\n' && ch != 'q'
	   && ch != KEY_UP && ch != KEY_DOWN)
    {
      helps();
      i = i + 1;
    }
  return (i);
}
