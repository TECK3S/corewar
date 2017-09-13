/*
** full_check.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sun Dec 19 02:40:04 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 15:06:53 2010 eugene-valentin ngontang-tchiadjie
*/

#include	<stdlib.h>
#include	"commons.h"
#include	"asm.h"

char	*full_check(char *addr, int nb_oct)
{
  char	*cpy_addr;

  cpy_addr = my_strdup(&(addr[1]));
  free(addr);
  cpy_addr = my_sub(do_power_two(nb_oct), cpy_addr, 2);
  return (cpy_addr);
}
