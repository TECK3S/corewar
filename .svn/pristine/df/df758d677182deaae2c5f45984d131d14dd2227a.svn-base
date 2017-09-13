/*
** my_strncpy.c for my_lib in /home/benich_a//afs/rendu/lib/my
** 
** Made by mickael benichou
** Login   <benich_a@epitech.net>
** 
** Started on  Mon Nov  8 20:42:05 2010 mickael benichou
** Last update Tue Dec  7 17:27:19 2010 eugene-valentin ngontang-tchiadjie
*/

char		*my_strncpy(char *dest, char *src, int n)
{
  int		cpt;

  cpt = 0;
  if (src && dest)
    {
      while (src[cpt] != '\0' && cpt < n)
	{
	  dest[cpt] = src[cpt];
	  cpt = cpt + 1;
	}
      dest[cpt] = '\0';
    }
  return (dest);
}
