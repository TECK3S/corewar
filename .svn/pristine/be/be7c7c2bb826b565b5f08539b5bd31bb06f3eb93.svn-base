/*
** parse_option.c for parse_option in /home/benlou_d//proj/coreware/corewar_2013s/trunk/vm
** 
** Made by damien benloukil
** Login   <benlou_d@epitech.net>
** 
** Started on  Tue Nov 30 16:32:00 2010 damien benloukil
** Last update Sat Dec 18 22:08:50 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

int	check_opt_name(char *opt_name)
{
  int	i;
  int	ok;

  ok = 0;
  i = 0;
  while ((gl_tab_opt[i]).name_opt)
    {
      if (my_strcmp((gl_tab_opt[i]).name_opt, opt_name) == 0)
	ok = i + 1;
      i++;
    }
  return (ok);
}

int	is_valid(char *num, t_param_vm  *param_vm)
{
  int	valid_num;
  int	i;

  i = 0;
  valid_num = my_getnbr(num);
  if (valid_num < 1 && valid_num > MAX_CHAMPS)
    valid_num = 0;
  while (valid_num && i < MAX_CHAMPS)
    {
      if (((param_vm->champs)[i]).number == valid_num)
	valid_num = 0;
      i++;
    }
  return (valid_num);
}

int	check_option(t_args_par *args_par,
		     int *i,
		     int *current_champ)
{
  int	ok;

  ok = 1;
  if ((ok = check_opt_name(&((args_par->av)[*i][1]))) > 0)
    ok = ((gl_tab_opt[ok - 1]).check_opt_val)(args_par,
					      current_champ,
					      i);
  else
    ok = OPT_BAD_OPT_ERR_CODE;
  return (ok);
}

void	add_champ(t_param_vm *param_vm, char *path, int *current_champ)
{
  ((param_vm->champs)[*current_champ]).path = path;
  *current_champ = *current_champ + 1;
}

int	parse_option(t_args_par *args_par)
{
  int	i;
  int	ok;
  int	current_champ;

  current_champ = 0;
  ok = 1;
  i = 1;
  if (args_par->ac >= 2)
    {
      while ((args_par->ac) > i && ok > 0)
	{
	  if ((args_par->av)[i][0] == '-')
	    ok = check_option(args_par, &i, &current_champ);
	  else if (current_champ < MAX_CHAMPS)
	    add_champ(args_par->param_vm, (args_par->av)[i], &current_champ);
	  else
	    ok = TOO_MANY_CHAMPS_ERR_CODE;
	  i++;
	}
      if (ok > 0 && args_par->param_vm->champs[0].path == 0)
	ok = HOW_TO_CODE;
    }
  else
    ok = HOW_TO_CODE;
  return (ok);
}
