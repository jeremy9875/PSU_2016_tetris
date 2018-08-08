/*
** get_next_line.h for get_next_line in /home/arnaud.d/CPE_2016_getnextline
** 
** Made by Arnaud DEMANGE
** Login   <arnaud.d@epitech.net>
** 
** Started on  Tue Jan 10 17:52:07 2017 Arnaud DEMANGE
** Last update Sat Mar 18 17:36:04 2017 Arnaud DEMANGE
*/
#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
# define READ_SIZE 1
#endif /* !READ_SIZE */

# define SIZE_BUFF READ_SIZE + 1

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
