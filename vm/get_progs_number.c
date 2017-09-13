/*
** get_progs_number.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Dec 16 12:11:26 2010 adrien barrau
** Last update Sat Dec 18 04:02:03 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

static void	is_valid_num(t_param_vm *param_vm, int *found, int number)
{
  int	i;

  i = 0;
  *found = 0;
  while (i < MAX_CHAMPS && !(*found))
    {
      if (((param_vm->champs)[i]).number == number)
	*found = 1;
      i++;
    }
}

void	get_progs_number(t_param_vm *param_vm)
{
  int	number;
  int	i;
  int	found;

  i = 0;
  while (i < MAX_CHAMPS)
    {
      found = 1;
      if (param_vm->champs[i].path && param_vm->champs[i].number == 0)
	{
	  number = 0;
	  while (number < MAX_CHAMPS && found)
	    {
	      number++;
	      is_valid_num(param_vm, &found, number);
	    }
	  param_vm->champs[i].number = number;
	}
      i++;
    }
}
