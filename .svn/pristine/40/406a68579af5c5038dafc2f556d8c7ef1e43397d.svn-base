/*
** my_nbrlen_base_pf.c for my_printf in /home/barrau_a//c/my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Nov 25 13:41:17 2010 adrien barrau
** Last update Wed Dec  1 01:20:17 2010 root
*/

#include "commons.h"

int	my_nbrlen_base_pf(unsigned int nbr, char *base)
{
  int	len;
  int	base_len;

  len = 0;
  base_len = my_strlen(base);
  if (nbr == 0)
    len += 1;
  while (nbr != 0)
    {
      nbr /= base_len;
      len += 1;
    }
  return (len);
}
