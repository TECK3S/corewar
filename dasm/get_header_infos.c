/*
** get_header_infos.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/dasm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Dec 19 03:11:56 2010 adrien barrau
** Last update Sun Dec 19 17:16:37 2010 adrien barrau
*/

#include "op.h"
#include "commons.h"
#include "dasm.h"
#include "xfunctions.h"

int	get_magicnum(int fd)
{
  int	ok;
  unsigned char	buf[MAGIC_SIZE];
  int	i;
  int	mem_read;

  i = 0;
  ok = 1;
  if ((mem_read = read(fd, buf, MAGIC_SIZE)) == -1)
    ok = BAD_READ_ERR_CODE;
  if (ok > 0 && mem_read != MAGIC_SIZE)
    ok = BAD_BYTE_CODE_ERR_CODE;
  mem_read = 0;
  while (ok > 0 && i < MAGIC_SIZE)
    {
      mem_read <<= NB_BITS_IN_OCT;
      mem_read +=  buf[i++];
    }
  if (ok > 0 && mem_read != COREWAR_EXEC_MAGIC)
    ok = BAD_COR_FILE_ERR_CODE;
  return (ok);
}

int		get_name(int fd, t_file *file)
{
  int		ok;
  unsigned char	buf[PROG_NAME_LENGTH + 4];
  int		mem_read;

  ok = 1;
  if ((mem_read = read(fd, buf, PROG_NAME_LENGTH + 4)) == -1)
    ok = BAD_READ_ERR_CODE;
  if (ok > 0 && mem_read != PROG_NAME_LENGTH + 4)
    ok = BAD_BYTE_CODE_ERR_CODE;
  if (ok > 0)
    {
      file->filename = xmalloc((PROG_NAME_LENGTH + 5) * sizeof(*buf));
      file->filename = my_strncpy(file->filename,
				  (char *)buf, PROG_NAME_LENGTH + 4);
    }
  return (ok);
}

int		get_comment(int fd, t_file *file)
{
  int		ok;
  unsigned char	buf[COMMENT_LENGTH + 4];
  int		mem_read;

  mem_read = 0;
  ok = 1;
  if ((mem_read = read(fd, buf, COMMENT_LENGTH + 4)) == -1)
    ok = BAD_READ_ERR_CODE;
  if (ok > 0 && mem_read != COMMENT_LENGTH + 4)
    ok = BAD_BYTE_CODE_ERR_CODE;
  if (ok > 0)
    {
      file->comment = xmalloc((COMMENT_LENGTH + 5) * sizeof(*buf));
      file->comment = my_strncpy(file->comment,
				 (char *)buf, COMMENT_LENGTH + 4);
    }
  return (ok);
}

int		get_progsize(int fd, t_file *file)
{
  int		ok;
  unsigned char	buf[MAGIC_SIZE];
  int		i;
  int		mem_read;

  i = 0;
  ok = 1;
  if ((mem_read = read(fd, buf, MAGIC_SIZE)) == -1)
    ok = BAD_READ_ERR_CODE;
  if (ok > 0 && mem_read != MAGIC_SIZE)
    ok = BAD_BYTE_CODE_ERR_CODE;
  while (ok > 0 && i < MAGIC_SIZE)
    {
      ok <<= NB_BITS_IN_OCT;
      ok += buf[i++];
    }
  if (ok > 0)
    file->prog_size = ok;
  return (ok);
}

int		get_code(int fd, t_file *file)
{
  int		ok;
  int		i;
  int		mem_read;

  i = 0;
  ok = 1;
  file->output_file = xmalloc((file->prog_size + 1)
			      * sizeof(*(file->output_file)));
  if ((mem_read = read(fd, file->output_file, file->prog_size + 1)) == -1)
    ok = BAD_READ_ERR_CODE;
  if (ok > 0 && (mem_read != file->prog_size))
    ok = BAD_BYTE_CODE_ERR_CODE;
  return (ok);
}
