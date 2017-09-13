/*
** trunc_neg.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sat Dec 18 01:27:33 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 17:25:28 2010 eugene-valentin ngontang-tchiadjie
*/

#include	"asm.h"
#include	"commons.h"

static char	*do_trunc_neg(char *str)
{
    char	*cpy_str;

    cpy_str = my_strdup(&(str[1]));
    free(str);
    cpy_str = my_sub(TRUNC_VALUE, cpy_str, 2);
    return (cpy_str);
}

char	*trunc_neg(char *str)
{
  while (str[0] == MINUS && my_compar(&(str[1]), NEG_BOUND) > 0)
    str = do_trunc_neg(str);
  return (str);
}
