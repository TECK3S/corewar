/*
** check_dump.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 11 15:50:03 2010 adrien barrau
** Last update Sat Dec 11 16:09:13 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

int	check_dump(t_param_vm *param_vm, unsigned char *big_male, int cycle)
{
  int	dumped;

  dumped = 0;
  if (param_vm->dump > 0 && cycle == param_vm->dump)
    {
      dump_memory(big_male);
      dumped = 1;
    }
  return (dumped);
}
