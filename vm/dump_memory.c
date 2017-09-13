/*
** dump_memory.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 18 04:01:14 2010 adrien barrau
** Last update Sat Dec 18 16:05:00 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

int	dump_memory(unsigned char *big_male)
{
  int i;

  i = 0;
  my_printf(MEMORY_DUMPED_MSG);
  while (i < MEM_SIZE)
    {
      if (i % 16 == 0)
	my_printf("%04x : ", i);
      my_printf("%02x", big_male[TO_ABS(i % MEM_SIZE)]);
      if ((i + 1) % 16 == 0)
	my_printf("\n");
      else
	my_printf(" ");
      i++;
    }
  return (1);
}
