/*
** parse_arg.c for parse_arg in /home/arnaud.d/PSU_2016_tetris
** 
** Made by Arnaud DEMANGE
** Login   <arnaud.d@epitech.net>
** 
** Started on  Mon Mar 13 13:23:29 2017 Arnaud DEMANGE
** Last update Sun Mar 19 21:13:08 2017 Arnaud DEMANGE
*/
#include <stdlib.h>
#include "includes/tetris.h"

int	check_long_arg(char **argv)
{
  int	a;

  a = 0;
  while (argv[a] != '\0')
    {
      if (argv[a][0] == '-' && argv[a][1] == 'd' &&
	  argv[a][2] == '\0')
	{
	  open_tetri();
	  press_key_to_play();
	}
      a++;
    }
}

int	continue_parsing(char **argv)
{
  int	a;

  a = 1;
  while (argv[a] != '\0')
    {
      if (argv[a][0] == '-' && argv[a][1] == '-' &&
	  argv[a][2] == 'd' && argv[a][3] == 'e' &&
	  argv[a][4] == 'b' && argv[a][5] == 'u' &&
	  argv[a][6] == 'g' || argv[a][0] == '-' &&
	  argv[a][1] == 'd')
	{
	  open_tetri();
	  press_key_to_play();
	}
      a++;
    }
}

int	parse_arg(int argc, char **argv)
{
  int	i;

  i = 1;
  while (argv[i] != '\0')
    {
      if (argv[i][0] == '-' && argv[i][1] == '-' &&
	  argv[i][2] == 'h' && argv[i][3] == 'e' &&
	  argv[i][4] == 'l' && argv[i][5] == 'p')
	{
	  helptetris(argv);
	  exit (84);
	}
      i++;
    }
  continue_parsing(argv);
}
