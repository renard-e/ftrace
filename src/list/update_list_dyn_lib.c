/*
** update_list_dyn_lib.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_ftrace/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Apr 21 17:49:05 2017 Gregoire Renard
** Last update Sun May  7 14:42:08 2017 Gregoire Renard
*/

#include <stdio.h>
#include <stdlib.h>
#include <libelf.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <gelf.h>
#include <stdint.h>
#include "ftrace.h"

static int		get_tab_dyn(Elf64_Sym **dyn_tab,
				    char **str_dyn_tab,
				    Elf *elf)
{
  Elf_Data		*data;
  Elf_Scn		*scn;
  GElf_Shdr		shdr;

  scn = NULL;
  while ((scn = elf_nextscn(elf, scn)) != NULL)
    {
      if ((gelf_getshdr(scn, &shdr)) != &shdr)
	return (ERROR);
      if (shdr.sh_type == SHT_DYNSYM ||
	  (shdr.sh_flags == SHF_ALLOC && shdr.sh_type == SHT_STRTAB))
	{
	  if ((data = elf_getdata(scn, NULL)) == NULL)
	    return (ERROR);
	  if (shdr.sh_type == SHT_STRTAB)
	    *str_dyn_tab = (char *)data->d_buf;
	  else
	    *dyn_tab = (Elf64_Sym *)data->d_buf;
	}
    }
  if (*dyn_tab == NULL)
    return (UNDEFINED);
  return (SUCCESS);
}

static int		create_new_elem(t_all_type *all,
					t_list **list,
					int fd,
					int cpt)
{
  long unsigned int	addr;
  char			*name;

  if ((read(fd, &addr, 8)) == -1)
    return (ERROR);
  if ((name = DYN_NAME) == NULL)
    return (ERROR);
  if ((add_elem(list, name, (size_t)addr - 0x6)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

static int		push_fct_dyn(t_all_type *all,
				     t_list **list,
				     int fd)
{
  size_t		size;
  size_t		cpt;

  cpt = 0;
  if ((all->data = elf_getdata(all->scn, NULL)) == NULL)
    return (ERROR);
  if ((size = all->shdr.sh_size / all->shdr.sh_entsize) == 0)
    return (ERROR);
  if ((all->dyn = (Elf64_Rela *)all->data->d_buf) == NULL)
    return (ERROR);
  while (cpt < size)
    {
      if ((ELF64_R_SYM(all->dyn[cpt].r_info)) != STN_UNDEF
	  && (ELF64_R_TYPE(all->dyn[cpt].r_info)) == R_386_JMP_SLOT)
	{
	  if ((lseek(fd, all->dyn[cpt].r_offset - 6291456,
		     SEEK_SET)) == (off_t)-1)
	    return (ERROR);
	  if ((create_new_elem(all, list, fd, cpt)) == ERROR)
	    return (ERROR);
	}
      cpt++;
    }
  return (SUCCESS);
}

static int		new_add(t_all_type *all,
				t_list **list,
				int fd)
{
  all->scn = NULL;
  while ((all->scn = elf_nextscn(all->elf, all->scn)) != NULL)
    {
      if ((gelf_getshdr(all->scn, &all->shdr)) != &all->shdr)
	return (ERROR);
      if (all->shdr.sh_type == SHT_RELA)
	if ((push_fct_dyn(all, list, fd)) == ERROR)
	  return (ERROR);
    }
  return (SUCCESS);
}

int			update_list_dyn_lib(t_list **list,
					    Elf *elf,
					    int fd)
{
  Elf64_Sym		*dyn_tab;
  char			*str_dyn_tab;
  int			state;
  t_all_type		all;

  dyn_tab = NULL;
  str_dyn_tab = NULL;
  if ((state = get_tab_dyn(&dyn_tab, &str_dyn_tab, elf)) == ERROR)
    return (ERROR);
  if (state == UNDEFINED)
    return (SUCCESS);
  all.dyn_tab = dyn_tab;
  all.str_dyn_tab = str_dyn_tab;
  all.elf = elf;
  if ((new_add(&all, list, fd)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
