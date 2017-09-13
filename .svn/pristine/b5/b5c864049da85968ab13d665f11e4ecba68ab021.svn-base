/*
** commons.h for corewar in /home/benich_a//afs/rendu/c/proj/corewar/corewar_2013s/trunk/includes
** 
** Made by mickael benichou
** Login   <benich_a@epitech.net>
** 
** Started on  Sat Nov 20 04:37:07 2010 mickael benichou
** Last update Sun Dec 19 18:01:54 2010 damien benloukil
*/

#ifndef		__COMMONS_H__
#define		__COMMONS_H__

#include	<stdarg.h>
#include	<stdlib.h>
#include	<unistd.h>

#define	BAD_FD_FPRINTF_ERR_MSG	("Bad file descriptor.\n")
#define	STDERR			(2)

/*
** my_gnl.h
*/
#define		READ_SIZE 1024

typedef struct	s_gnl
{
  int		fd;
  int		pos2;
  char		*s2;
  char		*s3;
  char		*s4;
}		t_gnl;

char	*get_next_line(int fd);
char	*get_next_line2(t_gnl *gnl);
char	*get_next_line3(t_gnl *gnl, int *size, int *pos, char *buffer);

/*
** my_strncpy.h
*/
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strdup(char *str);


# define	TO_DIGIT(c)	((c) + '0')

/*
** struct_format.h
*/
  struct s_format
  {
    int		flags[5];
    int		width;
    int		precision;
    char	*len_mod;
  };
  typedef	struct s_format	t_format;

/*
** struct_con_spe.h
*/
  struct s_con_spe
  {
    char	name;
    void	(*fct)(t_format *, int *, int);
  };
  typedef	struct s_con_spe	t_con_spe;

/*
** my_free_wt
*/

void		my_free_wt(char **wt);

/*
** struct_string.h
*/
  struct s_string
  {
    char	*format;
    int		new_idx;
  };
  typedef	struct s_string	t_string;

/*
** global
*/
  extern char gl_flags[];
  extern char *gl_len_mod[];
  extern t_con_spe gl_con_spe[];
  extern va_list gl_ap;

/*
** flags_pos.h
*/
# define	FL_DIESE_POS	(0)
# define	FL_ZERO_POS	(1)
# define	FL_MINUS_POS	(2)
# define	FL_SPACE_POS	(3)
# define	FL_PLUS_POS	(4)

/*
** my_printf.h
*/
  int my_printf(char *format, ...);
  int my_fprintf(int fd, char *format, ...);

/*
** xfunctions.h
*/

# define	STDOUT		(1)
# define	XCWRT_ERR_MSG	("Cannot write\n")

  void xcwrite(char c, int *char_count, int fd);

/*
** check_flag.h
*/
  void check_flag(t_string *strct_str, t_format *strct_format);
  int pos_flag(char c);

/*
** check_con_spe.h
*/
  int check_con_spe(t_string *strct_str, t_format *strct_format, int *chr_cnt, int fd);

/*
** check_len_mod.h
*/
  void check_len_mod(t_string *strct_str, t_format *strct_format);

/*
** check_precision.h
*/
  void check_precision(t_string *strct_str, t_format *strct_format);

/*
** check_width.h
*/
  void check_width(t_string *strct_str, t_format *strct_format);

/*
** fill_with_blank.h
*/
  void fill_with_blank(t_format *strct_format, int *chr_cnt, int nbr_len, int fd);

/*
** my_getnbr.h
*/
  int my_getnbr(char *str);


/*
** my_getnbr_base.h
*/
int my_getnbr_base(char *str, char *base);

/*
** my_nbrlen_base_pf.h
*/
  int my_nbrlen_base_pf(unsigned int nbr, char *base);


/*
** my_nbrlen_pf.h
*/
  int my_nbrlen_pf(int nbr);

/*
** my_put_bin.h
*/
  void my_put_bin(t_format *strct_format, int *chr_cnt, int fd);

/*
** my_put_char_pf.h
*/
  void my_put_char_pf(t_format *strct_format, int *chr_cnt, int fd);



