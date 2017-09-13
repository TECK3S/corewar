/*
** get_op.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sun Dec 19 20:19:15 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:28:58 2010 eugene-valentin ngontang-tchiadjie
*/

#include	"asm.h"

char	get_op(char c)
{
  char sign;
  
  sign = '0';
  
  if (c == MINUS)
    sign = c;
  if (c == MULT)
    sign = c;
  if (c == DIV)
    sign = c;
  return (sign);
}
