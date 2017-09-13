/*
** is_utterly_num.c for is_utterly_num in /home/bartel_r//KoreWar/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Sun Dec 19 20:04:12 2010 remi bartel
** Last update Sun Dec 19 20:27:16 2010 remi bartel
*/

#include "asm.h"
#include "commons.h"

int	is_utterly_num(char *str)
{
  int   ok;

  ok = 1;
  if (*str != '-' && !is_num(*str))
    ok = 0;
  ++str;
  while (ok && *str && *str != ' ' && *str != '\t'
         && *str != COMMENT_CHAR && *str != SEPARATOR_CHAR)
    {
      if ((!is_num(*str)))
	{
	  my_printf("faux ; %s\n", str);
	  ok = 0;
	}
      ++str;
    }
  return (ok);
}
