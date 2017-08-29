/*
** launcher.c for ftrace in /home/jeanadrien/rendu/PROJECT/PSU_2016_ftrace/src/launcher
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May  5 00:59:59 2017 Jean-Adrien Domage
** Last update Sun May  7 20:01:35 2017 Gregoire Renard
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ftrace.h"
#include "tracer.h"

static int		ftrace_attach(t_arg *target, t_process *proc, t_list *list)
{
  (void)proc;
  if (ptrace(PTRACE_ATTACH, target->pid, NULL, NULL) == -1)
    return (-1);
  ptrace(PTRACE_CONT, target->pid, 0, 0);
  printf("%s: Process %d attached\n", target->father, target->pid);
  ftrace_loop(target->pid, target, list);
  ptrace(PTRACE_DETACH, target->pid, 0, 0);
  return (0);
}

static int		ftrace_fork(t_arg *target, t_process *proc, t_list *list)
{
  int		fd;
  int		ret;

  if ((ret = fork()) == -1)
    return (-1);
  if (ret == 0)
    {
      fd = open("/dev/null", O_WRONLY | O_TRUNC | O_CREAT,
		S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
      dup2(fd, 1);
      ptrace(PTRACE_TRACEME, proc->father);
      execvp(target->target, target->arg);
    }
  else
    {
      proc->son = ret;
      ftrace_loop(proc->son, target, list);
    }
  return (0);
}

int		launch(t_arg *target, t_list *list)
{
  t_process	*proc;

  if (!(proc = malloc(sizeof(t_process))))
    return (perror(target->father), -1);
  proc->father = getpid();
  if (target->pid != -1)
    ftrace_attach(target, proc, list);
  else
    if (ftrace_fork(target, proc, list) == -1)
      return (free(proc), -1);
  return (0);
}
