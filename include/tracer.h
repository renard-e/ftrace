/*
** tracer.h for ftrace in /home/jeanadrien/rendu/PROJECT/PSU_2016_ftrace/include
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May  5 01:20:13 2017 Jean-Adrien Domage
** Last update Fri May  5 01:32:51 2017 Jean-Adrien Domage
*/

#ifndef TRACER_H_
# define TRACER_H_

# include <sys/types.h>
# include <sys/user.h>
# include "tracer_enum_type.h"
# include "ftrace.h"

typedef struct	s_syscall_tab
{
  int		idx;
  char		*name;
  int		argc;
  t_type	ret;
  t_type	param[6];
}		t_syscall_tab;

int	syscall_tracer(struct user_regs_struct regs,
		       pid_t pid,
		       t_arg *target,
		       long ret);
void	char_ptr(int idx,
		 size_t *tab,
		 pid_t pid);
void	print_execve(t_arg *target,
		     int ret);
void	ftrace_loop(int p,
		    t_arg *target,
		    t_list *list);

#endif /* !TRACER_H_ */
