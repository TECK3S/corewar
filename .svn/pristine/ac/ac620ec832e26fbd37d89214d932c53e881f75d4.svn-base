/*
** ins_st.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Dec 19 08:55:26 2010 adrien barrau
** Last update Sun Dec 19 08:55:28 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

static void	do_write_neg(t_param_vm *param_vm,
			     t_champion *champ,
			     unsigned char **big_male,
			     int st_idx[3])
{
  if (param_vm->ctmo == -1 || addr_is_inside(champ,
	   (MEM_SIZE + (champ->pc + (st_idx[1] % IDX_MOD)))))
    {
      champ->address_instruction = (MEM_SIZE
			+ (champ->pc + (st_idx[1] % IDX_MOD)));
      write_octets(big_male, st_idx[0], (MEM_SIZE
	   + (champ->pc + (st_idx[1] % IDX_MOD))), REG_SIZE - 1);
      if (param_vm->is_verbose)
	my_printf(V_INS_ST_IND_MSG, champ->number,
	  st_idx[0], (MEM_SIZE + (champ->pc + (st_idx[1] % IDX_MOD))));
    }
}

static void	do_write_pos(t_param_vm *param_vm,
			     t_champion *champ,
			     unsigned char **big_male,
			     int st_idx[3])
{
  if (param_vm->ctmo == -1 || addr_is_inside(champ,
		      (champ->pc + (st_idx[1] % IDX_MOD))))
    {
      champ->address_instruction = (champ->pc + (st_idx[1] % IDX_MOD));
      write_octets(big_male, st_idx[0], (champ->pc
			    + (st_idx[1] % IDX_MOD)), REG_SIZE - 1);
      if (param_vm->is_verbose)
	my_printf(V_INS_ST_IND_MSG, champ->number,
		  st_idx[0], (champ->pc + (st_idx[1] % IDX_MOD)));
    }
}

static void	do_write_st(t_param_vm *param_vm,
			    t_champion *champ,
			    unsigned char **big_male,
			    int st_idx[3])
{
  if (st_idx[2] == T_REG && st_idx[1] >= 1 && st_idx[1] <= REG_NUMBER)
    {
      champ->registers[st_idx[1] - 1] = st_idx[0];
      champ->address_instruction = REG_ADD_GRAPH;
      if (param_vm->is_verbose)
	my_printf(V_INS_ST_REG_MSG, champ->number, st_idx[0], st_idx[1]);
      champ->pc = (champ->pc + 3 + st_idx[2]) % MEM_SIZE;
    }
  else if (st_idx[2] == IND_SIZE)
    {
      if (st_idx[1] < 0 && (champ->pc + (st_idx[1] % IDX_MOD)) < 0)
	do_write_neg(param_vm, champ, big_male, st_idx);
      else
	do_write_pos(param_vm, champ, big_male, st_idx);
      champ->pc = (champ->pc + 3 + st_idx[2]) % MEM_SIZE;
    }
  else
    {
      if (param_vm->is_verbose)
	my_printf(V_INS_ST_ERR_MSG, champ->number);
      champ->pc = (champ->pc + 1) % MEM_SIZE;
    }
}

void	do_st(t_champion *champ,
	      t_param_vm *param_vm,
	      unsigned char **big_male,
	      unsigned char *tab_oct)
{
  int		st_idx[3];

  st_idx[0] = (*big_male)[TO_ABS((champ->pc + 2) % MEM_SIZE)];
  st_idx[2] = get_parameter(tab_oct, 2);
  if (st_idx[2] == T_REG)
    st_idx[1] = (*big_male)[TO_ABS(champ->pc + 2 + st_idx[2])];
  else
    st_idx[1] = get_octets_st(champ, big_male, st_idx[2], 1);
  if (st_idx[0] >= 1 && st_idx[0] <= REG_NUMBER)
    {
      st_idx[0] = champ->registers[st_idx[0] - 1];
      do_write_st(param_vm, champ, big_male, st_idx);
    }
  else
    champ->pc = (champ->pc + 1) % MEM_SIZE;
}

void	ins_st(t_champion *champ,
	       t_param_vm *param_vm,
	       unsigned char **big_male,
	       t_lives *lives)
{
  unsigned char *tab_oct;

  lives = lives;
  tab_oct = check_oct_param(champ->instruction.code,
	   (*big_male)[TO_ABS((champ->pc + 1) % MEM_SIZE)]);
  if (tab_oct)
    do_st(champ, param_vm, big_male, tab_oct);
  else
    champ->pc = (champ->pc + 1) % MEM_SIZE;
  free(tab_oct);
}
