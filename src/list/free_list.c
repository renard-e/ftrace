/*
** free_list.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_ftrace/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Apr 20 16:43:32 2017 Gregoire Renard
** Last update Fri May  5 01:37:10 2017 Jean-Adrien Domage
*/

#include <stdlib.h>
#include "ftrace.h"

void			free_list(t_list *list)
{
  t_list		*tmp;

  while (list != NULL)
    {
      tmp = list;
      list = list->next;
      free(tmp->name);
      free(tmp);
    }
}
