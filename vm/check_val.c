/*
** check_val.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 18 04:00:31 2010 adrien barrau
** Last update Sat Dec 18 04:00:32 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

int	check_comment_val(t_args_par *args_par,
			  int *current_champ,
			  int *i)
{
  int	ok;

  ok = 1;
  args_par = args_par;
  current_champ = current_champ;
  i = i;
  if ((args_par->param_vm)->have_comment == 0)
    (args_par->param_vm)->have_comment = 1;
  else
    ok = OPT_COMMENT_ERR_CODE;
  return (ok);
}

int	check_verbose_val(t_args_par *args_par,
			  int *current_champ,
			  int *i)
{
  int	ok;

  ok = 1;
  args_par = args_par;
  current_champ = current_champ;
  i = i;
  if ((args_par->param_vm)->is_verbose == 0)
    (args_par->param_vm)->is_verbose = 1;
  else
    ok = OPT_V_EXIST_ERR_CODE;
  return (ok);
}

int	check_graph_val(t_args_par *args_par,
			  int *current_champ,
			  int *i)
{
  int	ok;

  ok = 1;
  args_par = args_par;
  current_champ = current_champ;
  i = i;
  if ((args_par->param_vm)->opt_graph == 0)
    (args_par->param_vm)->opt_graph = 1;
  else
    ok = OPT_GRAPH_ERR_CODE;
  return (ok);
}

int	check_dump_val(t_args_par *args_par,
		       int *current_champ,
		       int *i)
{
  int	dump_num;
  int	ok;

  ok = 0;
  dump_num = 0;
  current_champ = current_champ;
  if ((args_par->param_vm)->dump == 0)
    {
      if (args_par->ac > *i + 1 && str_isnum(args_par->av[*i + 1]) &&
	  (dump_num = my_getnbr(args_par->av[*i + 1])) > 0)
	{
	  (args_par->param_vm)->dump = dump_num;
	  *i = *i + 1;
	  ok = 1;
	}
      else
	ok = OPT_DUMP_NUM_ERR_CODE;
    }
  else
    ok = OPT_DUMP_ERR_CODE;
  return (ok);
}

int     check_ctmo_val(t_args_par *args_par,
                       int *current_champ,
                       int *i)
{
  int   ctmo_num;
  int	ok;

  ok = 0;
  ctmo_num = 0;
  current_champ = current_champ;
  if ((args_par->param_vm)->ctmo == -1)
    {
      if (args_par->ac > *i + 1 && str_isnum(args_par->av[*i + 1]) &&
	  (ctmo_num = my_getnbr(args_par->av[*i + 1])) >= 0)
	{
	  (args_par->param_vm)->ctmo = ctmo_num;
	  *i = *i + 1;
	  ok = 1;
	}
      else
	ok = OPT_CTMO_NUM_ERR_CODE;
    }
  else
    ok = OPT_CTMO_ERR_CODE;
  return (ok);
}
