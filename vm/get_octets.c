/*
** get_octets.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 18 03:50:27 2010 adrien barrau
** Last update Sun Dec 19 09:37:14 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"
#include "xfunctions.h"

static void	manage_octets_index(t_champion *champ,
				    unsigned char **big_male,
				    int size,
				    int *res)
{
  if (size == IND_SIZE)
    {
      if (*res < 0 && champ->pc + *res < 0)
	*res = MEM_SIZE + (champ->pc + *res);
      *res = get_octets(champ, big_male, DIR_SIZE, (*res % MEM_SIZE) - 2);
    }
}

int	get_octets(t_champion *champ,
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
	  res += (*big_male)[TO_ABS((champ->pc + 2 + offset + i++) % MEM_SIZE)];
	}
      if (res >= my_power_rec(2, (size * NB_BITS_IN_OCT) - 1))
	res = res - my_power_rec(2, size * NB_BITS_IN_OCT);
      manage_octets_index(champ, big_male, size, &res);
    }
  return (res);
}

static void	manage_mod_index(t_champion *champ,
				 unsigned char **big_male,
				 int size,
				 int *res)
{
  if (size == IND_SIZE)
    {
      if (*res < 0 && champ->pc + *res < 0)
	*res = MEM_SIZE + (champ->pc + *res);
      *res = get_octets(champ, big_male, DIR_SIZE, ((*res % IDX_MOD)
						    % MEM_SIZE) - 2);
    }
}

int	get_octets_mod(t_champion *champ,
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
	  res += (*big_male)[TO_ABS((champ->pc + 2 + offset + i++) % MEM_SIZE)];
	}
      if (res >= my_power_rec(2, (size * NB_BITS_IN_OCT) - 1))
	res = res - my_power_rec(2, size * NB_BITS_IN_OCT);
      manage_mod_index(champ, big_male, size, &res);
    }
  return (res);
}

int	get_octets_dir(t_champion *champ,
		       unsigned char **big_male,
		       int size,
		       int offset)
{
  int	i;
  int	res;
  int	reg;

  i = 0;
  res = 0;
  if (size == 1)
    {
      reg = (*big_male)[TO_ABS((champ->pc + 1 + offset) % MEM_SIZE)];
      if (reg >= 1 && reg <= REG_NUMBER)
	res = champ->registers[reg - 1];
    }
  else
    {
      while (i < size)
	{
	  res <<= NB_BITS_IN_OCT;
	  res += (*big_male)[TO_ABS((champ->pc + 1 + offset + i) % MEM_SIZE)];
	  i++;
	}
      if (res >= my_power_rec(2, (size * NB_BITS_IN_OCT) - 1))
	res = res - my_power_rec(2, size * NB_BITS_IN_OCT);
    }
  return (res);
}
