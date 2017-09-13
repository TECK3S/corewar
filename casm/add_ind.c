/*
** add_ind.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Thu Dec 16 01:48:00 2010 eugene-valentin ngontang-tchiadjie
** Last update Thu Dec 16 01:49:12 2010 eugene-valentin ngontang-tchiadjie
*/

#include "asm.h"
#include "commons.h"
#include "op.h"

int	add_ind(unsigned char *octet_code, int n)
{
  int i;

  i = n * 2;
  *octet_code = *octet_code + my_power_rec(2, 7 - i);
  i++;
  *octet_code = *octet_code + my_power_rec(2, 7 - i);
  return (IND_SIZE);
}
