/*
** tetris4.c for tetris4 in /home/jeremy.elkaim/PSU_2016_tetris
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Wed Feb 22 14:33:15 2017 jeremy elkaim
** Last update Sun Mar 19 21:39:30 2017 Arnaud DEMANGE
*/
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "includes/tetris.h"

void	toosmall(char *buffer, int chars, int lines)
{
  int	a;
  int	b;

  a = LINES / 2;
  b = COLS / 2 - 8;
  if (COLS < chars || LINES < lines)
    {
      mvprintw(a,b, "window too small");
    }
  else
    mvprintw(0,0, buffer);
}

int	tetrp(char *temp, int ch)
{
  if (ch == ' ')
    {
      flash();
      window(temp);
    }
  return (0);
}

void	helptetris(char **argv)
{
  my_putstr("Usage:\t");
  my_putstr(argv[0]);
  my_putstr(" [options]\n");
  my_putstr("Options:\n");
  my_putstr("  --help\t        Display this help\n");
  my_putstr("  -l --level={num}\tStart Tetris at level num");
  my_putstr(" (def: 1)\n");
  my_putstr("  -kl --key-left={K}\tMove the tetrimino LEFT");
  my_putstr(" using the K key (def: left arrow)\n");
  my_putstr("  -kr --key-right={K}\tMove the tetrimino RIGHT");
  my_putstr(" using the K key (def: right arrow)\n");
  my_putstr("  -kt --key-turn={K}\tTURN the tetrimino clockwise 90d");
  my_putstr(" using the K key (def: top arrow)\n");
  my_putstr("  -kd --key-drop={K}\tDROP the tetrimino using the K key");
  my_putstr(" (def: down arrow)\n");
  my_putstr("  -kq --key-quit={K}\tQUIT the game using the K key");
  my_putstr(" (def: 'q' key)\n");
  my_putstr("  -kp --key-pause={K}\tPAUSE/RESTART the game using");
  my_putstr(" the K key  (def: space bar)\n");
  my_putstr("  --map-size={row,col}\tSet the numbers of rows");
  my_putstr(" and columns of the map (def: 20,10)\n");
  my_putstr("  -w --without-next\tHide next tetrimino (def: false)\n");
  my_putstr("  -d --debug\t\tDebug mode (def: flase)\n");
}
