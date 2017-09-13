/*
** init_registers.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 18 04:02:16 2010 adrien barrau
** Last update Sat Dec 18 04:02:17 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

void	init_registers(t_champion *champ)
{
  int	i;

  i = 1;
  champ->registers[0] = champ->number;
  while (i < REG_NUMBER)
    champ->registers[i++] = 0;
  champ->pc = champ->load_address;
}
