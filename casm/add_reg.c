/*
** inst_code.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Mon Dec 13 18:58:19 2010 eugene-valentin ngontang-tchiadjie
** Last update Thu Dec 16 20:36:13 2010 eugene-valentin ngontang-tchiadjie
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
