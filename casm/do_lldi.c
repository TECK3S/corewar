/*
** do_lldi.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Thu Dec 16 19:33:26 2010 eugene-valentin ngontang-tchiadjie
   Last update Sun Dec 19 23:01:01 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:39:00 2010 remi bartel
*/

#include	"asm.h"
#include	"op.h"
#include	"commons.h"

static void	getlldi_octet_code(char **params, unsigned char *octet_code)
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

void	do_lldi(unsigned char **str, int *i,
		char **params, t_param **call_list)
{
  unsigned char	octet_code;
  int		cpt;
  int		pc;

  pc = *i - 1;
  cpt = 0;
  octet_code = 0;
  getlldi_octet_code(params, &octet_code);
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
