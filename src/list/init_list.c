/*
** init_list.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_ftrace/src/list
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Apr 20 15:17:19 2017 Gregoire Renard
** Last update Fri May  5 23:20:23 2017 Jean-Adrien Domage
*/

#include <stdio.h>
#include <stdlib.h>
#include <libelf.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <gelf.h>
#include <stdint.h>
#include "ftrace.h"

static int		add_func(t_list **list, size_t addr,
				 char *name)
{
  if (addr == 0)
    return (SUCCESS);
  if ((add_elem(list, name, addr)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

static int		fill_list(t_list **list, Elf_Scn *scn,
				  Elf *elf, GElf_Shdr shdr)
{
  Elf_Data		*data;
  size_t		size;
  Elf64_Sym		*sym;
  size_t		cpt;

  cpt = 0;
  if ((data = elf_getdata(scn, NULL)) == NULL)
    return (ERROR);
  if ((size = shdr.sh_size / shdr.sh_entsize) == 0)
    return (ERROR);
  if ((sym = (Elf64_Sym *)data->d_buf) == NULL)
    return (ERROR);
  while (cpt < size)
    {
      if ((ELF64_ST_TYPE(sym[cpt].st_info)) == STT_NOTYPE
	  || ELF64_ST_TYPE(sym[cpt].st_info) == STT_FUNC)
	if ((add_func(list, sym[cpt].st_value,
		      elf_strptr(elf, shdr.sh_link, sym[cpt].st_name)))
	    == ERROR)
	  return (ERROR);
      cpt++;
    }
  return (SUCCESS);
}

static int		find_and_fill(Elf *elf, t_list **list)
{
  size_t		shdridx;
  Elf_Scn		*scn;
  GElf_Shdr		shdr;
  char			*name;

  scn = NULL;
  if ((elf_getshdrstrndx(elf, &shdridx)) != 0)
    return (ERROR);
  while ((scn = elf_nextscn(elf, scn)) != NULL)
    {
      if ((gelf_getshdr(scn, &shdr)) != &shdr)
	return (ERROR);
      if ((name = elf_strptr(elf, shdridx, shdr.sh_name)) == NULL)
      	return (ERROR);
      if ((strcmp(name, SYMTAB)) == 0)
	if ((fill_list(list, scn, elf, shdr)) == ERROR)
	  return (ERROR);
    }
  return (SUCCESS);
}

static int		check_file(Elf **elf, const char *file,
				   int *fd)
{
  char			*new_file;

  if (file == NULL)
    return (ERROR);
  if ((elf_version(EV_CURRENT)) == EV_NONE)
    return (ERROR);
  if ((new_file = get_path_file(file)) == NULL)
    return (ERROR);
  if ((*fd = open(new_file, O_RDONLY)) < 0)
    return (ERROR);
  free(new_file);
  if ((*elf = elf_begin(*fd, ELF_C_READ, NULL)) == NULL)
    return (ERROR);
  if ((elf_kind(*elf)) != ELF_K_ELF)
    return (ERROR);
  return (SUCCESS);
}

t_list			*init_list(const char *file)
{
  t_list		*list;
  Elf			*elf;
  int			fd;

  list = NULL;
  elf = NULL;
  if ((check_file(&elf, file, &fd)) == ERROR)
    return (NULL);
  if ((find_and_fill(elf, &list)) == ERROR)
    return (NULL);
  if ((update_list_dyn_lib(&list, elf, fd)) == ERROR)
    return (NULL);
  elf_end(elf);
  close(fd);
  return (list);
}
