/*
** my_strlen_pf.c for my_printf in /home/barrau_a//my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Nov 24 15:46:19 2010 adrien barrau
** Last update Wed Dec  1 00:49:28 2010 root
*/

int	my_strlen(char *str)
{
  int	len;

  len = 0;
  while (str && str[len])
    len++;
  return (len);
}
