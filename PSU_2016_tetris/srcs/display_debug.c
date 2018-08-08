/*
** display_debug.c for display_debug in /home/arnaud.d/PSU_2016_tetris
** 
** Made by Arnaud DEMANGE
** Login   <arnaud.d@epitech.net>
** 
** Started on  Fri Mar 17 12:54:09 2017 Arnaud DEMANGE
** Last update Sun Mar 19 21:11:41 2017 Arnaud DEMANGE
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "includes/tetris.h"
#include "includes/get_next_line.h"

void		display_deb(int n, int i, char *s)
{
  int	fd;
  struct dirent *pDirent;
  struct dirent **name;

  n = scandir("tetriminos/", &name, 0, alphasort);
  while (i < n)
    {
      chdir("tetriminos/");
      fd = open(name[i]->d_name, O_RDONLY);
      if (check_ext(name[i]->d_name) == 0)
        {
          check_tetri(name[i]->d_name);
          read_info(name[i]->d_name);
          while (s = get_next_line(fd))
            {
              if (*s == '*' || *s == ' ')
                {
                  my_putstr(s);
                  my_putchar('\n');
                  free(s);
                }
            }
        }
      i++;
    }
}

int	open_tetri()
{
  DIR   *pDir;
  int	n;
  int	i;
  char	*s;

  i = 0;
  n = 0;
  s = NULL;
  pDir = opendir("tetriminos/");
  if (opendir("tetriminos/") == NULL)
    return (1);
  count_tetri();
  display_deb(n, i, s);
  closedir(pDir);
}
