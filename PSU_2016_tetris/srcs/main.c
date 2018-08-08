/*
** main.c for main.c in /home/arnaud.d/PSU_2016_tetris
** 
** Made by Arnaud DEMANGE
** Login   <arnaud.d@epitech.net>
** 
** Started on  Mon Mar 13 13:22:33 2017 Arnaud DEMANGE
** Last update Sun Mar 19 21:12:07 2017 Arnaud DEMANGE
*/
#include "includes/tetris.h"

int	main(int argc, char **argv)
{
  if (argc != 1)
    parse_arg(argc, argv);
  else if (argc == 1)
    get_game();
}
