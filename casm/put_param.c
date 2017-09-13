/*
** put_param.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Mon Dec 13 21:00:45 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 23:18:46 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:46:54 2010 remi bartel
*/

#include <stdlib.h>
#include "asm.h"
#include "commons.h"
#include "op.h"

static int	is_zero(char *str)
{
  int	i;
  int	result;

  result = 1;
  i = 0;
  while (str && str[i] && result)
    {
      if (str[i] != '0')
	result = 0;
      i++;
    }
  return (result);
}

static	char	*check_overflow(char *addr, int nb_oct)
{
  if (addr[0] == MINUS)
    {
      while (addr[0] == MINUS)
	addr = full_check(addr, nb_oct);
    }
  else if (!is_zero(addr))
    {
      while (my_compar(addr, do_power_two(nb_oct)) > 0)
	addr = my_sub(addr, do_power_two(nb_oct), 1);
    }
  return (addr);
}

unsigned char	*put_param(unsigned char *str,
			   int *i, int nb_oct, char *param)
{
  unsigned char	*buf;
  int		cpt;
  char		*recup_addr;

  recup_addr = NULL;
  cpt = 0;
  if (is_label(param) == 1)
    buf = copy_addr(nb_oct);
  else
    {
      recup_addr = my_getchar_addr(param);
      recup_addr = check_overflow(recup_addr, nb_oct);
      buf = my_putaddr(recup_addr, nb_oct);
    }
  while (cpt < nb_oct)
    {
      str = do_fill(str, *i, buf[cpt]);
      cpt++;
      *i = *i + 1;
    }
  free(recup_addr);
  free(buf);
  return (str);
}
