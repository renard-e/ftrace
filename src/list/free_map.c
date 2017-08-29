/*
** free_map.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_ftrace
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed May  3 16:30:56 2017 Gregoire Renard
** Last update Fri May  5 01:36:07 2017 Jean-Adrien Domage
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftrace.h"

void			free_map(char **map)
{
  int			cpt;

  cpt = 0;
  while (map[cpt] != NULL)
    {
      free(map[cpt]);
      cpt++;
    }
  free(map);
}
