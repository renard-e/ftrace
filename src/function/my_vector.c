/*
** my_vector.c for ftrace in /home/jeanadrien/rendu/PROJECT/PSU_2016_ftrace/src/function
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May  5 05:39:46 2017 Jean-Adrien Domage
** Last update Fri May  5 07:02:41 2017 Jean-Adrien Domage
*/

#include <sys/types.h>
#include <stdlib.h>
#include "my_vector.h"

static void	vector_flush(t_vector *this)
{
  if (this->sp != NULL)
    free(this->sp);
}

static size_t	vector_pop(t_vector *this)
{
  size_t       	elem;
  size_t       	*new;
  int		idx;

  idx = 1;
  if (this->size == 0)
    return (-1);
  elem = this->sp[0];
  this->size -= 1;
  if (!(new = malloc(sizeof(char *) * this->size)))
    return (elem);
  while (idx <= this->size)
    {
      new[idx - 1] = this->sp[idx];
      idx += 1;
    }
  this->flush(this);
  this->sp = new;
  return (elem);
}

static int     vector_push(t_vector *this, size_t data)
{
  size_t	*new;
  int		idx;

  idx = 0;
  this->size += 1;
  if (!(new = malloc(sizeof(size_t) * this->size)))
    return (-1);
  new[0] = data;
  while (idx < this->size - 1)
    {
      new[idx + 1] = this->sp[idx];
      idx += 1;
    }
  this->flush(this);
  this->sp = new;
  return (this->size);
}

t_vector	*vector_ctor(void)
{
  t_vector	*new;

  if (!(new = malloc(sizeof(t_vector))))
    return (NULL);
  new->size = 0;
  if (!(new->sp = malloc(sizeof(size_t))))
      return (free(new), NULL);
  new->sp = NULL;
  new->push = vector_push;
  new->pop = vector_pop;
  new->flush = vector_flush;
  return (new);
}

void	vector_dtor(t_vector *vtor)
{
  vtor->flush(vtor);
  free(vtor);
}
