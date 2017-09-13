/*
** my_getchar_addr.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sat Dec 18 18:08:16 2010 eugene-valentin ngontang-tchiadjie
** Last update Sat Dec 18 19:24:58 2010 eugene-valentin ngontang-tchiadjie
*/

#include	"op.h"
#include	"asm.h"
#include	"commons.h"

static char	*get_right_str(char *str)
{
  if (str[0] == REG_CHAR || str[0] == DIRECT_CHAR)
    return (&(str[1]));
  return (str);
}

char	*my_getchar_addr(char *str)
{
  char	*str_cpy;

  str_cpy = my_strdup(get_right_str(str));
  str_cpy = trunc_nbr(str_cpy);
  return (str_cpy);
 }
