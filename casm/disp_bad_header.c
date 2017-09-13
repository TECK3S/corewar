/*
** disp_bad_header.c for disp_bad_header in /home/bartel_r//Workspace/KoreWar/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Mon Dec  6 14:02:05 2010 remi bartel
** Last update Wed Dec  8 22:29:44 2010 remi bartel
*/

#include "asm.h"
#include "commons.h"

void    disp_bad_header(int line)
{
  my_fprintf(STDERR, "error line %d : %s.\n", line, ERR_HEADER);
}
