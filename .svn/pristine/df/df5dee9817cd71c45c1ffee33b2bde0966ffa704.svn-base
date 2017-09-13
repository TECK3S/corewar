/*
** ins_lfork.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/dasm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Dec 19 10:17:24 2010 adrien barrau
** Last update Sun Dec 19 15:10:01 2010 adrien barrau
*/

#include "commons.h"
#include "dasm.h"
#include "op.h"

void	ins_lfork(t_file *file, int *i)
{
  my_fprintf(file->fd, "\t%s ", INS_LFORK);
  *i += 1;
  write_param(file, i, IND_SIZE, DIR_SIZE);
  my_fprintf(file->fd, "\n");
  *i += IND_SIZE;
}
