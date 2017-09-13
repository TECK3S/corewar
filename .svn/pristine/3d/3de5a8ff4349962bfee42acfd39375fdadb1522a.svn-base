/*
** addr_is_inside.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Dec 16 20:00:22 2010 adrien barrau
** Last update Fri Dec 17 23:45:02 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

int	addr_is_inside(t_champion *champ, int addr)
{
  int	ok;
  int	begin_inter;
  int	end_inter;

  ok = 0;
  begin_inter = champ->load_address;
  end_inter = champ->load_address + champ->prog_size;
  addr = addr % MEM_SIZE;
  if (end_inter > MEM_SIZE)
    end_inter = end_inter - MEM_SIZE;
  if (end_inter < begin_inter)
    {
      if ((addr >= begin_inter && addr <= MEM_SIZE - 1)
	  || (addr >= 0 && addr <= end_inter))
	ok = 1;
    }
  else
    {
      if (addr >= begin_inter && addr <= end_inter)
	ok = 1;
    }
  return (ok);
}
