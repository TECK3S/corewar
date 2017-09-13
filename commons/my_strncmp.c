/*
** my_strcmp.c for coreware in /home/benlou_d//proj/coreware/corewar_2013s/trunk/commons
** 
** Made by damien benloukil
** Login   <benlou_d@epitech.net>
** 
** Started on  Fri Dec  3 12:08:07 2010 damien benloukil
** Last update Mon Dec  6 11:29:51 2010 remi bartel
*/

int     my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while ((s1[i] || s2[i]) && i < n)
    {
      if (s1[i] > s2[i])
	return (1);
      if (s2[i] > s1[i])
	return (-1);
      ++i;
    }
  return (0);
}
