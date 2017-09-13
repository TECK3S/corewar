/*
** copy_addr.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Thu Dec 16 02:15:27 2010 eugene-valentin ngontang-tchiadjie
** Last update Thu Dec 16 02:48:54 2010 eugene-valentin ngontang-tchiadjie
*/

#include	"asm.h"
#include	"xfunctions.h"

unsigned char	*copy_addr(int nb_oct)
{
  unsigned char		*buff_addr;
  int			i;

  buff_addr = xmalloc((nb_oct + 1) * sizeof(*buff_addr));
  i = nb_oct;
  buff_addr[i] = '\0';
  i = i - 1;
  while (i >= 0)
    {
      buff_addr[i] = GET_LAB_ADDR;
      i = i - 1;
    }
  return (buff_addr);
}
