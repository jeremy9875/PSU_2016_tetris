/*
** check_open.c for check_open in /home/arnaud.d/PSU_2016_tetris
** 
** Made by Arnaud DEMANGE
** Login   <arnaud.d@epitech.net>
** 
** Started on  Sat Mar 18 17:33:09 2017 Arnaud DEMANGE
** Last update Sun Mar 19 21:35:46 2017 Arnaud DEMANGE
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include "includes/get_next_line.h"
#include "includes/tetris.h"

int	press_key_to_play(char **av)
{
  char	*s;

  my_putstr("Press any key to start Tetris");
  s = get_next_line(0);
  free(s);
  chdir("..");
  get_game();
}

int	read_info(char *d_name)
{
  char	*s;
  int	fd;

  fd = open(d_name, O_RDONLY);
  s = malloc(sizeof(char) * 200);
  read(fd, s, 30);
  if (d_name[0] == '.')
    return (1);
  if (s[0] <= 57 && s[0] >= 48 && s[4] <= 57 && s[4] >= 48)
    {
      my_putstr(" : Size ");
      my_putchar(s[0]);
    }
  if (s[2] <= 57 && s[2] >= 48 && s[4] <= 57 && s[4] >= 48)
    {
      my_putchar('*');
      my_putchar(s[2]);
      my_putstr(" : Color ");
      my_putchar(s[4]);
      my_putstr(" :");
    }
  else
    my_putstr(" : Error");
  free(s);
  my_putchar('\n');
}

int	check_ext(char *d_name)
{
  int	a;

  a = 0;
  while (d_name[a])
    {
      a = a + 1;
    }
  if (d_name[a - 1] != 'o' && d_name[a - 2] != 'n')
    return (1);
  else
    return (0);
}

int	check_tetri(char *d_name)
{
  int	i;
  int	a;

  a = 0;
  i = 0;
  if (d_name[0] == '.')
    return (1);
  else
    {
      my_putstr("Tetriminos : Name ");
      while (d_name[i] != '\0' && d_name[i] != '.')
	{
	  my_putchar(d_name[i]);
	  i++;
	}
    }
}

int		count_tetri()
{
  int	i;
  struct dirent *pDirent;
  DIR   *pDir;
  char  *s;

  i = 0;
  pDir = opendir("tetriminos/");
  if (opendir("tetriminos/") == NULL)
    return (1);
  while ((pDirent = readdir(pDir)) != '\0')
    {
      if (check_ext(pDirent->d_name) == 0)
	i = i + 1;
    }
  my_putstr("Tetriminos : ");
  my_putnbr(i);
  my_putchar('\n');
}
