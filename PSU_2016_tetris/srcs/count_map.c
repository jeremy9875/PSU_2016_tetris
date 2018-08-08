/*
** tetris3.c for tetris3 in /home/jeremy.elkaim/PSU_2016_tetris
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Wed Feb 22 14:28:35 2017 jeremy elkaim
** Last update Sun Mar 19 21:36:03 2017 Arnaud DEMANGE
*/
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "includes/tetris.h"

void	mvdirectory(char *buffer, int ch, int line)
{
  mvleft(buffer, ch);
  mvright(buffer, ch);
  quit(ch);
}

int	countline(char *buffer)
{
  int	i;
  int	u;

  i = 0;
  u = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	{
	  u = u + 1;
	}
      i = i + 1;
    }
  u = u + 1;
  return (u);
}

int	countchar(char *buffer)
{
  int	i;

  i = 0;
  while (buffer[i] != '\n')
    {
      i = i + 1;
    }
  return (i);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
