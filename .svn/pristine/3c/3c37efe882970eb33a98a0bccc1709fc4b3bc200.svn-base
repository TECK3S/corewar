/*
** check_too_close_address.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Dec 16 12:38:28 2010 adrien barrau
** Last update Sat Dec 18 04:00:09 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

static int	calc_pg_la(t_param_vm *param_vm,
			   int current_champ,
			   int i,
			   int *pg_I1)
{
  int	la_I2;

  la_I2 = 0;
  if (param_vm->champs[current_champ].load_address
      < param_vm->champs[i].load_address)
    {
      *pg_I1 = param_vm->champs[current_champ].load_address
	+ param_vm->champs[current_champ].prog_size;
      la_I2 = param_vm->champs[i].load_address;
      if (la_I2 + param_vm->champs[i].prog_size > MEM_SIZE)
	la_I2 = la_I2 - MEM_SIZE;
    }
  else
    {
      *pg_I1 = param_vm->champs[i].load_address
	+ param_vm->champs[i].prog_size;
      la_I2 = param_vm->champs[current_champ].load_address;
      if (la_I2 + param_vm->champs[current_champ].prog_size > MEM_SIZE)
	la_I2 = la_I2 - MEM_SIZE;
    }
  return (la_I2);
}

int	check_too_close_address(t_param_vm *param_vm, int current_champ)
{
  int	ok;
  int	i;
  int	pg_I1;
  int	la_I2;

  i = 0;
  ok = 1;
  while (ok > 0 && i < current_champ)
    {
      if (param_vm->champs[i].path)
	{
	  la_I2 = calc_pg_la(param_vm, current_champ, i, &pg_I1);
	  if (la_I2 - pg_I1 < 0)
	    ok = OPT_A_TOO_CLOSE_ERR_CODE;
	}
      i++;
    }
  return (ok);
}
