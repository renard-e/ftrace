/*
** get_path_file.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_ftrace
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed May  3 16:00:24 2017 Gregoire Renard
** Last update Sun May  7 20:03:44 2017 Gregoire Renard
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "ftrace.h"

static char		**get_all_path()
{
  char			*path;
  char			**all_path;

  if ((path = getenv("PATH")) == NULL)
    return (NULL);
  if ((all_path = my_str_to_wordtab(path)) == NULL)
    return (NULL);
  return (all_path);
}

static char		*first_test(const char *file)
{
  char			*tmp;

  if ((tmp = malloc(strlen(file) + 3)) == NULL)
    return (NULL);
  if ((strcpy(tmp, "./")) == NULL)
    return (NULL);
  if ((strcat(tmp, file)) == NULL)
    return (NULL);
  if ((access(tmp, R_OK)) == -1)
    return (NULL);
  return (tmp);
}

static char		*check_all_path(const char *file,
					char **all_path)
{
  char			*tmp;
  int			cpt;

  cpt = 0;
  tmp = NULL;
  while (all_path[cpt] != NULL)
    {
      if ((tmp = malloc(strlen(all_path[cpt])
			+ strlen(file) + 4)) == NULL)
	return (NULL);
      if ((strcat(tmp, all_path[cpt])) == NULL)
	return (NULL);
      if ((strcat(tmp, "/")) == NULL)
	return (NULL);
      if ((strcat(tmp, file)) == NULL)
	return (NULL);
      if ((access(tmp, R_OK)) != -1)
	return (tmp);
      free(tmp);
      cpt++;
    }
  return (NULL);
}

char			*get_path_file(const char *file)
{
  char			**all_path;
  char			*tmp;

  if ((tmp = first_test(file)) != NULL)
    return (tmp);
  if ((all_path = get_all_path()) == NULL)
    return (NULL);
  if ((tmp = check_all_path(file, all_path)) == NULL)
    return (NULL);
  free_map(all_path);
  return (tmp);
}
