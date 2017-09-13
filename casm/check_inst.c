/*
** check_inst.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Tue Dec 14 02:04:46 2010 eugene-valentin ngontang-tchiadjie
   Last update Sun Dec 19 23:01:15 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:16:04 2010 remi bartel
*/

#include	"op.h"
#include	"asm.h"
#include	"commons.h"

int	check_inst(t_inst *l_inst, unsigned char **str,
		   int *i, t_param **call_list)
{
  int	cpt;

  cpt = 0;
  while (ireg_tab[cpt].inst_name)
    {
      if (my_strcmp(l_inst->mnemo, ireg_tab[cpt].inst_name) == 0)
	{
	  ireg_tab[cpt].get_param(str, i, l_inst->params, call_list);
	  return (1);
	}
      cpt++;
    }
  return (0);
}
