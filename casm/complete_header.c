/*
** complete_header.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Tue Dec 14 04:40:31 2010 eugene-valentin ngontang-tchiadjie
** Last update Tue Dec 14 19:07:45 2010 eugene-valentin ngontang-tchiadjie
*/

#include "op.h"
#include "asm.h"
#include "commons.h"

t_file	*complete_header(t_file *file, int i)
{
  (file->header)->magic = COREWAR_EXEC_MAGIC;
  (file->header)->prog_size = i;
  return (file);
}
