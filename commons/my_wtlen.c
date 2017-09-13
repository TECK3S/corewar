/*
** my_wtlen.c for my lib in /u/all/benich_a/cu/rendu/c/minishell2
** 
** Made by mickael benichou
** Login   <benich_a@epitech.net>
** 
** Started on  Mon Dec  7 23:43:22 2009 mickael benichou
** Last update Fri Nov 12 09:07:11 2010 mickael benichou
*/
int		my_wtlen(char **wt)
{
  int		nbword;

  nbword = 0;
  while (wt[nbword] != 0)
    {
      nbword++;
    }
  return (nbword);
}
