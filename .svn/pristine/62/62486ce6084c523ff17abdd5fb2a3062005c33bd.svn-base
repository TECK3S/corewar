/*
** ins_fork.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/dasm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Dec 19 10:16:40 2010 adrien barrau
** Last update Sun Dec 19 15:05:18 2010 adrien barrau
*/

#include "commons.h"
#include "dasm.h"
#include "op.h"

void	ins_fork(t_file *file, int *i)
{
  my_fprintf(file->fd, "\t%s ", INS_FORK);
  *i += 1;
  write_param(file, i, IND_SIZE, DIR_SIZE);
  my_fprintf(file->fd, "\n");
  *i += IND_SIZE;
}
