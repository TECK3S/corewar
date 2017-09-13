/*
** xopen.c<2> for xfunctions in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Tue Dec  7 18:36:43 2010 eugene-valentin ngontang-tchiadjie
** Last update Wed Dec  8 12:56:11 2010 eugene-valentin ngontang-tchiadjie
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "commons.h"
#include "asm.h"

int	xopen(const char *pathname, int flags, mode_t mode)
{
  int	result;

  result = 0;
  if ((result = open(pathname, flags, mode)) < 0)
    my_fprintf(STDERR, "Error: %s\n", ENOEXIST);
  return (result);
}
