/*
** xstat.c for xfunctions in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Tue Dec  7 18:21:12 2010 eugene-valentin ngontang-tchiadjie
** Last update Wed Dec  8 12:57:34 2010 eugene-valentin ngontang-tchiadjie
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "commons.h"
#include "asm.h"

int	xstat(const char *path, struct stat *buf)
{
  int	result;

  result = 0;
  if ((result = stat(path, buf)) < 0)
    my_fprintf(STDERR, "%s\n", ERROR_STAT);
  return (result);
}
