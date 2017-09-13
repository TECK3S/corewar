/*
** fill_header.c for corewar in /home/benich_a//afs/rendu/c/proj/corewar/corewar_2013s/trunk
** 
** Made by mickael benichou
** Login   <benich_a@epitech.net>
** 
** Started on  Wed Dec  8 02:23:30 2010 mickael benichou
** Last update Mon Dec 13 18:44:25 2010 remi bartel
*/

#include	"asm.h"
#include	"commons.h"
#include	"xfunctions.h"

void	fill_header(t_file *file, int add, char *str)
{
  if (add == 2)
    my_strncpy((file->header)->prog_name, str, my_strlen(str));
  else
    my_strncpy((file->header)->comment, str, my_strlen(str));
}
