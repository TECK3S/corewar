/*
** ins_live.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Dec 19 09:30:42 2010 adrien barrau
** Last update Sun Dec 19 14:43:07 2010 adrien barrau
*/

#include "commons.h"
#include "dasm.h"
#include "op.h"

void	ins_live(t_file *file, int *i)
{
  my_fprintf(file->fd, "\t%s ", INS_LIVE);
  *i += 1;
  write_param(file, i, DIR_SIZE, DIR_SIZE);
  my_fprintf(file->fd, "\n");
  *i += DIR_SIZE;
}
