/*
** execve.c for ftrace in /home/jeanadrien/rendu/PROJECT/PSU_2016_ftrace/src/function
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May  5 00:59:45 2017 Jean-Adrien Domage
** Last update Fri May  5 01:35:05 2017 Jean-Adrien Domage
*/

#include <stdio.h>
#include "ftrace.h"

void	print_execve(t_arg *target, unsigned int ret)
{
  int	idx;

  idx = 0;
  printf("Syscall execve(");
  if (target->base == HEXA)
    {
      printf("%p", target->target);
      printf(", %p", target->arg);
      printf(", %p", target->environ);
      printf(") = 0x%x", ret);
    }
  else
    {
      printf("\"%s\"", target->target);
      printf(", [\"%s\"]", target->arg[0]);
      while (target->environ[idx])
	idx += 1;
      printf(", [/* %d vars */]", idx);
      printf(") = %i", ret);
    }
  printf("\n");
}
