/*
** vm.h for vm in /home/benlou_d//proj/coreware/corewar_2013s/trunk/includes
** 
** Made by damien benloukil
** Login   <benlou_d@epitech.net>
** 
** Started on  Mon Nov 29 21:57:02 2010 damien benloukil

*/

#ifndef VM_H_
#define VM_H_

#ifdef		__linux__
#include	<SDL/SDL.h>
#include	<SDL/SDL_image.h>
#include	<SDL/SDL_ttf.h>
#endif

# define	MAX_CHAMPS			(4)
# define	GRAPH_NAME			("g")
# define	DUMP_NAME			("dump")
# define	N_NAME				("n")
# define	A_NAME				("a")
# define	CTMO_NAME			("ctmo")
# define	COMMENT_NAME			("comment")
# define	VERBOSE_NAME			("v")


# define	HOW_TO_MSG			("Usage: [-comment]\n       [-dump nb_cycles]\n       [[-n prog_number] [-a load_adress] prog_name] ...\n       [-ctmo nb_cycles]\n       [-g]\n       [-v]\n")
# define	EMPTY_STRING			("")
# define	BAD_OPTION_ERR_MSG		("Incorrect option\n")
# define	OPT_COMMENT_ERR_MSG		("Option comment must be set on only once\n")
# define	OPT_DUMP_ERR_MSG		("Option dump must be set on only once\n")
# define	OPT_DUMP_NUM_ERR_MSG		("Option dump must be superior to zero\n")
# define	OPT_CTMO_ERR_MSG		("Option CTMO must be set on only once\n")
# define	OPT_CTMO_NUM_ERR_MSG		("Option CTMO must be superior or equal to zero\n")
# define	OPT_GRAPH_ERR_MSG		("Graphic option already set on\n")
# define	OPT_N_EXIST_ERR_MSG		("Option -n already set on\n")
# define	OPT_N_BAD_ERR_MSG		("Number already used for a champion\n")
# define	OPT_A_EXIST_ERR_MSG		("Option -a already set on\n")
# define	OPT_A_BAD_ERR_MSG		("Wrong address for -a option\n")
# define	OPT_A_TOO_CLOSE_ERR_MSG		("Address too close from another\n")
# define	OPT_BAD_OPT_ERR_MSG		("Bad option requested\n")
# define	OPT_V_EXIST_ERR_MSG		("Wordy option already set on\n")
# define	TOO_MANY_CHAMPS_ERR_MSG		("Too many champions already in battle\n")
# define	OPT_TOO_FEW_ARG_MSG		("Too few arguments to this option\n")


# define	CHAMP_DOESNT_EXIST_ERR_MSG	("Champion does not exist\n")
# define	CHAMP_WRONG_RIGHT_ERR_MSG	("You are not permitted to use this champion\n")
# define	CHAMP_OPEN_FAIL_ERR_MSG		("Opening error\n")
# define	BAD_READ_ERR_MSG		("Reading error\n")
# define	BAD_BYTE_CODE_ERR_MSG		("Imcomplete byte code\n")
# define	BAD_CORE_FILE_ERR_MSG		("Bad .cor file\n")
# define	WIN_MSG				("Player %i (%s) wins")
# define	COMMENT_WIN_MSG			(" : %s")
# define	DRAW_MATCH_MSG			("Draw\n")
# define	V_INS_LIVE_MSG			("Player %i is alive\n")
# define	V_INS_ADD_MSG			("Player %i adds r%i and r%i to r%i\n")
# define	V_INS_SUB_MSG			("Player %i substracts r%i from r%i to r%i\n")
# define	V_INS_AND_MSG			("Player %i does a binary and between %i and %i in r%i\n")
# define	V_INS_OR_MSG			("Player %i does a binary or between %i and %i in r%i\n")
# define	V_INS_XOR_MSG			("Player %i does a binary xor between %i and %i in r%i\n")
# define	V_INS_FORK_MSG			("Player %i does a fork at %i\n")
# define	V_INS_ZJMP_MSG			("Player %i does a jump at %i\n")
# define	V_INS_LD_MSG			("Player %i loads %i in r%i\n")
# define	V_INS_ST_IND_MSG		("Player %i stores %i at %i\n")
# define	V_INS_STI_MSG			("Player %i stores index %i at %i\n")
# define	V_INS_ST_REG_MSG		("Player %i stores %i in r%i\n")
# define	V_INS_ST_ERR_MSG		("Player %i cannot store\n")
# define	V_INS_LDI_MSG			("Player %i loads index %i in r%i\n")
# define	V_INS_LLD_MSG			("Player %i loads far %i in r%i\n")
# define	V_INS_LLDI_MSG			("Player %i loads long index %i in r%i\n")
# define	V_INS_GTMD_MSG			("%i cycle(s) remaining before RAM's opening\n")
# define	V_INS_UNKY_MSG			("Player %i does an unknown instruction\n")
# define	MEMORY_DUMPED_MSG		("\n------------------- MEMORY DUMPED --------------------\n\n")
# define	CTMO_TO_REAL_VAL		(param_vm->ctmo == -1 ? 0 : param_vm->ctmo)

