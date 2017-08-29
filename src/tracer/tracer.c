/*
** tracer.c for ftrace in /home/jeanadrien/rendu/PROJECT/PSU_2016_ftrace/src/tracer
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May  5 01:01:25 2017 Jean-Adrien Domage
** Last update Sun May  7 20:11:36 2017 Gregoire Renard
*/

#include <errno.h>
#include <string.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include "ftrace.h"
#include "tracer.h"
#include "syscalls_entry.h"

static void	syscall_ret(struct user_regs_struct regs,
			    t_arg *target,
			    long ret)
{
  if (g_syscalls[regs.rax].ret == VOID)
    {
      printf(" = ?\n");
      return;
    }
  if (target->base == DECIMAL && (g_syscalls[regs.rax].ret == INT ||
				  g_syscalls[regs.rax].ret == SSIZE_T))
    printf(" = %ld\n", ret);
  else
    printf(" = 0x%lx\n", ret);
}

static void	syscall_arg_hexa(struct user_regs_struct regs,
				 int idx,
				 unsigned long int *tab)
{
  if (g_syscalls[regs.rax].param[idx] != VOID)
    {
      if (g_syscalls[regs.rax].param[idx] == CONST_CHAR_P ||
	  g_syscalls[regs.rax].param[idx] == CHAR_P ||
	  g_syscalls[regs.rax].param[idx] == CHAR_P_CONST)
	printf("%p", (void*)tab[idx]);
      else if (g_syscalls[regs.rax].param[idx] == VOID_P)
	{
	  if ((void*)tab[idx] == NULL)
	    printf("0x0");
	  else
	    printf("%p", (void*)tab[idx]);
	}
	else
	printf("0x%lx", (size_t)tab[idx]);
    }
}

static void	syscall_arg_dec(struct user_regs_struct regs,
				int idx,
				unsigned long int *tab,
				pid_t pid)
{
  if (g_syscalls[regs.rax].param[idx] != VOID)
    {
      if (g_syscalls[regs.rax].param[idx] == CONST_CHAR_P ||
	  g_syscalls[regs.rax].param[idx] == CHAR_P ||
	  g_syscalls[regs.rax].param[idx] == CHAR_P_CONST)
	char_ptr(idx, tab, pid);
      else if (g_syscalls[regs.rax].param[idx] == VOID_P)
	{
	  if ((void*)tab[idx] == NULL)
	    printf("NULL");
	  else
	    printf("%p", (void*)tab[idx]);
	}
      else if (g_syscalls[regs.rax].param[idx] == INT)
	printf("%ld", tab[idx]);
      else
	printf("0x%lx", (size_t)tab[idx]);
    }
}

static void	set_arg_tab(struct user_regs_struct regs,
			    unsigned long int *tab)
{
  tab[0] = regs.rdi;
  tab[1] = regs.rsi;
  tab[2] = regs.rdx;
  tab[3] = regs.rcx;
  tab[4] = regs.r8;
  tab[5] = regs.r9;
}

int	syscall_tracer(struct user_regs_struct regs, pid_t pid,
		       t_arg *target, long ret)
{
  int	idx;
  unsigned long int	tab[6];

  idx = 0;
  (void)pid;
  (void)target;
  printf("Syscall ");
  printf(g_syscalls[regs.rax].name);
  set_arg_tab(regs, tab);
  printf("(");
  while (idx < g_syscalls[regs.rax].argc)
    {
      if (idx != 0)
	printf(", ");
      if (target->base == HEXA)
	syscall_arg_hexa(regs, idx, tab);
      else
	syscall_arg_dec(regs, idx, tab, pid);
      idx += 1;
    }
  printf(")");
  syscall_ret(regs, target, ret);
  return (0);
}
