##
## Makefile for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_ftrace
## 
## Made by Gregoire Renard
## Login   <renard_e@epitech.net>
## 
## Started on  Tue Apr 18 15:18:28 2017 Gregoire Renard
## Last update Sun May  7 20:23:42 2017 Gregoire Renard
##

NAME	=	ftrace

RM	=	rm -f

CC	=	gcc -Iinclude/

LDFLAGS	=	-W -Werror -Wall -lelf

SRC	=	main.c\
		src/parser/parser.c\
		src/parser/function_parser.c\
		src/launcher/launcher.c\
		src/tracer/trace_parser.c\
		src/tracer/tracer.c\
		src/tracer/function_tracer.c\
		src/function/execve.c \
		src/function/my_vector.c\
		src/list/init_list.c \
		src/list/add_elem.c \
		src/list/print_list.c \
		src/list/free_list.c \
		src/list/printf_error.c \
		src/list/update_list_dyn_lib.c \
		src/list/get_symbole.c \
		src/list/get_path_file.c \
		src/list/my_str_to_wordtab.c \
		src/list/print_map.c \
		src/list/free_map.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)	
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.c.o:
	$(CC) $(LDFLAGS) -c $< -o $@ 

.PHONY:	all clean fclean re
