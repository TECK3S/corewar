/*
** do_cmp.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sun Dec 12 18:49:00 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 23:11:39 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:36:36 2010 remi bartel
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "commons.h"
#include "xfunctions.h"
#include "op.h"

static int	*get_octet_code(char **params, unsigned char *octet_code)
{
  int	cpt;
  int	j;
  int	*nb_oct;

  cpt = 0;
  j = 0;
  nb_oct = xmalloc((my_tablen(params) + 1) * sizeof(*nb_oct));
  while (params[cpt])
    {
      nb_oct[cpt] = 0;
      j = 0;
      while (inst_code_tab[j].param_char && nb_oct[cpt] == 0)
	{
	  if (params[cpt][0] == inst_code_tab[j].param_char)
	    nb_oct[cpt] = inst_code_tab[j].inst_code(octet_code, cpt);
	  j++;
	}
      if (nb_oct[cpt] == 0)
	nb_oct[cpt] = add_ind(octet_code, cpt);
      cpt++;
    }
  return (nb_oct);
}

static unsigned char	get_code(char *mnemo)
{
  int	cpt;

  cpt = 0;
  while (op_tab[cpt].mnemonique != NULL)
    {
      if (my_strcmp(mnemo, op_tab[cpt].mnemonique) == 0)
	return (op_tab[cpt].code);
      cpt++;
    }
  return (GET_LAB_ADDR);
}

static int	init_var(unsigned char *octet_code,
			 int *i,
			 unsigned char **str,
			 t_inst *l_inst)
{
  unsigned	char code;
  
  code = get_code(l_inst->mnemo);
  *octet_code = 0;
  if (code != GET_LAB_ADDR)
    {
      *str = do_fill(*str, *i, code);
      *i = *i + 1;
    }
  else
    *str = do_code(*str, l_inst->params[0], i);
  return (0);
}

static unsigned char	*copy_inst(unsigned char *str,
				   int *i,
				   t_inst *l_inst,
				   t_param **call_list)
{
  int		cpt;
  unsigned char	octet_code;
  int		*params;
  int		pc;

  while (l_inst != NULL)
    {
      cpt = init_var(&octet_code, i, &str, l_inst);
      pc = *i - 1;
      if (check_inst(l_inst, &str, i, call_list) == 0)
	{
	  params = get_octet_code(l_inst->params, &octet_code);
	  str = do_fill(str, *i, octet_code);
	  *i = *i + 1;
	  while (l_inst->params[cpt])
	    {
	      store_addr_call(call_list, pc, l_inst->params[cpt], params[cpt]);
	      str = put_param(str, i, params[cpt], l_inst->params[cpt]);
	      cpt++;
	    }
	  free(params);
	}
      l_inst = l_inst->next;
    }
  return (str);
}

void	do_cmp(t_file *file, int to_update)
{
  unsigned char	*core_file;
  int		i;
  t_label	*label_list;
  t_param	*call_list;
  t_call	*all_label;

  i = 0;
  call_list = NULL;
  all_label = NULL;
  core_file = xmalloc(BIN_SIZE * sizeof(*core_file));
  label_list = file->label_list;
  while (label_list != NULL)
    {
      store_label(&all_label, label_list->label, i);
      core_file = copy_inst(core_file, &i, label_list->l_inst, &call_list);
      label_list = label_list->next;
    }
  file = complete_header(file, i);
  core_file = end_copy(core_file, all_label, call_list);
  create_bin(file->header, file->filename, core_file, to_update);
  free(core_file);
  free_label_stack(all_label);
  free_call_addr(call_list);
}
