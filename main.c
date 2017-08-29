/*
** main.c for strace in /home/jeanadrien/rendu/PROJECT/PSU_2016_strace
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Mon Apr  3 10:30:45 2017 Jean-Adrien Domage
** Last update Sun May  7 20:00:21 2017 Gregoire Renard
*/

#include <stdlib.h>
#include <stdio.h>
#include "ftrace.h"

int	main(int ac, char **av, char **environ)
{
  t_arg	*args;
  int	ret;
  t_list *list;

  ret = 0;
  if (!(args = get_arg(ac, av, environ)))
    return (1);
  list = init_list(args->target);
  ret = launch(args, list);
  free(args);
  free_list(list);
  return (ret);
}
