/*
** dasm.c for corewar in /home/benich_a//afs/rendu/c/proj/corewar/corewar_2013s/trunk
** 
** Made by mickael benichou
** Login   <benich_a@epitech.net>
** 
** Started on  Sat Dec 18 14:47:14 2010 mickael benichou
** Last update Sun Dec 19 02:23:06 2010 adrien barrau
*/

#include	"commons.h"
#include	"dasm.h"

void		dasm(char *cor_name)
{
  t_file	file;
  int		ok;

  ok = load_cor_file(cor_name, &file);
  if (ok > 0)
    ok = write_source_file(&file);
  if (ok < 0)
    my_fprintf(STDERR, gl_err_msg[(ok * -1)]);
}
