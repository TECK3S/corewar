/*
** get_octets_st.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 18 19:34:06 2010 adrien barrau
** Last update Sat Dec 18 19:47:12 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

int	write_octets(unsigned char **big_male, int src, int dest, int count)
{
  if (count == 0)
    {
      (*big_male)[TO_ABS((dest + count) % MEM_SIZE)] = src % BASE_OCT;
      return (0);
    }
  write_octets(big_male, src / BASE_OCT, dest, count - 1);
  (*big_male)[TO_ABS((dest + count) % MEM_SIZE)] = src % BASE_OCT;
  return (0);
}

int	get_octets_st(t_champion *champ,
		      unsigned char **big_male,
		      int size,
		      int offset)
{
  int	i;
  int	res;
  int	reg;

  i = 0;
  res = 0;
  if (size == T_REG)
    {
      reg = (*big_male)[TO_ABS((champ->pc + 2 + offset) % MEM_SIZE)];
      if (reg >= 1 && reg <= REG_NUMBER)
	res = champ->registers[reg - 1];
    }
  else
    {
      while (i < size)
	{
	  res <<= NB_BITS_IN_OCT;
	  res += (*big_male)[TO_ABS((champ->pc + 2 + offset + i) % MEM_SIZE)];
	  i++;
	}
      if (res >= my_power_rec(2, (size * NB_BITS_IN_OCT) - 1))
	res = res - my_power_rec(2, size * NB_BITS_IN_OCT);
    }
  return (res);
}
