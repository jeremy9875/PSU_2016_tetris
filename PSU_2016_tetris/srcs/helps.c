/*
** helps.c for helps in /home/jeremy.elkaim/PSU_2016_tetris
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Fri Mar 17 09:31:59 2017 jeremy elkaim
** Last update Tue Mar 21 16:04:01 2017 jeremy elkaim
*/
#include <stdlib.h>
#include "includes/tetris.h"

void	printmenu()
{
  mvprintw(LINES / 2 - 3, COLS / 2 - 4, "PLAY");
  mvprintw(LINES - 1, COLS - 16, "Press Q to quit");
  mvprintw(LINES / 2, COLS / 2 - 4, "Press space for HELP");
  move(LINES / 2 - 3, COLS / 2 - 5);
}

int	helps()
{
  int	i;
  int	mv;

  i = 1;
  initscr();
  keypad(stdscr, TRUE);
  while (i == 1)
    {
      clear();
      mvprintw(LINES - 1, COLS -16, "Press Q to quit");
      mvprintw(LINES / 2 + 2, COLS / 2 - 5, "PLAY");
      mvprintw(LINES / 2 - 4, COLS / 2 - 10, "Get help type ./tetris --help");
      move(LINES / 2 + 2, COLS / 2 - 6);
      mv = getch();
      if (mv == '\n')
	{
	  i = i + 1;
	}
      quit(mv);
    }
  return (0);
}
