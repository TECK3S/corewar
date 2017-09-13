/*
** ins_ld.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 11 03:18:15 2010 adrien barrau

*/

#include "commons.h"
#include "op.h"
#include "vm.h"

static void	modif_carry_and_aff(t_champion *champ,
				    t_param_vm *param_vm,
				    int reg,
				    int parameter)
{
  champ->carry = 0;
  if (parameter == 0)
    champ->carry = 1;
  if (param_vm->opt_graph)
    champ->address_instruction = parameter;
  if (param_vm->is_verbose)
    my_printf(V_INS_LD_MSG, champ->number, parameter, reg);
  champ->address_instruction = REG_ADD_GRAPH;
}

void	ins_ld(t_champion *champ,
	       t_param_vm *param_vm,
	       unsigned char **big_male,
	       t_lives *lives)
{
  unsigned char	*tab_oct;
  int		parameter_size;
  int		parameter;
  int		reg;

  lives = lives;
  tab_oct = check_oct_param(champ->instruction.code,
			    (*big_male)[TO_ABS((champ->pc + 1) % MEM_SIZE)]);
  if (tab_oct)
    {
      parameter_size = get_parameter(tab_oct, 1);
      parameter = get_octets_mod(champ, big_male, parameter_size, 0);
      reg = (*big_male)[TO_ABS((champ->pc + 2 + parameter_size) % MEM_SIZE)];
      if (reg >= 1 && reg <= REG_NUMBER)
	{
	  champ->registers[reg - 1] = parameter;
	  modif_carry_and_aff(champ, param_vm, reg, parameter);
	  champ->pc = (champ->pc + 3 + parameter_size) % MEM_SIZE;
	}
      else
	champ->pc = (champ->pc + 1) % MEM_SIZE;
    }
  else
    champ->pc = (champ->pc + 1) % MEM_SIZE;
  free(tab_oct);
}
