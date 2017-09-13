/*
** ins_lldi.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 11 03:27:33 2010 adrien barrau

*/

#include "commons.h"
#include "op.h"
#include "vm.h"

static void	modif_carry_and_aff(t_param_vm *param_vm,
				    int res,
				    int reg,
				    t_champion *champ)
{
  champ->registers[reg - 1] = res;
  champ->carry = 0;
  if (res == 0)
    champ->carry = 1;
  if (param_vm->is_verbose)
    my_printf(V_INS_LLDI_MSG, champ->number, res, reg);
}

void	do_lldi(t_champion *champ,
		unsigned char **big_male,
		t_param_vm *param_vm,
		unsigned char *tab_oct)
{
  int		op_left;
  int		op_left_size;
  int		op_right;
  int		op_right_size;
  int		reg;
  int		res;

  op_left_size = get_parameter(tab_oct, 1);
  op_left = get_octets_ldi(champ, big_male, op_left_size, 0);
  op_right_size = get_parameter(tab_oct, 2);
  op_right = get_octets_ldi(champ, big_male, op_right_size,
			    (op_left_size == 4 ? 2 : op_left_size));
  reg = (*big_male)[TO_ABS((champ->pc + 2 + (op_left_size == 4 ? 2
     : op_left_size) + (op_right_size == 4 ? 2 : op_right_size)) % MEM_SIZE)];
  if (reg >= 1 && reg <= REG_NUMBER)
    {
      champ->address_instruction = champ->pc + (op_right + op_left);
      res = get_octets(champ, big_male, REG_SIZE, (op_right + op_left) - 2);
      champ->address_instruction = TO_ABS((champ->pc
			       + op_right + op_left) % MEM_SIZE);
      modif_carry_and_aff(param_vm, res, reg, champ);
      champ->pc = (champ->pc + 3 + op_left_size + op_right_size) % MEM_SIZE;
    }
  else
    champ->pc = (champ->pc + 1) % MEM_SIZE;
}

void	ins_lldi(t_champion *champ,
		t_param_vm *param_vm,
		unsigned char **big_male,
		t_lives *lives)
{
    unsigned char	*tab_oct;

  lives = lives;
  tab_oct = check_oct_param(champ->instruction.code,
	  (*big_male)[TO_ABS((champ->pc + 1) % MEM_SIZE)]);
  if (tab_oct)
    do_lldi(champ, big_male, param_vm, tab_oct);
  else
    champ->pc = (champ->pc + 1) % MEM_SIZE;
  free(tab_oct);
}

