#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfanton <gfanton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:57:53 by gfanton           #+#    #+#              #
#    Updated: 2014/03/27 12:19:09 by jwoodrow         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NNAME = exec
INCLUDE = ../include/
SRCPATH = srcs/
OBJPATH = obj
CFLAGS = -g -Wall -Werror -Wextra
C = \033[1;34m

SRCS = alias.c\
	   alias_b.c\
	   and_or.c\
	   builtin.c\
	   cd.c\
	   cmd.c\
	   cmd_b.c\
	   echo_backslash.c\
	   echo_backslash_b.c\
	   echo_backslash_c.c\
	   exec.c\
	   exit.c\
	   export.c\
	   for.c\
	   ft_echo.c\
	   ft_echo_b.c\
	   free.c\
	   function.c\
	   generic_func.c\
	   if.c\
	   init_redirection.c\
	   init_redirection_b.c\
	   init_redirection_c.c\
	   pipe.c\
	   redir_great.c\
	   redir_less.c\
	   redir_less_b.c\
	   redirection.c\
	   redirection_b.c\
	   redirection_c.c\
	   redirection_d.c\
	   shopt.c\
	   shopt_b.c\
	   shopt_c.c\
	   shopt_init.c\
	   shopt_print.c\
	   source.c\
	   unalias.c\
	   unalias_b.c\
	   variables.c\
	   variables_b.c\
	   while_until.c \

NAME = lib$(NNAME).a
CLNAME = l$(NNAME)
V = 0
SILENCE_1 :=
SILENCE_0 :=@
SILENCE = $(SILENCE_$(V))
CC = $(SILENCE)gcc
LIB = $(SILENCE)ar rc
RM = $(SILENCE)rm -rf
SRC = $(addprefix $(SRCPATH), $(SRCS))
OBJS= $(SRCS:.c=.o)
SKIP_1 :=
SKIP_0 := \033[A
SKIP = $(SKIP_$(V))
U = $(C)[$(NAME)]----->\033[0m
OBJDIR = $(addprefix $(OBJPATH)/, $(OBJS))

all: createdir $(NAME)

$(NAME): $(OBJDIR)
	@echo "$(U)$(C)[COMPILE:\033[1;32m DONE$(C)]\033[0m"
	@echo "$(U)$(C)[BUILD LIB]\033[0;32m"
	$(LIB) $(NAME) $(OBJDIR)
	@ranlib $(NAME)
	@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m"

$(OBJPATH)/%.o: srcs/%.c
	@echo "$(U)$(C)[COMPILE: \033[1;31m$<\033[A\033[0m"
	@echo "\033[0;32m"
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<
	@echo "\033[1;31m [.working.]"
	@echo "$(SKIP)\033[A\033[2K$(SKIP)"

clean:
	@echo "$(U)$(C)[CLEAN]\033[0;32m"
	$(RM) $(OBJPATH)
	@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"

fclean: clean
	@echo "$(U)$(C)[F-CLEAN]\033[0;32m"
	$(RM) $(NAME)
	@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

re: fclean all

createdir:
	$(shell if [ ! -d "$(OBJPATH)" ]; then mkdir -p $(OBJPATH); fi)

.PHONY: clean fclean createdir all
