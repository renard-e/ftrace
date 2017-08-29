/*
** parser.c for ftrace in /home/jeanadrien/rendu/PROJECT/PSU_2016_ftrace/src/parser
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May  5 01:00:26 2017 Jean-Adrien Domage
** Last update Sun May  7 20:05:32 2017 Gregoire Renard
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ftrace.h"

static char    g_parser_option[3][3] = {
  OPTION1,
  OPTION2,
  OPTION3
};

void	print_usage(char *prog_name)
{
  printf("USAGE:\n");
  printf("\t%s: ", prog_name);
  printf("%s\n", USAGE);
}

static void	arg_setter(t_arg *new,
			   char *prog_name,
			   char **environ)
{
  new->father = prog_name;
  new->target = NULL;
  new->pid = -1;
  new->arg = NULL;
  new->environ = environ;
  new->base = HEXA;
}

static int	find_occurance(t_arg *new,
			       int ac,
			       char **av)
{
  int		idx;
  int		func;
  int		ret;

  idx = 0;
  parser_setter();
  while (idx++ < ac && av[idx])
    {
      func = 0;
      ret = -1;
      while (func < OPTION_NB && av[idx] && ret == -1)
	{
	  if (strcmp(av[idx], g_parser_option[func]) == 0)
	    {
	      if ((ret = (parser[func])(new, ac, av, &idx)) == -1)
		return (-1);
	    }
	  else if (func == 2)
	    if ((ret = (parser[func])(new, ac, av, &idx)) == -1)
	      return (-1);
	  func += 1;
	}
      idx += ret;
    }
  return (0);
}

t_arg	*get_arg(int ac,
		 char **av,
		 char **environ)
{
  t_arg	*new;

  if (ac == 1)
    return (print_usage(av[0]), NULL);
  if (!(new = malloc(sizeof(t_arg))))
    return (perror(av[0]), NULL);
  arg_setter(new, av[0], environ);
  if (find_occurance(new, ac, av) == -1)
    return (free(new), NULL);
  if (new->target == NULL && new->pid == -1)
    return (free(new), NULL);
  return (new);
}
