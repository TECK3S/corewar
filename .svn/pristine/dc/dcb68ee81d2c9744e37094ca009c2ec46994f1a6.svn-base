/*
** check_arg_nbr.c for check_arg_nb in /home/bartel_r//Workspace/KoreWar/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Mon Dec  6 13:58:13 2010 remi bartel
** Last update Sun Dec 12 19:00:07 2010 remi bartel
*/

#include "commons.h"
#include "asm.h"

int     check_arg_nb(int found, int exp, int line)
{
  if (found > exp)
    {
      my_fprintf(STDERR, "Error line %d : %s.\n", line, ERR_FW_ARG);
      return (0);
    }
  return (1);
}
