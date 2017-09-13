/*
** trunc_pos.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sat Dec 18 02:10:01 2010 eugene-valentin ngontang-tchiadjie
** Last update Sat Dec 18 18:52:14 2010 eugene-valentin ngontang-tchiadjie
*/

#include	"asm.h"

char	*trunc_pos(char *str)
{
  while (str[0] != MINUS && my_compar(str, POS_BOUND) > 0)
    str = my_sub(str, TRUNC_VALUE, 1);
  return (str);
}
