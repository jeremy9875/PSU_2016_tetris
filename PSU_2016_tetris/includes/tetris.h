/*
** tetris.h for tetris in /home/jeremy.elkaim/PSU_2016_tetris
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Wed Feb 22 14:24:30 2017 jeremy elkaim
*/
#include <ncurses.h>
 #include <ncurses/curses.h>

#ifndef _TETRIS_H_
# define _TETRIS_H_

typedef struct s_arguments
{
  char		*help;
  char		*debug;
  char		*key_left;
  char		*key_right;
  char		*key_up;
  char		*key_down;
  char		*resize;
  char		*key_quit;
  char		*key_pause;

}		t_arguments;

typedef struct s_coords
{
  int		x;
  int		y;
}	       t_coords;

void	my_putchar(char c);
void	my_putstr(char *str);
void	my_putnbr(int nb);
void	quit(int ch);
int	read_info(char *d_name);
int	count_tetri();
void	display_deb(int n, int i, char *s);
int	check_ext(char *d_name);
int	check_tetri(char *d_name);
int	menu();
int	mvmenu(int ch, int place, int i);
void	mvright(char *buffer, int ch);
void	mvleft(char *buffer, int ch);
void	mvdirectory(char *buffer, int ch, int line);
int	tetrp(char *temp, int ch);
void	printmenu();
int	open_tetri();
int	countp(char *buffer);
int	helps();
int	get_game();
int	parse_arg(int argc, char **argv);
int	press_key_to_play();
int	countline(char *buffer);
int	countchar(char *buffer);
char	*my_strcpy(char *dest, char *src);
void	toosmall(char *buffer, int chars, int lines);
int	counto(char *buffer);
void	helptetris();
int	window(char *buffer);
int	main(int ac, char **av);

#endif /* !MY_H_ */
