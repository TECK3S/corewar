/*
** my_putaddr.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Tue Dec 14 00:51:44 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 17:04:18 2010 eugene-valentin ngontang-tchiadjie
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"xfunctions.h"
#include	"commons.h"

static unsigned char	*fill_buff(unsigned char *s, int q, int rest, int n)
{
  int	i;

  i = n;
  s[i--] = '\0';
  s[i--] = rest;
  while (i >= 0)
    {
      {
	s[i] = q % BASE_DEC;
	q = q / BASE_DEC;
	i = i - 1;
      }
    }
  return (s);
}

static unsigned char	*div_eucli(char *addr, unsigned char *buff_addr, int n)
{
  char		*rest;
  int		i;
  int		q;
  int		new_rest;

  i = n;
  rest = my_sub(addr, MAX_Q, 0);
  q = my_getaddr(MIN_Q);
  new_rest = my_getaddr(rest);
  if (new_rest >= BASE_DEC)
    {
      q = q + (new_rest / BASE_DEC);
      new_rest = new_rest % BASE_DEC;
    }
  fill_buff(buff_addr, q, new_rest, n);
  free(rest);
  return (buff_addr);
}

unsigned char	*my_putaddr(char *addr, int nb_oct)
{
  unsigned char		*buff_addr;
  int			i;
  int			value;

  buff_addr = xmalloc((nb_oct + 1) * sizeof(*buff_addr));
  i = nb_oct;
  if (my_compar(addr, POS_BOUND) > 0)
    buff_addr = div_eucli(addr, buff_addr, nb_oct);
  else
    {
      value = my_getaddr(addr);
      buff_addr[i] = '\0';
      i = i - 1;
      while (i >= 0)
	{
	  buff_addr[i] = value % BASE_DEC;
	  value = value / BASE_DEC;
	  i = i - 1;
	}
    }
  return (buff_addr);
}
