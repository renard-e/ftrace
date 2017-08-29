/*
** my_vector.h for ftrace in /home/jeanadrien/rendu/PROJECT/PSU_2016_ftrace/include
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May  5 05:40:54 2017 Jean-Adrien Domage
** Last update Fri May  5 06:55:08 2017 Jean-Adrien Domage
*/

#ifndef MY_VECTOR_H_
# define MY_VECTOR_H_

/*
**  t_vector is a C modular object that allow you to manipulate
**  LIFO stack based on size_t.
**
**  Push allow you to add an elem
**  Pop allow your to remove an elem
**  Flush allow you to empty the vector stack
**  !Flush! Do not use flush before calling dtor, you'll have a double free.
*/

typedef struct	s_vector
{
  int		size;
  size_t	*sp;
  int		(*push)(struct s_vector *, size_t);
  size_t	(*pop)(struct s_vector *);
  void		(*flush)(struct s_vector *);
}		t_vector;

t_vector	*vector_ctor();
void		vector_dtor(t_vector *vtor);

#endif /* !MY_VECTOR_H_ */
