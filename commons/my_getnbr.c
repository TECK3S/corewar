/*
** my_getnbr.c for corewar in /home/benlou_d//proj/coreware/corewar_2013s/trunk/commons
** 
** Made by damien benloukil
** Login   <benlou_d@epitech.net>
** 
** Started on  Fri Dec  3 12:25:58 2010 damien benloukil
** Last update Fri Dec  3 12:26:07 2010 damien benloukil
*/

int	my_getnbr(char *str)
{
  int	i;
  int	end_sign;
  int	sign;
  int	number;

  i = 0;
  end_sign = 0;
  sign = 1;
  number = 0;
  while ((str[i] >= '0' && str[i] <= '9')
	 || ((str[i] == '+' || str[i] == '-') && !end_sign))
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  end_sign = 1;
	  number = (number * 10) + (str[i] - '0');
	}
      if (str[i] == '-')
	sign = sign * -1;
      i++;
    }
  return (number * sign);
}
