/*
** ins_or.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 11 03:21:05 2010 adrien barrau
** Last update Sat Dec 18 18:32:21 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

void	do_or(t_champion *champ,
	      unsigned char **big_male,
	      t_param_vm *param_vm,
	      unsigned char *tab_oct)
{
  int		op_left;
  int		op_left_size;
  int		op_right;
  int		op_right_size;
  int		reg;

  op_left_size = get_parameter(tab_oct, 1);
  op_left = get_octets(champ, big_male, op_left_size, 0);
  op_right_size = get_parameter(tab_oct, 2);
  op_right = get_octets(champ, big_male, op_right_size, op_left_size);
  reg = (*big_male)[TO_ABS((champ->pc + 2
     + op_left_size + op_right_size) % MEM_SIZE)];
  if (reg >= 1 && reg <= REG_NUMBER)
    {
      champ->registers[reg - 1] = op_right | op_left;
      champ->carry = 0;
      if ((op_right | op_left) == 0)
	champ->carry = 1;
      if (param_vm->is_verbose)
	my_printf(V_INS_OR_MSG, champ->number, op_left, op_right, reg);
      champ->pc = (champ->pc + 3 + op_left_size + op_right_size) % MEM_SIZE;
    }
  else
    champ->pc = (champ->pc + 1) % MEM_SIZE;
}

void	ins_or(t_champion *champ,
	       t_param_vm *param_vm,
	       unsigned char **big_male,
	       t_lives *lives)
{
  unsigned char	*tab_oct;

  lives = lives;
  tab_oct = check_oct_param(champ->instruction.code,
	      (*big_male)[TO_ABS((champ->pc + 1) % MEM_SIZE)]);
  if (tab_oct)
    do_or(champ, big_male, param_vm, tab_oct);
  else
    champ->pc = (champ->pc + 1) % MEM_SIZE;
  free(tab_oct);
}
