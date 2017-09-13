/*
** dasm.h for corewar in /home/benich_a//afs/rendu/c/proj/corewar/corewar_2013s/trunk
** 
** Made by mickael benichou
** Login   <benich_a@epitech.net>
** 
** Started on  Sat Dec 18 14:25:13 2010 mickael benichou

*/

#ifndef		__DASM_H__
#define		__DASM_H__

# define	ERROR_USAGE_ERR_MSG		("Usage: ./dasm <filename.cor>\n")
# define	COR_DOESNT_EXIST_ERR_MSG	("The .cor file does not exist\n")
# define	COR_WRONG_RIGHT_ERR_MSG		("You are not permitted to use this .cor file\n")
# define	COR_OPEN_FAIL_ERR_MSG		("Opening error\n")
# define	BAD_READ_ERR_MSG		("Reading error\n")
# define	BAD_BYTE_CODE_ERR_MSG		("Imcomplete byte code\n")
# define	BAD_COR_FILE_ERR_MSG		("Bad .cor file\n")
# define	SRC_OPEN_FAIL_ERR_MSG		("Opening error\n")
# define	DASM_MESSAGE			("Desassembling %s :\n")

# define	MAIN_LABEL			("main")
# define	DOT_CODE			(".code")
# define	DOT_EXTEND			(".extend")

# define	INS_LIVE			("live")
# define	INS_LD				("ld")
# define	INS_ST				("st")
# define	INS_ADD				("add")
# define	INS_SUB				("sub")
# define	INS_AND				("and")
# define	INS_OR				("or")
# define	INS_XOR				("xor")
# define	INS_ZJMP			("zjmp")
# define	INS_LDI				("ldi")
# define	INS_STI				("sti")
# define	INS_FORK			("fork")
# define	INS_LLD				("lld")
# define	INS_LLDI			("lldi")
# define	INS_LFORK			("lfork")
# define	INS_AFF				("aff")
# define	INS_GTMD			("gtmd")
# define	LSEEK_ERR_MSG			("Lseek error\n")

# define	REG_OR_IND(size)		(((size) == (DIR_SIZE)) ? (IND_SIZE) : (size))

# define	NB_BITS_IN_OCT			(8)

# define	ERROR_USAGE_ERR_CODE		(0)
# define	COR_DOESNT_EXIST_ERR_CODE	(-1)
# define	COR_WRONG_RIGHT_ERR_CODE	(-2)
# define	COR_OPEN_FAIL_ERR_CODE		(-3)
# define	BAD_READ_ERR_CODE		(-4)
# define	BAD_BYTE_CODE_ERR_CODE		(-5)
# define	BAD_COR_FILE_ERR_CODE		(-6)
# define	SRC_OPEN_FAIL_ERR_CODE		(-7)

# define	COR_EXTENSION			(".cor")
# define	COR_EXT_LEN			(4)
# define	SRC_EXTENSION			(".s")
# define	SRC_EXT_LEN			(2)

# define	MAGIC_SIZE			(4)
# define	MIN_INSTRUCTION			(1)
# define	MAX_INSTRUCTION			(17)
# define	UNKNOWN_INSTRUCTION_CODE	(18)

typedef struct	s_file
{
  char		*pathname;
  char		*filename;
  int		prog_size;
  char		*comment;
  unsigned char	*output_file;
  int		fd;
}		t_file;

extern char *gl_err_msg[];
extern void (*gl_ins[])(t_file *file, int *i);

/*
** dasm.c
*/

void    dasm(char *cor_name);

/*
** load_cor_file.c
*/

int     load_cor_file(char *cor_name, t_file *file);

/*
** write_source_file.c
*/

int     write_source_file(t_file *file);

/*
** get_header_infos.c
*/

int     get_magicnum(int fd);
int     get_name(int fd, t_file *file);
int     get_comment(int fd, t_file *file);
int     get_progsize(int fd, t_file *file);
int     get_code(int fd, t_file *file);

/*
** write_param.c
*/

void	write_param(t_file *file, int *i, int size, int type);

/*
** ins_live.c
*/

void	ins_live(t_file *file, int *i);

/*
** ins_ld.c
*/

void	ins_ld(t_file *file, int *i);

/*
** ins_st.c
*/

void	ins_st(t_file *file, int *i);

/*
** ins_add.c
*/

void	ins_add(t_file *file, int *i);

/*
** ins_sub.c
*/

void	ins_sub(t_file *file, int *i);

/*
** ins_and.c
*/

void	ins_and(t_file *file, int *i);

/*
** ins_or.c
*/

void	ins_or(t_file *file, int *i);

/*
** ins_xor.c
*/

void	ins_xor(t_file *file, int *i);

/*
** ins_zjmp.c
*/

void	ins_zjmp(t_file *file, int *i);

/*
** ins_ldi.c
*/

void	ins_ldi(t_file *file, int *i);

/*
** ins_sti.c
*/

void	ins_sti(t_file *file, int *i);

/*
** ins_fork.c
*/

void	ins_fork(t_file *file, int *i);

/*
** ins_lld.c
*/

void	ins_lld(t_file *file, int *i);

/*
** ins_lldi.c
*/

void	ins_lldi(t_file *file, int *i);

/*
** ins_lfork.c
*/

void	ins_lfork(t_file *file, int *i);

/*
** ins_aff.c
*/

void	ins_aff(t_file *file, int *i);

/*
** ins_gtmd.c
*/

void	ins_gtmd(t_file *file, int *i);

/*
** ins_unky.c
*/

void	ins_unky(t_file *file, int *i);

/*
** check_oct_param.c
*/

int		get_parameter(unsigned char *tab_oct, int idx);
unsigned char	*check_oct_param(unsigned char code, unsigned char oct);

#endif		/*__DASM_H__*/
