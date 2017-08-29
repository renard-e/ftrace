/*
** print_map.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_ftrace
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed May  3 16:28:58 2017 Gregoire Renard
** Last update Fri May  5 01:38:11 2017 Jean-Adrien Domage
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftrace.h"

void			print_map(char **map)
{
  int			cpt;

  cpt = 0;
  while (map[cpt] != NULL)
    {
      printf("%s\n", map[cpt]);
      cpt++;
    }
}
