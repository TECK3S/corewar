/*
** ins_gtmd.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/dasm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Dec 19 10:17:50 2010 adrien barrau
** Last update Sun Dec 19 14:34:25 2010 adrien barrau
*/

#include "commons.h"
#include "dasm.h"
#include "op.h"

void	ins_gtmd(t_file *file, int *i)
{
  my_fprintf(file->fd, "\t%s ", INS_GTMD);
  *i += 2;
  write_param(file, i, T_REG, T_REG);
  my_fprintf(file->fd, "\n");
  *i += T_REG;
}
