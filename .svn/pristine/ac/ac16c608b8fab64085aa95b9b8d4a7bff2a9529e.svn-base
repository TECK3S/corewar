/*
** str_isnum.c for corewar in /home/benlou_d//proj/coreware/corewar_2013s/trunk/vm
** 
** Made by damien benloukil
** Login   <benlou_d@epitech.net>
** 
** Started on  Fri Dec  3 12:20:24 2010 damien benloukil
** Last update Fri Dec  3 12:58:33 2010 damien benloukil
*/

int	str_isnum(char *str)
{
  int	i;
  int	is_num;

  i = 0;
  is_num = 0;
  if (str)
    {
      is_num = 1;
      while (str[i])
	{
	  if (str[i] < '0' || str[i] > '9')
	    is_num = 0;
	  i++;
	}
    }
  return (is_num);
}
