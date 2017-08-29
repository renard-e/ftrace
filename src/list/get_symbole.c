/*
** get_symbole.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_ftrace/src/list
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun Apr 30 11:36:46 2017 Gregoire Renard
** Last update Sun May  7 14:35:59 2017 Gregoire Renard
*/

#include "ftrace.h"

char			*get_symbole(const t_list *list, const size_t addr)
{
  while (list != NULL)
    {
      if (list->addr == addr)
	return (list->name);
      list = list->next;
    }
  return (NULL);
}
