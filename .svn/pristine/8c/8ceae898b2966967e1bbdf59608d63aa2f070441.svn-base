/*
** check_log.c for check_log in /home/bartel_r//svn/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Thu Dec  9 21:11:47 2010 remi bartel
   Last update Sun Dec 19 23:01:32 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:16:19 2010 remi bartel
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "commons.h"
#include "xfunctions.h"
#include "asm.h"

static int	check_time(struct stat s1, struct stat s2, char *cor_file)
{
  if (s1.st_mtime >= s2.st_mtime)
    return (1);
  else
    {
      my_printf("%s: ", cor_file);
      my_printf("updated\n");
      return (1);
    }
}

int	check_log(char *str, char *cor_file)
{
  struct stat	file_info;
  struct stat	cor_file_info;

  if (access(cor_file, F_OK) == -1)
    return (2);
  if (xstat(str, &file_info) != -1)
    {
      if (xstat(cor_file, &cor_file_info) != -1)
     	return (check_time(file_info, cor_file_info, cor_file));
      else
	return (1);
    }
  else
    return (1);
}
