/*
** asm.h for asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
<<<<<<< .mine
** Last update Sun Dec 19 21:17:55 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 16:15:12 2010 remi bartel
=======
** Last update Sun Dec 19 20:38:47 2010 remi bartel
>>>>>>> .r173
** Last update Mon Dec 13 18:28:34 2010 remi bartel
*/

#ifndef		__ASM_H__
#define		__ASM_H__

#define		ENOEXIST	("Cannot open file")
#define		BADEXTEND	("Invalid extension")
#define		SUCCESS		("Compilation succeded")
#define		ERR_HEADER	("Bad header")
#define		ERR_FW_ARG	("Too few arguments")
#define		ERR_HDUNKN	("Unknown header word")
#define		ERR_BADARG	("Statement unknown")
#define		WRONG_TYPE	("Bad parameter type")
#define		ERROR_USAGE	("Usage: ./asm infile")
#define		SUCCESS		("Compilation succeded")
#define		WRONG_TYPE	("Bad parameter type")
#define		ERR_NAMELG	("Program name too long")
#define		BIN_EXTENSION	("cor")
#define		CALL_ERROR	("Undefined reference to")
#define		ERROR_STAT	("Error occured when getting file information")
#define		SUCCESS		("Compilation succeded")
#define		ERR_HDUNKN	("Unknown header word")
#define		WRONG_TYPE	("Bad parameter type")
#define		ERROR_STAT	("Error occured when getting file information")
#define		SUCCESS		("Compilation succeded")
#define		ERR_NONAME	("No program name specified")
#define		ERR_HEADER	("Bad header")
#define		ERR_FW_ARG	("Too few arguments")
#define		ERR_MN_ARG	("Too many arguments")
#define		ERR_HDUNKN	("Unknown header word")
#define		ERR_BADARG	("Statement unknown")
#define		ERR_ACOMMA	("Argument expected after a comma")
#define		ERR_REGIST	("a register-type data ought to be with format 'r + [1 <-> 16]'")
#define		ERR_DIRECT	("a direct-type data ought to be with format '% + [ integer or :label ]'")
#define		ERR_COMMA	("arguments ought to be seperated by a comma")
#define		ERR_FW_ARG	("Too few arguments")
#define		ERR_MN_ARG	("Too many arguments")
#define		ERR_HDUNKN	("Unknown header word")
#define		ERR_NONAME	("No program name specified")
#define		ERR_NAMELG	("Program name too long")
#define		ERR_QUOTEXP	("Quote expected after name declaraction statement")
#define		ERR_QUOTEXPC	("Quote expected after comment declaraction statement")
#define		ERR_BADCHR	("Bad character found when a comma or end of line is expected")
#define		ERR_HDMISP	("misplaced")
#define		ERR_NOCOMM	("No program comment specified")
#define		ERR_COMMLG	("Program comment too long")

#define		VAL_NAME	(1)
#define		VAL_COMM	(2)
#define		VAL_EXTD	(4)

#define		BIN_SIZE	(1024)
#define		BASE_DEC	(256)
#define		ONE		("1")
#define		MIN_Q		("8388608")
#define		MAX_Q		("2147483648")
#define		GET_LAB_ADDR	('X')
#define		BASE		("256")
#define		BASE_INT	("0123456789")
#define		NEG_BOUND	MAX_Q
#define		POS_BOUND	("2147483647")
#define		TRUNC_VALUE	("4294967296")
#define		BOUND_1		BASE
#define		BOUND_2		("65536")
#define		BOUND_3		("16777216")
#define		BOUND_4		TRUNC_VALUE
#define		MINUS		('-')
#define		PLUS		('+')
#define		BUFF_CHAR_SIZE	(1024)
#define		DIV		('/')
#define		MULT		('*')

#include		"op.h"

typedef struct s_inst_code
{
  char	param_char;
  int	(*inst_code) (unsigned char *, int);
}		t_inst_code;

extern t_inst_code	inst_code_tab[];

typedef struct	s_inst
{
  char		*mnemo;
  char		**params;
  struct s_inst	*next;
}		t_inst;

typedef struct	s_label
{
  char			*label;
  struct s_inst		*l_inst;
  struct s_label	*next;
}			t_label;

typedef struct	s_call
{
  char			*label;
  int			line;
  struct s_call		*next;
} t_call;

typedef struct	s_param
{
  char			*name;
  int			index;
  int			param_size;
  char			sign;
  int			val;
  struct s_param	*next;
}			t_param;

typedef struct	s_ireg
{
  char		*inst_name;
  void		(*get_param) (unsigned char **, int *, char **, t_param **);
}		t_ireg;

extern t_ireg	ireg_tab[];

typedef struct s_link
{
  int			spe;
  int			add;
  int			extd;
  char			*label;
  int			nb;
  char			*mnemo;
  unsigned	char	*inst;
} t_link;

typedef struct s_spe
{
  int	val;
  char	*lib;
} t_spe;

/* main.c */

typedef	struct	s_file
{
  char		*filename;
  t_label	*label_list;
  header_t	*header;
}		t_file;

/* division euclidienne */

