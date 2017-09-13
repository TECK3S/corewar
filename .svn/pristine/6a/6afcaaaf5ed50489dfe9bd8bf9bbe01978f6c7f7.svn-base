/*
** xcwrite.c for my_printf in /home/barrau_a//my_printf/xfunctions
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Nov 23 10:57:56 2010 adrien barrau
** Last update Mon Dec  6 17:01:17 2010 adrien barrau
*/

#include <unistd.h>
#include <stdio.h>
#include "xfunctions.h"
#include "commons.h"

void	xcwrite(char c, int *char_count, int fd)
{
  if ((int) xwrite(fd, &c, 1) == -1)
    my_fprintf(STDERR, XCWRT_ERR_MSG);
  else
    *char_count = *char_count + 1;
}
