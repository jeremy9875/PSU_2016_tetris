/*
** get_next_line.c for get_next_line in /home/arnaud.d/CPE_2016_getnextline
** 
** Made by Arnaud DEMANGE
** Login   <arnaud.d@epitech.net>
** 
** Started on  Tue Jan 10 17:27:20 2017 Arnaud DEMANGE
** Last update Sun Mar 19 21:11:50 2017 Arnaud DEMANGE
*/
#include <stdlib.h>
#include <unistd.h>
#include "includes/get_next_line.h"

int	my_strlen(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    {
      a = a + 1;
    }
  return (a);
}

char	*my_strcat(char *dest, char *str)
{
  int	i;
  int	source;

  i = 0;
  source = 0;
  while (dest[i] != '\0')
    i = i + 1;
  while (str[source] != '\0')
    {
      dest[i] = str[source];
      i = i + 1;
      source = source + 1;
    }
  *str = '\0';
  dest[i] = '\0';
  return (dest);
}

char	*my_line_realloc(char *str, int lenght, char *buff)
{
  char	*newdest;

  buff[lenght] = '\0';
  newdest = malloc((my_strlen(str) + lenght + 1 * sizeof(*str)));
  if (newdest == 0)
    return (NULL);
  *newdest = '\0';
  my_strcat(newdest, str);
  *str = '\0';
  free(str);
  return (newdest);
}

int	my_backslash(char *line, char *buff)
{
  int   i;

  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] == '\n')
        {
          line[i] = '\0';
          *buff = '\0';
	  my_strcat(buff, &line[i + 1]);
          return (1);
        }
      i = i + 1;
    }
  return (0);
}

char	*get_next_line(const int fd)
{
  char	*line;
  static char buff[SIZE_BUFF];
  int	lenght;

  lenght = READ_SIZE;
  if (fd == -1)
    return (NULL);
  line = malloc(SIZE_BUFF * sizeof(*line));
  if (line == 0)
    return (NULL);
  *line = '\0';
  my_strcat(line, buff);
  *buff = '\0';
  while (my_backslash(line, buff) != 1 && lenght == READ_SIZE)
    {
      lenght = read(fd, buff, READ_SIZE);
      line = my_line_realloc(line, lenght, buff);
      my_strcat(line, buff);
    }
  if (READ_SIZE < lenght || READ_SIZE > lenght && *line == '\0')
    return (0);
  else
    return (line);
}
