/*
** inst_code.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Mon Dec 13 18:58:19 2010 eugene-valentin ngontang-tchiadjie
   Last update Sun Dec 19 23:05:06 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:41:51 2010 remi bartel
*/

#include "asm.h"
#include "commons.h"
#include "op.h"

int	add_reg(unsigned char *octet_code, int n)
{
  int i;

  i = n * 2;
  i++;
  *octet_code = *octet_code + my_power_rec(2, 7 - i);
  return (T_REG);
}

int	add_dir(unsigned char *octet_code, int n)
{
  int i;

  i = n * 2;
  *octet_code = *octet_code + my_power_rec(2, 7 - i);
  return (REG_SIZE);
}

int	add_ind(unsigned char *octet_code, int n)
{
  int i;

  i = n * 2;
  *octet_code = *octet_code + my_power_rec(2, 7 - i);
  i++;
  *octet_code = *octet_code + my_power_rec(2, 7 - i);
  return (IND_SIZE);
}
