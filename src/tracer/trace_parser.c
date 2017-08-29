/*
** trace_parser.c for ftrace in /home/jeanadrien/rendu/PROJECT/PSU_2016_ftrace/src/tracer
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May  5 00:59:09 2017 Jean-Adrien Domage
** Last update Sun May  7 20:07:06 2017 Gregoire Renard
*/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/user.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <string.h>
#include "ftrace.h"
#include "tracer.h"
#include "my_vector.h"
#include "signal_name.h"
#include "syscalls_entry.h"

int		call_catch(int p,
			   struct user_regs_struct regs,
			   t_list *list,
			   t_vector *vec,
			   unsigned short instr,
			   const char *name)
{
  char		*symbol;
  int		status;
  int		idx;

  idx = 0;
  ptrace(PTRACE_SINGLESTEP, p, 0, 0);
  waitpid(p, &status, 0);
  ptrace(PTRACE_GETREGS, p, NULL, &regs);
  symbol = get_symbole(list, regs.rip);
  if (symbol == NULL && (instr & 0xff) == 0xff)
    return (status);
  vec->push(vec, regs.rip);
  if (symbol != NULL)
    {
      while (idx < 332)
	{
	  if (strcmp(g_syscalls[idx].name, symbol) == 0)
	    return (status);
	  idx += 1;
	}
      printf("Entering function %s at 0x%llx\n", symbol, regs.rip);
    }
  else if (list == NULL)
    printf("Entering function_%llx@%s\n", regs.rip, name);
  return (status);
}

static void	ret_catch(t_list *list,
			  t_vector *vec,
			  const char *name)
{
  char		*symbol;
  size_t	addr;
  int		idx;

  idx = 0;
  addr = vec->pop(vec);
  symbol = get_symbole(list, addr);
  while (symbol != NULL && idx < 332)
    {
      if (strcmp(g_syscalls[idx].name, symbol) == 0)
	return;
      idx += 1;
    }
  if (symbol != NULL)
    printf("Leaving function %s\n", symbol);
  else if (list == NULL)
    printf("Leaving function_%lx@%s\n", addr, name);
}

static void	sig_catch(siginfo_t *sig)
{
  if (sig->si_signo > -1 && sig->si_signo < 32 && sig->si_signo != 5)
    printf("Received signal %s\n", g_signal_tab[sig->si_signo - 1]);
}

static int			op_tracer(int p,
					  t_arg *target,
					  t_list *list,
					  t_vector *vec)
{
  struct user_regs_struct	regs;
  struct user_regs_struct	regs_return;
  unsigned short		instr;
  int				status;
  siginfo_t			sig;

  waitpid(p, &status, WSTOPPED);
  while (!WIFEXITED(status))
    {
      ptrace(PTRACE_GETREGS, p, NULL, &regs);
      instr = ptrace(PTRACE_PEEKTEXT, p, regs.rip, 0);
      ptrace(PTRACE_GETSIGINFO, p, NULL, &sig);
      sig_catch(&sig);
      if ((instr & 0xff) == 0xe8 ||
	  (instr & 0xff) == 0xff || (instr & 0xff) == 0x9a)
	status = call_catch(p, regs, list, vec, instr, target->father);
      else if ((instr & 0xff) == 0xc3)
	ret_catch(list, vec, target->father);
      ptrace(PTRACE_SINGLESTEP, p, 0, 0);
      waitpid(p, &status, 0);
      ptrace(PTRACE_GETREGS, p, 0, &regs_return);
      if (instr == 0x050F)
      	syscall_tracer(regs, p, target, regs_return.rax);
    }
  return (status);
}

void		ftrace_loop(int p,
			    t_arg *target,
			    t_list *list)
{
  int		status;
  t_vector	*vec;

  if (!(vec = vector_ctor()))
    return;
  if (target->pid == -1)
    print_execve(target, WIFEXITED(status) ? -1 : 0);
  status = op_tracer(p, target, list, vec);
  vector_dtor(vec);
  if (WIFEXITED(status))
    printf("+++ exited with %i +++\n", WEXITSTATUS(status));
}
