/*
** my_power_rec.c for my_power_rec in /home/barrau_a//piscine/Jour_05
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Oct  8 20:12:47 2010 adrien barrau
** Last update Sun Dec 12 18:04:22 2010 adrien barrau
*/

int	my_power_rec(int nb, int power)
{
  int	result;

  if (power < 0)
    return (0);
  if (power < 1)
    return (1);
  result = nb * my_power_rec(nb, power - 1);
  return (result);
}
