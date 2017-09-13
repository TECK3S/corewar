/*
** end_copy.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Tue Dec 14 05:11:43 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 21:32:15 2010 eugene-valentin ngontang-tchiadjie
*/

#include	<stdlib.h>
#include	"commons.h"
#include	"asm.h"

static int	get_call_addr(int pc, unsigned char *str)
{
  int	cpt;

  cpt = pc;
  while (str[cpt] != GET_LAB_ADDR)
    cpt++;
  return (cpt);
}

static int	get_extend(int addr, int val, char sign)
{
  if (sign == PLUS)
    addr = addr + val;
  else if (sign == MINUS)
    addr = addr - val;
  else if (sign == DIV)
    addr = addr / val;
  else if (sign == MULT)
    addr = addr * val;
  return (addr);
}

static unsigned char	*replace_call(unsigned char *str,
				      int line,
				      t_param *call_list)
{
  int		addr;
  int		cpt;
  int		call_addr;
  unsigned char	*buf;
  char		*recup_addr;

  cpt = 0;
  addr = line  - call_list->index;
  addr = get_extend(addr, call_list->val, call_list->sign);
  recup_addr = my_int_to_char(addr);
  call_addr = get_call_addr(call_list->index, str);
  if (recup_addr[0] == MINUS)
    {
      while (recup_addr[0] == MINUS)
	recup_addr = full_check(recup_addr, call_list->param_size);
    }
  buf = my_putaddr(recup_addr, call_list->param_size);
  while (cpt < call_list->param_size)
    str[call_addr++] = buf[cpt++];
  free(recup_addr);
  free(buf);
  return (str);
}

unsigned char	*end_copy(unsigned char *str,
			  t_call *all_label,
			  t_param *call_list)
{
  t_call	*tmp;

  while (call_list != NULL)
    {
      tmp = all_label;
      while (tmp && (my_strcmp(call_list->name, tmp->label) != 0))
	tmp = tmp->next;
      if (tmp != NULL)
	str = replace_call(str, tmp->line, call_list);
      call_list = call_list->next;
    }
  return (str);
}