# define	SDL_ERR_INIT_MSG		("SDL initialization error\n")
# define	PIC_EXTEND			(".png")
# define	SQUARE_SIZE			(10)
# define	BOARD_WIDTH			(96)
# define	REFRESH				(40)
# define	BOARD_HEIGHT			(64)
# define	BOARD_COLOR			(32)
# define	SDL_REFRESH			(30)
# define	WINDOW_WIDTH			(BOARD_WIDTH * 10)
# define	WINDOW_HEIGHT			(BOARD_HEIGHT * 10)
# define	NAME_WINDOW			("C'est un truc de foo lolilolz")
# define	IMG_CHAMP_SIZE_X		(120)
# define	IMG_CHAMP_SIZE_Y		(90)
# define	QUARTER				(4)
# define	FIRST_QUARTER			(0.25)
# define	SECOND_QUARTER			(0.50)
# define	THIRD_QUARTER			(0.75)
# define	REG_ADD_GRAPH			(-42)

# define	HOW_TO_CODE			(-1)
# define	TOO_MANY_CHAMPS_ERR_CODE	(-2)
# define	OPT_BAD_OPT_ERR_CODE		(-3)
# define	OPT_DUMP_NUM_ERR_CODE		(-4)
# define	OPT_DUMP_ERR_CODE		(-5)
# define	OPT_A_EXIST_ERR_CODE		(-6)
# define	OPT_A_BAD_ERR_CODE		(-7)
# define	OPT_A_TOO_CLOSE_ERR_CODE	(-8)
# define	OPT_N_EXIST_ERR_CODE		(-9)
# define	OPT_N_BAD_ERR_CODE		(-10)
# define	OPT_TOO_FEW_ARG_CODE		(-11)
# define	OPT_CTMO_NUM_ERR_CODE		(-12)
# define	OPT_CTMO_ERR_CODE		(-13)
# define	OPT_COMMENT_ERR_CODE		(-14)
# define	OPT_GRAPH_ERR_CODE		(-15)
# define	OPT_V_EXIST_ERR_CODE		(-16)
# define	CHAMP_DOESNT_EXIST_ERR_CODE	(-17)
# define	CHAMP_WRONG_RIGHT_ERR_CODE	(-18)
# define	CHAMP_OPEN_FAIL_ERR_CODE	(-19)
# define	BAD_READ_ERR_CODE		(-20)
# define	BAD_BYTE_CODE_ERR_CODE		(-21)
# define	BAD_COR_FILE_ERR_CODE		(-22)
# define	SDL_ERR_INIT_CODE		(-23)

# define	MAGIC_SIZE			(4)
# define	LIVE_CODE			(1)
# define	MIN_INSTRUCTION			(1)
# define	MAX_INSTRUCTION			(17)
# define	UNKNOWN_INSTRUCTION_CODE	(18)
# define	NB_BITS_IN_OCT			(8)
# define	ASCII_TABLE_SIZE		(256)
# define	BASE_OCT			(256)

