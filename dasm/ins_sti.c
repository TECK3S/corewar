/*
** ins_sti.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/dasm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Dec 19 10:16:23 2010 adrien barrau
** Last update Sun Dec 19 17:26:37 2010 adrien barrau
*/

#include "commons.h"
#include "dasm.h"
#include "op.h"

void	ins_sti(t_file *file, int *i)
{
  unsigned char	*tab_oct;
  int		size;

  my_fprintf(file->fd, "\t%s ", INS_STI);
  if (*i + 1 < file->prog_size)
    {
      tab_oct = check_oct_param((file->output_file)[*i],
				(file->output_file)[*i + 1]);
      *i += 2;
      size = get_parameter(tab_oct, 1);
      write_param(file, i, size, size);
      *i = *i + size;
      my_fprintf(file->fd, "%c ", SEPARATOR_CHAR);
      size = get_parameter(tab_oct, 2);
      write_param(file, i, REG_OR_IND(size), size);
      *i = *i + REG_OR_IND(size);
      my_fprintf(file->fd, "%c ", SEPARATOR_CHAR);
      size = get_parameter(tab_oct, 3);
      write_param(file, i, REG_OR_IND(size), size);
      *i = *i + REG_OR_IND(size);
      my_fprintf(file->fd, "\n");
      free(tab_oct);
    }
}
