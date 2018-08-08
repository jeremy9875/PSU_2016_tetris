/*
** utils.c for utils in /home/arnaud.d/PSU_2016_tetris
** 
** Made by Arnaud DEMANGE
** Login   <arnaud.d@epitech.net>
** 
** Started on  Fri Mar 17 13:30:39 2017 Arnaud DEMANGE
** Last update Sun Mar 19 21:13:29 2017 Arnaud DEMANGE
*/
#include <unistd.h>
#include "includes/tetris.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
}

void	my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar('0' + (nb % 10));
}