# define	TO_ABS(i)			(((i) < 0) ? ((i) * -1) : (i))
# define	OP_LEFT_SIZE			((idx[0] == 4 ? 2 : idx[0]))
# define	OP_RIGHT_SIZE			((idx[2] == 4 ? 2 : idx[2]))

typedef	struct	s_lives
{
  int	live;
  int	is_alive;
  int	count;
  int	tab_inlive[MAX_CHAMPS];
  int	cycle;
  int	cycle_to_die;
}	t_lives;

typedef struct	s_instruction
{
  unsigned char	code;
  int		nb_cycle_to_wait;
}		t_instruction;

typedef struct		s_champion
{
  char			*path;
  char			*name;
  char			*comment;
  int			number;
  int			load_address;
  int			prog_size;
  int			inlive;
  int			registers[REG_NUMBER];
  int			pc;
  unsigned char		carry;
  int			nb_child;
  t_instruction		instruction;
  int			address_instruction;
  struct s_champion	*children; 
  struct s_champion	*papounet;
  struct s_champion	*next; 
}			t_champion;

typedef struct s_info_graph
{
  t_lives	*lives;
  unsigned char	*big_male;
  float		ratio;
}		t_info_graph;

typedef	struct	s_SDL_data
{
  SDL_Surface	*screen;
  SDL_Surface	*base[MAX_CHAMPS + 1];
  SDL_Surface	*base_zero;
  SDL_Surface	*fond[14];
  SDL_Surface	*helico;  
  SDL_Surface	*tent;
  SDL_Surface	*start;
  SDL_Surface	*in[MAX_CHAMPS][10];
  SDL_Surface	*round[MAX_CHAMPS][10];
  SDL_Surface	*explosion[33];
  SDL_Surface	*out[MAX_CHAMPS][10];
}	SDL_data;

typedef struct s_param_vm
{    
  SDL_data	SDL;
  t_champion	champs[MAX_CHAMPS];
  int		dump;
  int		have_comment;
  int		ctmo;
  int		opt_graph;
  int		is_verbose;
  t_info_graph	info_graph;
}		t_param_vm;

typedef struct s_args_par
{
  int		ac;
  char		**av;
  t_param_vm	*param_vm;
}		t_args_par;

typedef struct s_opt
{
  char	*name_opt;
  int	(*check_opt_val)(t_args_par *, int *, int *);
}	t_opt;

extern	t_opt (gl_tab_opt[]);
extern	char (*gl_err_msg[]);
extern	void (*gl_instructions[])(t_champion *, t_param_vm *, unsigned char **, t_lives *);

/* 
** parse_option.c
*/

int     check_opt_name(char *opt_name);
void    add_champ(t_param_vm *param_vm, char *path, int *current_champ);
int     parse_option(t_args_par *args_par);
int	is_valid(char *num, t_param_vm  *param_vm);
int     check_option(t_args_par *args_par,
                     int *i,
                     int *current_champ);

/*
** check_champ_val.c
*/

int	check_load_address(int *load_address,
			   t_args_par *args_par,
			   int *i,
			   int *current_champ);
int	check_prog_number(int *prog_number,
			  t_args_par *args_par,
			  int *i,
			  int *current_champ);
int	check_add_champ(t_args_par *args_par, int *i, int *current_champ);
int     check_champ_val(t_args_par *args_par,
			int *current_champ,
			int *i);


/*
** check_val.c
*/

int     check_comment_val(t_args_par *args_par,
                          int *current_chanp,
                          int *i);
int     check_verbose_val(t_args_par *args_par,
                          int *current_chanp,
                          int *i);
int     check_graph_val(t_args_par *args_par,
			int *current_chanp,
			int *i);
int     check_dump_val(t_args_par *args_par,
		       int *current_chanp,
		       int *i);
