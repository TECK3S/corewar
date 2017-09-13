/*
** my_nbrlen_pf.c for my_printf in /home/barrau_a//my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Nov 24 15:19:50 2010 adrien barrau
** Last update Thu Nov 25 13:41:53 2010 adrien barrau
*/

int	my_nbrlen_pf(int nbr)
{
  int	len;

  len = 0;
  if (nbr == 0)
    len += 1;
  if (nbr < 0)
    {
      if (nbr < -2147483647)
	nbr = -2147483647;
      nbr *= -1;
      len += 1;
    }
  while (nbr != 0)
    {
      nbr /= 10;
      len += 1;
    }
  return (len);
}
