/*
** ftrace.h for ftrace in /home/jeanadrien/rendu/PROJECT/PSU_2016_ftrace/include
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May  5 01:19:12 2017 Jean-Adrien Domage
** Last update Sun May  7 14:40:59 2017 Gregoire Renard
*/

#ifndef FTRACE_H_
# define FTRACE_H_

# include <unistd.h>
# include <libelf.h>
# include <gelf.h>

/*
**  parser
*/

# define USAGE		"[-s] [-p <pid>|<command>]"

# define OPTION1	"-s\0"
# define OPTION2	"-p\0"
# define OPTION3	"\0"

# define OPTION_NB	3

# define ERROR		-1
# define SUCCESS	1
# define SYMTAB		".symtab"
# define UNDEFINED	-2
# define SIZE_OPTI	100
# define DYN_NAME	&all->str_dyn_tab[all->dyn_tab[ELF64_R_SYM(all->dyn[cpt].r_info)].st_name]

typedef enum	e_base
  {
    DECIMAL = 10,
    HEXA = 16
  }		t_base;

typedef	struct	s_arg
{
  char		*father;
  char		*target;
  int		pid;
  char		**arg;
  char		**environ;
  t_base       	base;
}		t_arg;

int	prog_setter(t_arg *new, int ac, char **av, int *idx);
int	pid_setter(t_arg *new, int ac, char **av, int *idx);
int	base_setter(t_arg *new, int ac, char **av, int *idx);
void	print_usage(char *prog_name);
void	parser_setter(void);
int	(*parser[3])(t_arg *, int, char **, int *);
t_arg	*get_arg(int ac, char **av, char **environ);

/*
**  launcher
*/

typedef struct	s_process
{
  pid_t		father;
  pid_t		son;
}		t_process;

typedef struct s_list t_list;

int	launch(t_arg *target, t_list *list);

/*
**  list Function
*/

typedef struct	s_all_type
{
  Elf64_Sym	*dyn_tab;
  char		*str_dyn_tab;
  Elf		*elf;
  Elf_Scn	*scn;
  GElf_Shdr	shdr;
  Elf_Data	*data;
  Elf64_Rela	*dyn;
}		t_all_type;
  
typedef struct	s_list
{
  char		*name;
  size_t	addr;
  struct s_list	*next;
  struct s_list *prev;
}		t_list;

typedef struct	s_all
{
  int		size;
  int		cpt;
  int		x;
  int		y;
  char		**map;
}		t_all;
  
int	printf_error(const char *error);
t_list	*init_list(const char *file);
int	add_elem(t_list **list, const char *name, const size_t addr);
void	print_list(t_list *list);
void	free_list(t_list *list);
int	update_list_dyn_lib(t_list **list, Elf *elf, int fd);
char	*get_symbole(const t_list *list, const size_t addr);
char	*get_path_file(const char *file);
char	**my_str_to_wordtab(char *str);
void	print_map(char **map);
void	free_map(char **map);

#endif /* !FTRACE_H_ */