typedef struct	s_div
{
  char	*quotient;
  char	*rest;
}		t_div;

/* compile.c */

void	compile(t_file *file);


/* compilation */

void	do_cmp(t_file *file, int to_update);
int	add_reg(unsigned char *octet_code, int n);
int	add_dir(unsigned char *octet_code, int n);
int	add_ind(unsigned char *octet_code, int n);
unsigned char	*do_fill(unsigned char *str, int i, unsigned char c);
int	my_getaddr(char *str);
unsigned char	*put_param(unsigned char *str, int *i, int nb_oct, char *param);
unsigned char	*my_putaddr(char *addr, int nb_oct);
unsigned char	*copy_addr(int nb_oct);
void	free_label_stack(t_call *all_label);
void	free_call_addr(t_param *call_list);
void	store_label(t_call **all_label, char *label, int i);
void	store_addr_call(t_param **call_list, int pc, char *param, int nb_oct);
int	check_inst(t_inst *l_inst, unsigned char **str, int *i, t_param **call_list);
void	do_zjmp(unsigned char **str, int *i, char **params, t_param **call_list);
void	do_live(unsigned char **str, int *i, char **params, t_param **call_list);
void	do_sti(unsigned char **str, int *i, char **params, t_param **call_list);
void	do_ldi(unsigned char **str, int *i, char **params, t_param **call_list);
void	do_lldi(unsigned char **str, int *i, char **params, t_param **call_list);
void	do_fork(unsigned char **str, int *i, char **params, t_param **call_list);
void	do_lfork(unsigned char **str, int *i, char **params, t_param **call_list);
int	add_reg(unsigned char *octet_code, int n);
int	add_dir(unsigned char *octet_code, int n);
int	add_ind(unsigned char *octet_code, int n);
t_file	*complete_header(t_file *file, int i);
unsigned char	*end_copy(unsigned char *str, t_call *all_label, t_param *call_list);
void	create_bin(header_t *header, char *name, unsigned char *cor, int n);
void	my_fill_with_zero(char tab[], int n);
int	is_label(char *param);
unsigned char	*get_header(int nbr, int size);
void	do_rev(t_label **list);
char	get_op(char c);
unsigned char	*do_code(unsigned char *str, char *s, int *i);

/* truncation des parametres */

int	my_compar(char *s1, char *s2);
char	*trunc_nbr(char	*str);
char	*trunc_neg(char *str);
char	*trunc_pos(char *str);
char	*my_sub(char *s1, char *s2, int n);
char    *fill_nbr(char *str, int n);
int     get_index(char c);
char	*do_power_two(int nb_oct);
char	*my_getchar_addr(char *str);
char	*my_add(char *nbr1, char *nbr2);
char     *my_int_to_char(int nbr);
char	*full_check(char *addr, int nb_oct);


/* seek_nb_arg(char *key, int *nb, int len); */

unsigned	char	*seek_nb_arg(char *key, t_link *link, int len);

/* parsing.c */

int	parsing(char *str, int count, t_link *link);

/* whole_parsing.c */

int	whole_parsing(int fd, t_file *file);

/* check_log.c */

int	check_log(char *str, char *cor_file);

/* fill_headers.c */

void	fill_header(t_file *file, int add, char *str);

/* my_get_paramtab */

char	**my_get_paramtab(unsigned char *str, int nb);

/* my_put_inlist.c */

void	my_put_inlist(t_link *link, t_label **label_list, t_call **call_list, int line);

/* my_insert_inst.c */

void	my_insert_inst(t_inst **inst_list, t_link *link, t_call **call_list, int line);

/* check_call.c */

int     check_call(t_call *call_list, t_label *label_list);

/* header.c */

int	seek_header(char *val, t_link *link, int line);

/* check_arg_nb.c */

int	check_arg_nb(int exp, int found, int line);

/* disp_bad_header.c */

void	disp_bad_header(int line);

/* disp_wong_type.c */

void	disp_wrong_type(int line);

/* is_alpha.c */

int     is_alpha(char c);

/* is_num.c */

int     is_num(char c);

/* is_valid.c */

int	is_valid(char c);

/* go_next_word */

char	*go_next_word(char *str);

/* check_name.c */

int	check_name(char *str, t_link *link);

/* check_comment.c */

int	check_comment(char *str, t_link *link);

/* disp_syntax_err.c */

void	disp_syntax_err(int line);

/* whole_parsing.c */

int     whole_parsing(int fd, t_file *file);

/* check_arg_type */

int	check_arg_type(char *str, char type, int line, int extd);

/* go_next_word */

char	*go_next_word(char *str);

/* rev_label.c */

void	rev_label(t_label **list);

/* rev_inst.c */

void	rev_inst(t_inst **list);

/* get_length.c */

int	get_length(char *str);

/* process_extd.c */

char	*process_extd(unsigned char *str, char type);

/* is_utterly_num.c */

int	is_utterly_num(char *str);

/*
** free_struct
*/

void		free_inst(t_inst *instruction);
void		free_label(t_label *label);
void		free_file(t_file *file);

 
#endif /* __ASM_H__ */
