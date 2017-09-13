/*
** get_header.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sun Dec 19 02:56:03 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 03:04:08 2010 eugene-valentin ngontang-tchiadjie
*/

#include	<stdlib.h>
#include	"asm.h"

unsigned char	*get_header(int nbr, int size)
{
  char		*buf;
  unsigned char	*result;

  buf = my_int_to_char(nbr);
  result = my_putaddr(buf, size);
  free(buf);
  return (result);
}
