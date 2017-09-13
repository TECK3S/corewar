/*
** ins_sti.c for coreware in /home/benlou_d//proj/coreware/corewar_2013s/trunk/vm
** 
** Made by damien benloukil
** Login   <benlou_d@epitech.net>
** 
** Started on  Sun Dec 19 17:53:16 2010 damien benloukil
** Last update Sun Dec 19 17:53:18 2010 damien benloukil
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

void	do_sti(t_champion *champ,
	       t_param_vm *param_vm,
	       unsigned char **big_male,
	       unsigned char *tab_oct)
{
  int	idx[5];

  idx[4] = (*big_male)[TO_ABS((champ->pc + 2) % MEM_SIZE)];
  idx[0] = get_parameter(tab_oct, 2);
  idx[1] = get_octets_ldi(champ, big_male, idx[0], 1);
  idx[2] = get_parameter(tab_oct, 3);
  idx[3] = get_octets_ldi(champ, big_male, idx[2], OP_LEFT_SIZE + 1);
  idx[1] = (idx[1] + idx[3]) % MEM_SIZE;
  if (idx[1] < 0 && champ->pc + idx[1] < 0)
    idx[1] = MEM_SIZE + (champ->pc + idx[1]);
  if (idx[4] >= 1 && idx[4] <= REG_NUMBER)
    {
      if (param_vm->ctmo == -1 || addr_is_inside(champ, (champ->pc + idx[1])))
	{
	  champ->address_instruction = (champ->pc + idx[1]);
	  idx[4] = (champ->registers)[idx[4] - 1];
	  write_octets(big_male, idx[4], (champ->pc + idx[1]), REG_SIZE - 1);
	  if (param_vm->is_verbose)
	    my_printf(V_INS_STI_MSG, champ->number, idx[4], (champ->pc + idx[1]));
	}
      champ->pc = (champ->pc + 3 + OP_LEFT_SIZE + OP_RIGHT_SIZE) % MEM_SIZE;
    }
  else
    champ->pc = (champ->pc + 1) % MEM_SIZE;
}

void	ins_sti(t_champion *champ,
		t_param_vm *param_vm,
		unsigned char **big_male,
		t_lives *lives)
{
  unsigned char	*tab_oct;

  lives = lives;
  tab_oct = check_oct_param(champ->instruction.code,
	       (*big_male)[TO_ABS((champ->pc + 1) % MEM_SIZE)]);
  if (tab_oct)
    do_sti(champ, param_vm, big_male, tab_oct);
  else
    champ->pc = (champ->pc + 1) % MEM_SIZE;
  free(tab_oct);
}
