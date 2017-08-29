/*
** add_elem.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_ftrace/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Apr 20 16:21:13 2017 Gregoire Renard
** Last update Sun May  7 14:40:06 2017 Gregoire Renard
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ftrace.h"

static int		set_elem(t_list **elem,
				 const size_t addr,
				 const char *name)
{
  if (((*elem)->name = strdup(name)) == NULL)
    return (ERROR);
  (*elem)->addr = addr;
  (*elem)->next = NULL;
  (*elem)->prev = NULL;
  return (SUCCESS);
}

int			add_elem(t_list **list,
				 const char *name,
				 const size_t addr)
{
  t_list		*tmp;
  t_list		*elem;

  tmp = (*list);
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (ERROR);
  if ((set_elem(&elem, addr, name)) == ERROR)
    return (ERROR);
  if (*list == NULL)
    *list = elem;
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
      elem->prev = tmp;
    }
  return (SUCCESS);
}
