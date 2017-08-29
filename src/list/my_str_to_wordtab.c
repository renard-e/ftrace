/*
** my_str_to_wordtab.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_ftrace/src/list
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun May  7 20:04:14 2017 Gregoire Renard
** Last update Sun May  7 20:04:14 2017 Gregoire Renard
*/

#include <stdlib.h>
#include "ftrace.h"

static int		count_size(char *str)
{
  int			cpt;
  int			word;

  cpt = 0;
  word = 0;
  while (str[cpt] != '\0')
    {
      while (str[cpt] == ':' && str[cpt] != '\0')
	cpt++;
      while (str[cpt] != ':' && str[cpt] != '\0')
	cpt++;
      word++;
    }
  return (word);
}

static int		count_len_word(char *str, int cpt)
{
  int			dif;

  dif = 0;
  while (str[cpt] != ':' && str[cpt] != '\0')
    {
      dif++;
      cpt++;
    }
  return (dif);
}

static void		set_all(t_all *all, char *str)
{
  all->size = count_size(str);
  all->cpt = 0;
  all->y = 0;
}

char			**my_str_to_wordtab(char *str)
{
  t_all			all;

  set_all(&all, str);
  if ((all.map = malloc(sizeof(char *) * (all.size + 1))) == NULL)
    return (NULL);
  while (str[all.cpt] != '\0')
    {
      all.x = 0;
      while (str[all.cpt] == ':' && str[all.cpt] != '\0')
	all.cpt++;
      if ((all.map[all.y] = malloc(count_len_word(str, all.cpt) + 1)) == NULL)
	return (NULL);
      while (str[all.cpt] != ':' && str[all.cpt] != '\0')
	{
	  all.map[all.y][all.x] = str[all.cpt];
	  all.cpt++;
	  all.x++;
	}
      all.map[all.y][all.x] = '\0';
      all.y++;
    }
  all.map[all.y] = NULL;
  return (all.map);
}
