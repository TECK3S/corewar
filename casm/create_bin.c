/*
** create_bin.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Tue Dec 14 05:49:44 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 23:22:27 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:35:59 2010 remi bartel
*/

#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"op.h"
#include	"xfunctions.h"
#include	"commons.h"

static void	free_all(unsigned char *s1, unsigned char *s2, char *s3)
{
  free(s1);
  free(s2);
  free(s3);
}

static void	do_write_name(int fd, unsigned char *magic, char *name)
{
  xwrite(fd, magic, REG_SIZE);
  xwrite(fd, name, PROG_NAME_LENGTH + 1);
  xwrite(fd, "\0\0\0", 3);
}

static void	do_write_comment(int fd, unsigned char
				 *prog_size, char *comment)
{
  xwrite(fd, prog_size, REG_SIZE);
  xwrite(fd, comment, COMMENT_LENGTH + 1);
  xwrite(fd, "\0\0\0", 3);
}

static void	do_write_prog(int fd, unsigned
			      char *core_file, header_t *header)
{
  xwrite(fd, core_file, header->prog_size);
  my_printf("\t%s\n", header->prog_name);
  my_printf("\t%s\n", header->comment);
}

void	create_bin(header_t *header, char *name, unsigned char *cor, int n)
{
  char		*cor_file;
  unsigned char	*magic_number;
  unsigned char	*prog_size;
  int		fd;

  magic_number = get_header(header->magic, REG_SIZE);
  prog_size = get_header(header->prog_size, REG_SIZE);
  my_fill_with_zero(header->prog_name, PROG_NAME_LENGTH);
  my_fill_with_zero(header->comment, COMMENT_LENGTH);
  cor_file = xmalloc((my_strlen(name) + 3) * (sizeof(*cor_file)));
  cor_file = my_strncpy(cor_file, name, my_strlen(name) - 1);
  cor_file = my_strcat(cor_file, BIN_EXTENSION);
  umask(S_IWGRP | S_IWOTH);
  if (n == 1)
    fd = open(cor_file, O_RDWR | O_CREAT | O_TRUNC,  S_IRUSR | S_IWUSR
	      | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
  else
    fd = open(cor_file, O_RDWR | O_CREAT,  S_IRUSR | S_IWUSR
	      | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
  do_write_name(fd, magic_number, header->prog_name);
  do_write_comment(fd, prog_size, header->comment);
  do_write_prog(fd, cor, header);
  close(fd);
  free_all(magic_number, prog_size, cor_file);
}