int     check_ctmo_val(t_args_par *args_par,
                       int *current_champ,
                       int *i);

/*
** main.c
*/

void	init_args(int *ac,
		  char **av,
		  t_args_par *args_par,
		  t_param_vm *param_vm);
void    init_param_vm(t_param_vm *param_vm);

/*
** get_load_address.c
*/

int     *get_la_value(t_param_vm *param_vm);
void	add_load_address(int **la, int new_address);
void	find_far_address(t_param_vm *param_vm, int nbc, int **la);
void    get_load_address(t_param_vm *param_vm);

/*
** tool_inttab.c
*/

int	my_tab_intlen(int *res);
int	*my_sorttab_int(int **la);
int     *my_tab_intcpy(int *dest, int* src);

/*
** launch_virtual_machine.c
*/

int launch_virtual_machine(t_param_vm * param_vm);

/*
** check_valid_champs.c
*/

int	check_header_champ(t_param_vm *param_vm, int fd, unsigned char *big_male, int i);
int	load_champ(unsigned char *big_male, t_champion *champion, int fd);
int     check_valid_champs(t_param_vm *param_vm, unsigned char *big_male);

/*
** big_malloc.c
*/

unsigned char    *big_malloc(void);

/*
** get_headerinfos.c
*/

int     get_magicnum(int fd);
int     get_name(t_param_vm *param_vm, int fd, int idx);
int     get_comment(t_param_vm *param_vm, int fd, int idx);
int     get_progsize(t_param_vm *param_vm, int fd, int idx);

/*
** dump_memory.c
*/

int	dump_memory(unsigned char *big_male);


/*
** get_octets.c
*/

int		get_octets_mod(t_champion *champ, unsigned char **big_male, int size, int offset);
int		get_octets(t_champion *champ, unsigned char **big_male, int size, int offset);
int		get_octets_dir(t_champion *champ, unsigned char **big_male, int size, int offset);

/*
** check_oct_param.c
*/

int		get_parameter(unsigned char *tab_oct, int idx);
unsigned char	*check_oct_param(unsigned char code, unsigned char oct);

/*
** ins_live.c
*/

void	ins_live(t_champion *champ,
		 t_param_vm *param_vm,
		 unsigned char **big_male,
		 t_lives *lives);
/*
** ins_ld.c
*/

void	ins_ld(t_champion *champ,
	       t_param_vm *param_vm,
	       unsigned char **big_male,
	       t_lives *lives);

/*
** get_octets_st.c
*/

int	write_octets(unsigned char **big_male, int src, int dest, int count);
int	get_octets_st(t_champion *champ,
		      unsigned char **big_male,
		      int size,
		      int offset);

/*
** ins_st.c
*/
void	ins_st(t_champion *champ,
	       t_param_vm *param_vm,
	       unsigned char **big_male,
	       t_lives *lives);

/*
** ins_add.c
*/

void	ins_add(t_champion *champ,
		t_param_vm *param_vm,
		unsigned char **big_male,
		t_lives *lives);

/*
** ins_sub.c
*/

void	ins_sub(t_champion *champ,
		t_param_vm *param_vm,
		unsigned char **big_male,
		t_lives *lives);

/*
** ins_and.c
*/

void	ins_and(t_champion *champ,
		t_param_vm *param_vm,
		unsigned char **big_male,
		t_lives *lives);

/*
** ins_or.c
*/

void	ins_or(t_champion *champ,
	       t_param_vm *param_vm,
	       unsigned char **big_male,
	       t_lives *lives);

/*
** ins_xor.c
*/

void	ins_xor(t_champion *champ,
		t_param_vm *param_vm,
		unsigned char **big_male,
		t_lives *lives);

/*
** ins_zjmp.c
*/

void	ins_zjmp(t_champion *champ,
		 t_param_vm *param_vm,
		 unsigned char **big_male,
		 t_lives *lives);

/*
** ins_ldi.c
*/

void	ins_ldi(t_champion *champ,
		t_param_vm *param_vm,
		unsigned char **big_male,
		t_lives *lives);
