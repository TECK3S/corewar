/*
** tool_inttab.c for coreware in /home/benlou_d//proj/coreware/corewar_2013s/trunk/vm
** 
** Made by damien benloukil
** Login   <benlou_d@epitech.net>
** 
** Started on  Sun Dec  5 16:57:54 2010 damien benloukil
** Last update Wed Dec  8 14:10:55 2010 damien benloukil
*/

#include "commons.h"
#include "op.h"
#include "vm.h"
#include "xfunctions.h"

int	my_tab_intlen(int *res)
{
  int	i;

  i = 0;
  while (res[i] != -1)
      i = i + 1;
  return (i);
}

int	*my_tab_intcpy(int *dest, int *src)
{
  int	i;

  i = 0;
  while (src[i] != -1)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = -1;
  return (dest);
}

int	*my_sorttab_int(int **la)
{
  int	i;
  int	change;
  int	temp;

  temp = 0;
  change = 1;
  i = 0;
  while (change != 0)
    {
      change = 0;
      i = 0;
      while ((*la)[i] != -1 && (*la)[i + 1] != -1)
	{
	  if ((*la)[i] > (*la)[i + 1])
	    {
	      temp = (*la)[i];
	      (*la)[i] = (*la)[i + 1];
	      (*la)[i + 1] = temp;
	      change = 1;
	    }
	  i = i + 1;
	}
    }
  return (*la);
}
