/*
** ins_zjmp.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/dasm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Dec 19 10:15:55 2010 adrien barrau
** Last update Sun Dec 19 14:52:03 2010 adrien barrau
*/

#include "commons.h"
#include "dasm.h"
#include "op.h"

void	ins_zjmp(t_file *file, int *i)
{
  my_fprintf(file->fd, "\t%s ", INS_ZJMP);
  *i += 1;
  write_param(file, i, IND_SIZE, DIR_SIZE);
  my_fprintf(file->fd, "\n");
  *i += IND_SIZE;
}
