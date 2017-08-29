/*
** print_list.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_ftrace/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Apr 20 16:39:24 2017 Gregoire Renard
** Last update Fri May  5 01:36:41 2017 Jean-Adrien Domage
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftrace.h"

void			print_list(t_list *list)
{
  int			cpt;

  cpt = 0;
  while (list != NULL)
    {
      printf("list[%i].name = %s\n", cpt, list->name);
      printf("list[%i].addr = %zx\n", cpt, list->addr);
      printf("\n");
      list = list->next;
      cpt++;
    }
}
