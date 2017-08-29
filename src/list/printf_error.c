/*
** pintf_error.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_ftrace/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Apr 20 17:07:25 2017 Gregoire Renard
** Last update Fri May  5 01:37:55 2017 Jean-Adrien Domage
*/

#include <stdio.h>
#include "ftrace.h"

int			printf_error(const char *error)
{
  printf("%s\n", error);
  return (ERROR);
}