int	get_octets_ldi(t_champion *champ,
		       unsigned char **big_male,
		       int size,
		       int offset);

/*
** ins_sti.c
*/

void	ins_sti(t_champion *champ,
		t_param_vm *param_vm,
		unsigned char **big_male,
		t_lives *lives);

/*
** ins_fork.c
*/

void		ins_fork(t_champion *champ,
			 t_param_vm *param_vm,
			 unsigned char **big_male,
			 t_lives *lives);
t_champion      *fill_child(t_champion *child,
			    t_champion *champ,
			    int fork_idx,
			    int is_long);
void	insert_child(t_champion *child, t_champion *champ);
void	load_child(t_champion *child, t_champion *champ, unsigned char **big_male);

/*
** ins_lld.c
*/

void	ins_lld(t_champion *champ,
		t_param_vm *param_vm,
		unsigned char **big_male,
		t_lives *lives);

/*
** ins_lldi.c
*/

void	ins_lldi(t_champion *champ,
		 t_param_vm *param_vm,
		 unsigned char **big_male,
		 t_lives *lives);

/*
** ins_lfork.c
*/

void	ins_lfork(t_champion *champ,
		  t_param_vm *param_vm,
		  unsigned char **big_male,
		  t_lives *lives);

/*
** ins_aff.c
*/

void	ins_aff(t_champion *champ,
		t_param_vm *param_vm,
		unsigned char **big_male,
		t_lives *lives);

/*
** ins_gtmd.c
*/

void	ins_gtmd(t_champion *champ,
		 t_param_vm *param_vm,
		 unsigned char **big_male,
		 t_lives *lives);

/*
** ins_unky.c
*/

void	ins_unky(t_champion *champ,
		 t_param_vm *param_vm,
		 unsigned char **big_male,
		 t_lives *lives);

/*
** virtual_machine_core.c
*/

int	check_live_champs(t_lives *lives,
			  t_param_vm *param_vm);
void	throw_champ(t_champion *champ,
		    t_param_vm *param_vm,
		    t_lives *lives,
		    unsigned char **big_male);
void	exec_champs(t_param_vm *param_vm,
		    t_lives *lives,
		    unsigned char **big_male);
void	virtual_machine_core(t_param_vm *param_vm, unsigned char *big_male);

/*
** init_register.c
*/

void	init_registers(t_champion *champ);

/*
** and_the_winner_is.c
*/

void	and_the_winner_is(t_param_vm *param_vm, t_lives *lives);

/*
** check_dump.c
*/

int	check_dump(t_param_vm *param_vm, unsigned char *big_male, int cycle);

/*
** update_ctmo.c
*/

void	update_ctmo(t_param_vm *param_vm);

/*
** update_graphic.c
*/

void	update_graphic(t_param_vm *param_vm, unsigned char *big_male, t_lives *lives);

/*
** on_pause.c
*/

int	on_pause(void);

/*
** manage_event.c
*/

int	manage_event(t_param_vm *param_vm, unsigned char *big_male, t_lives *lives);

/*
** get_progs_number.c
*/

void	get_progs_number(t_param_vm *param_vm);

/*
** check_too_close_address.c
*/

int	check_too_close_address(t_param_vm *param_vm, int current_champ);

/*
** addr_is_inside.c
*/

int	addr_is_inside(t_champion *champ, int addr);

/*
** init_SDL.c
*/

int	init_SDL(t_param_vm *param_vm);

/*
** aff_graph
*/

void    aff_children(t_param_vm *param_vm, SDL_Rect *pos, int i);
void    aff_instruction(t_param_vm *param_vm, SDL_Rect *pos, int i);
void    aff_base(int i, t_param_vm *param_vm, SDL_Rect *pos);
void	aff_buildbase(int i, t_param_vm *param_vm, SDL_Rect *pos);

/*
** 
*/

void	frame_per_sec(t_param_vm *param_vm, SDL_Rect *pos);

#endif
