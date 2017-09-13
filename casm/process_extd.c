/*
** process_extd.c for process_extd in /home/benich_a//afs/rendu/c/proj/corewar/corewar_2013s/trunk/casm
** 
** Made by mickael benichou
** Login   <benich_a@epitech.net>
** 
** Started on  Sun Dec 19 14:03:13 2010 mickael benichou
** Last update Sun Dec 19 18:27:00 2010 remi bartel
*/

#include "op.h"
#include "commons.h"

static void	process_code(unsigned char *str)
{
  while (*str)
    {
      if (*str >= 'A' && *str <= 'F')
	*str += 32;
      if (!(*str >= '0' && *str <= '9') &&
	  !(*str >= 'a' && *str <= 'f') && *str != ' ')
	*str = '0';
      ++str;
    }
}

char	*process_extd(unsigned char *inst, char type)
{
  char	*res;
  int	len;

  if (type == T_CODE)
    process_code(inst);
  len = my_strlen((char*) inst);
  res = ((char*)inst + len);
  return (res);
}
