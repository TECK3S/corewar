/*
** do_sti.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Tue Dec 14 03:32:52 2010 eugene-valentin ngontang-tchiadjie
** Last update Sat Dec 18 18:52:15 2010 eugene-valentin ngontang-tchiadjie
*/

#include	"asm.h"
#include	"op.h"
#include	"commons.h"

static void	getsti_octet_code(char **params, unsigned char *octet_code)
{
  int	cpt;
  int	found;
  int	j;

  cpt = 0;
  while (cpt < my_tablen(params))
    {
      found = 0;
      j = 0;
      while (inst_code_tab[j].param_char && !found)
	{
	  if (params[cpt][0] == inst_code_tab[j].param_char)
	    found = inst_code_tab[j].inst_code(octet_code, cpt);
	  j++;
	}
      if (found == 0)
	found = add_ind(octet_code, cpt);
      cpt++;
    }
  return ;
}

void	do_sti(unsigned char **str, int *i, char **params, t_param **call_list)
{
  unsigned char	octet_code;
  int		cpt;
  int		pc;

  pc = *i - 1;
  cpt = 0;
  octet_code = 0;
  getsti_octet_code(params, &octet_code);
  *str = do_fill(*str, *i, octet_code);
  *i = *i + 1;
  while (params[cpt])
    {
      if (params[cpt][0] != REG_CHAR)
	{
	  store_addr_call(call_list, pc, params[cpt], IND_SIZE);
	  *str = put_param(*str, i, IND_SIZE, params[cpt]);
	}
      else
	 *str = put_param(*str, i, T_REG, params[cpt]);
      cpt++;
    }
  return ;
}
