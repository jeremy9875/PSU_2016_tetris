/*
** tetris.c for tetris in /home/arnaud.d/PSU_2016_tetris
** 
** Made by Arnaud DEMANGE
** Login   <arnaud.d@epitech.net>
** 
** Started on  Sat Mar 18 17:33:21 2017 Arnaud DEMANGE
** Last update Wed Mar 22 10:24:25 2017 jeremy elkaim
*/
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "includes/tetris.h"

void	droptetrim(char *buffer, int p, int ch)
{
  if (ch == KEY_DOWN)
    {
      if (buffer[p - 1] == ' ')
        {
          buffer[p] = ' ';
          buffer[p - 1] = ' ';
        }
      else
        my_putstr("Error");
    }
}

void	rotatetrimino(char *buffer, int p, int ch)
{
  if (ch == KEY_UP)
    {
      if (buffer[p - 1] == ' ')
        {
          buffer[p] = ' ';
          buffer[p - 1] = ' ';
        }
      else
        my_putstr("Error");
    }
}

int	menu()
{
  int	ch;
  int	i;
  int	b;
  int	place;

  i = 1;
  b = 0;
  initscr();
  keypad(stdscr, TRUE);
  while (i == 1)
    {
      if (b == 0)
	{
	  clear();
	  printmenu();
	  refresh();
	  b = 1;
	}
      ch = getch();
      beep();
      flash();
      i = mvmenu(ch, place, i);
    }
  return (0);
}

int	window(char *buffer)
{
  int   ch;
  int   lines;
  int   chars;
  char  temp[10001];

  my_strcpy(temp, buffer);
  chars = countchar(buffer);
  lines = countline(buffer);
  initscr();
  keypad(stdscr, TRUE);
  while (1)
    {
      clear();
      toosmall(buffer, chars, lines);
      mvprintw(LINES - 1,COLS - 16, "Press Q to quit");
      ch = getch();
      tetrp(temp, ch);
      refresh();
      mvdirectory(buffer, ch, lines);
      refresh();
    }
  endwin();
  return (0);
}

int	get_game(char **av)
{
  int	fd;
  char	*buffer;

  buffer = malloc(sizeof(char) * 400);
  fd = open("map", O_RDONLY);
  read(fd, buffer, 401);
  if (fd == -1)
    {
      my_putstr("Error opening file\n");
    }
  menu();
  window(buffer);
  free(buffer);
  close(fd);
  return (0);
}
