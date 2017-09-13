/*
** write_param.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/dasm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Dec 19 09:49:02 2010 adrien barrau
** Last update Sun Dec 19 17:21:45 2010 adrien barrau
*/

#include	"op.h"
#include        "commons.h"
#include        "dasm.h"

void	write_param(t_file *file, int *i, int size, int type)
{
  int	j;
  int	res;
  char	char_type;

  j = 0;
  res = 0;
  if (type == T_REG)
    char_type = REG_CHAR;
  else if (type == DIR_SIZE)
    char_type = DIRECT_CHAR;
  else
    char_type = 0;
  while (j < size && *i < file->prog_size)
    {
      res <<= NB_BITS_IN_OCT;
      res += (file->output_file)[*i + j];
      j++;
    }
  if (res >= my_power_rec(2, (size * NB_BITS_IN_OCT) - 1))
    res = res - my_power_rec(2, size * NB_BITS_IN_OCT);
  if (char_type)
    my_fprintf(file->fd, "%c", char_type);
  my_fprintf(file->fd, "%i", res);
}