/*
** my_put_fct.h
*/
  void my_put_e_or_f(t_format *strct_format, int *chr_cnt, int fd);
  void my_put_e_or_f_big(t_format *strct_format, int *chr_cnt, int fd);
  void my_put_double_hex(t_format *strct_format, int *chr_cnt, int fd);
  void my_put_double_hex_big(t_format *strct_format, int *chr_cnt, int fd);
  void my_put_nb_char(t_format *strct_format, int *chr_cnt, int fd);

/*
** my_put_fct_long.h
*/
  void my_put_expo_double(t_format *strct_format, int *chr_cnt, int fd);
  void my_put_expo_double_big(t_format *strct_format, int *chr_cnt, int fd);
  void my_put_double(t_format *strct_format, int *chr_cnt, int fd);
  void my_put_double_big(t_format *strct_format, int *chr_cnt, int fd);

/*
** my_put_int.h
*/
void my_put_int(t_format *strct_format, int *chr_cnt, int fd);

/*
** my_putnbr_base_pf.h
*/
  void my_putnbr_base_pf(unsigned int nbr, char *base, int *chr_cnt, int fd);

/*
** my_putnbr_pf.h
*/
  void my_putnbr_pf(int nbr, int *chr_cnt, int fd);

/*
** my_put_pourcent.h
*/
  void my_put_pourcent(t_format *strct_format, int *chr_cnt, int fd);

/*
** my_put_ptr.h
*/
  void my_put_ptr(t_format *strct_format, int *chr_cnt, int fd);

/*
** my_putstr_big_pf.h
*/
  int char_is_printable_pf(char c);
  void my_putstr_big_pf(char *str, int *chr_cnt, int fd);

/*
** my_put_string_big.h
*/
  void my_put_string_big(t_format *strct_format, int *chr_cnt, int fd);

/*
** my_put_string.h
*/
  void my_put_string(t_format *strct_format, int *chr_cnt, int fd);

/*
** my_putstr_pf.h
*/
  void my_putstr_pf(char *str, int *chr_cnt, int fd);

/*
** my_put_uhex_big.h
*/
  void my_put_uhex_big(t_format *strct_format, int *chr_cnt, int fd);

/*
** my_put_uhex.h
*/
  void my_put_uhex(t_format *strct_format, int *chr_cnt, int fd);

/*
** my_put_uint.h
*/
  void my_put_uint(t_format *strct_format, int *chr_cnt, int fd);

/*
** my_putunbr_pf.h
*/
  void my_putunbr_pf(unsigned int nbr, int *chr_cnt, int fd);

/*
** my_put_uoctal.h
*/
  void my_put_uoctal(t_format *strct_format, int *chr_cnt, int fd);

/*
** my_strlen_big_pf.h
*/
  int my_strlen_big_pf(char *str);

/*
** my_strlen_pf.h
*/
  int my_strlen(char *str);
  int my_wtlen(char **wt);

/*
** my_tablen.c
*/
  int my_tablen(char **tab);

/*
** my_strncmp_pf.h
*/
  int my_strncmp_pf(char *s1, char *s2, int nb);

/*
** my_strncmp.c
*/
  int my_strncmp(char *s1, char *s2, int nb);

/*
** my_unbrlen_pf.h
*/

  int my_unbrlen_pf(unsigned int nbr);

/*
** my_strdup
*/
  char	*my_strdup(char *str);

/*
** header_cpy
*/
void	header_cpy(char header[], char *src);


/*
** parse_arg.h
*/
  int parse_arg(char *format, int idx, int *chr_cnt, int fd);
  void init_strct_format(t_format *strct_format);

/*
** my_strcmp 
*/

  int     my_strcmp(char *s1, char *s2);
  char	  *my_strncat(char *dest, char *src, int n);
  char	  *my_strcat(char *dest, char *src);

/*
** str_isnum.h
*/

  int	str_isnum(char*str);

/*
** my_power_rec.c
*/
int	my_power_rec(int nb, int power);

/*
** my_memset.c
*/
void	*my_memset(char *mem, unsigned char v, size_t len);

#endif		/*__COMMONS_H__*/
