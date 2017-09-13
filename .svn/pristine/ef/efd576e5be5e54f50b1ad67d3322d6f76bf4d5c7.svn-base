/*
** ins_ldi.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 11 03:25:32 2010 adrien barrau

*/

#include "commons.h"
#include "op.h"
#include "vm.h"

static void	calc_oct_ldi(t_champion *champ,
			     unsigned char **big_male,
			     int offset,
			     int *res)
{
  int	i;

  i = 0;
  while (i < 2)
    {
      *res <<= NB_BITS_IN_OCT;
      *res += (*big_male)[TO_ABS((champ->pc + 2 + offset + i) % MEM_SIZE)];
      i++;
    }
}

int	get_octets_ldi(t_champion *champ,
		       unsigned char **big_male,
		       int size,
		       int offset)
{
  int	res;
  int	reg;

  res = 0;
  if (size == T_REG)
    {
      reg = (*big_male)[TO_ABS((champ->pc + 2 + offset) % MEM_SIZE)];
      if (reg >= 1 && reg <= REG_NUMBER)
	res = champ->registers[reg - 1];
    }
  else
    {
      calc_oct_ldi(champ, big_male, offset, &res);
      if (res >= my_power_rec(2, (size * NB_BITS_IN_OCT) - 1))
	res = res - my_power_rec(2, size * NB_BITS_IN_OCT);
      if (size == IND_SIZE)
	{
	  if (res < 0 && champ->pc + res < 0)
	    res = MEM_SIZE + (champ->pc + res);
	  res = get_octets(champ, big_male, DIR_SIZE, (res % MEM_SIZE) - 2);
	}
    }
  return (res);
}

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
    my_printf(V_INS_LDI_MSG, champ->number, res, reg);
}
void	do_ldi(t_champion *champ,
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
  res = get_octets_mod(champ, big_male, REG_SIZE, (op_right + op_left) - 2);
  if (reg >= 1 && reg <= REG_NUMBER)
    {
      champ->address_instruction = TO_ABS((op_right
				 + op_left + champ->pc) % MEM_SIZE);
      modif_carry_and_aff(param_vm, res, reg, champ);
      champ->pc = (champ->pc + 3 + (op_left_size == 4 ? 2 : op_left_size)
		   + (op_right_size == 4 ? 2 : op_right_size)) % MEM_SIZE;
    }
  else
    champ->pc = (champ->pc + 1) % MEM_SIZE;
}

void	ins_ldi(t_champion *champ,
		t_param_vm *param_vm,
		unsigned char **big_male,
		t_lives *lives)
{
  unsigned char	*tab_oct;

  lives = lives;
  tab_oct = check_oct_param(champ->instruction.code,
			    (*big_male)[(champ->pc + 1) % MEM_SIZE]);
  if (tab_oct)
    do_ldi(champ, big_male, param_vm, tab_oct);
  else
    champ->pc = (champ->pc + 1) % MEM_SIZE;
  free(tab_oct);
}
