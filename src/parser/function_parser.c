/*
** function_parser.c for ftrace in /home/jeanadrien/rendu/PROJECT/PSU_2016_ftrace/src/parser
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May  5 01:00:15 2017 Jean-Adrien Domage
** Last update Sun May  7 20:05:19 2017 Gregoire Renard
*/

#include <stdlib.h>
#include <stdio.h>
#include "ftrace.h"

int	prog_setter(t_arg *new,
		    int ac,
		    char **av,
		    int *idx)
{
  if (new->pid != -1)
    return (print_usage(new->father), -1);
  new->target = av[(*idx)];
  new->arg = av + (*idx);
  return (ac - 1 - (*idx));
}

int	pid_setter(t_arg *new,
		   int ac,
		   char **av,
		   int *idx)
{
  char	*err_ptr;

  (void)ac;
  if (!av[(*idx) + 1] || new->target != NULL)
    return (print_usage(new->father), -1);
  new->pid = strtol(av[(*idx) + 1], &err_ptr, DECIMAL);
  if (*err_ptr != '\0')
    return (print_usage(new->father), -1);
  return (1);
}

int	base_setter(t_arg *new,
		    int ac,
		    char **av,
		    int *idx)
{
  (void)ac;
  (void)av;
  (void)idx;
  new->base = DECIMAL;
  return (0);
}

void	parser_setter(void)
{
  parser[0] = base_setter;
  parser[1] = pid_setter;
  parser[2] = prog_setter;
}
