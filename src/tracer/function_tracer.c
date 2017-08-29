/*
** function_tracer.c for ftrace in /home/jeanadrien/rendu/PROJECT/PSU_2016_ftrace/src/tracer
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May  5 01:00:47 2017 Jean-Adrien Domage
** Last update Sun May  7 20:06:07 2017 Gregoire Renard
*/

#include <string.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include <sys/types.h>
#include "tracer.h"

static char	g_spec_char[7][3] = {
  "\\a",
  "\\b",
  "\\t",
  "\\n",
  "\\v",
  "\\f",
  "\\r"
};

void	print_char(char *str)
{
  int	idx;
  int	verif;

  idx = 0;
  printf("\"");
  while (str[idx] && idx < 40)
    {
      verif = str[idx];
      if (str[idx] == 0)
	printf("\\0");
      else if (str[idx] < 14 && str[idx] > 6)
	printf(g_spec_char[idx - 7]);
      else if (verif <= 6 || verif >= 127)
	printf("\\%d", str[idx]);
      else
	printf("%c", str[idx]);
      idx += 1;
    }
  if (idx == 41)
    printf("\"...");
  else
    printf("\"");
}

void     char_ptr(int idx, size_t *tab, pid_t pid)
{
  char          string[1024];
  char          *pointer;
  long          tmp;
  int           i;

  i = 0;
  pointer = string;
  string[0] = '0';
  string[1023] = '\0';
  if (tab[idx] == 0)
    {
      printf("NULL");
      return;
    }
  while ( i <= 41)
    {
      if ((tmp = ptrace(PTRACE_PEEKTEXT, pid,
			(tab[idx] + (i * 8)), NULL)) == -1)
        return;
      memcpy(pointer, &tmp, 8);
      i += 1;
      pointer += sizeof(long);
    }
  string[i] = '\0';
  print_char(string);
}
