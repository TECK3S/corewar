/*
** ins_unky.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/dasm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Dec 19 10:18:13 2010 adrien barrau
** Last update Sun Dec 19 17:14:34 2010 adrien barrau
*/

#include "commons.h"
#include "dasm.h"
#include "op.h"

static	int	ins_is_unknow(unsigned char ins)
{
  int	ok;

  ok = 1;
  if (ins >= MIN_INSTRUCTION && ins <= MAX_INSTRUCTION)
    ok = 0;
  return (ok);
}

void	ins_unky(t_file *file, int *i)
{
  my_fprintf(file->fd, "\t%s", DOT_CODE);
  while (ins_is_unknow((file->output_file)[*i]) && *i < file->prog_size)
    {
      my_fprintf(file->fd, " %0.2X", (file->output_file)[*i]);
      *i += 1;
    }
  my_fprintf(file->fd, "\n");
}
