#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 13:57:53 by jwoodrow          #+#    #+#              #
#    Updated: 2014/03/27 12:34:08 by jwoodrow         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 42sh
LIBNAME = string list readline lexer parser exec
C = \033[0;36m
CFLAGS = -g3 -Wall -Werror -Wextra
SRCPATH = srcs
OBJPATH = obj
INCLUDE = ./include

SRCS = main.c\
	   main_b.c

V = 0
SILENCE_1 :=
SILENCE_0 :=@
SILENCE = $(SILENCE_$(V))
LNAME = $(addprefix lib, $(LIBNAME))
CLNAME = $(addprefix -l, $(LIBNAME)) -ltermcap
LIB = $(addprefix -L, $(addsuffix /, $(LNAME))) $(CLNAME) -L/usr/lib
LINCLUDE =
CC = $(SILENCE)gcc
RM = $(SILENCE)rm -rf
MAKE = $(SILENCE)make V=$(V)
INCLUDES = -I $(INCLUDE) $(addprefix -I, $(LINCLUDE))
SRC = $(addprefix $(SRCPATH)/, $(SRCS))
OBJS= $(SRCS:.c=.o)
SKIP_1 :=
SKIP_0 := \033[A
SKIP = $(SKIP_$(V))
U = $(C)[$(NAME)]----->\033[0m
OBJDIR = $(addprefix $(OBJPATH)/, $(OBJS))

all: createdir $(LIBNAME) $(NAME)

$(NAME): $(OBJDIR)
	@echo "$(U)$(C)[COMPILE:\033[1;32m DONE$(C)]\033[0m"
	@echo "$(U)$(C)[BUILD]\033[0;32m"
	$(CC) -o $(NAME) $(OBJDIR) $(CFLAGS) $(INCLUDES) $(LIB)
	@echo "$(SKIP)\033[2K"
	@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m"

$(OBJPATH)/%.o: srcs/%.c
	@echo "$(U)$(C)[COMPILE: \033[1;31m$<\033[A\033[0m"
	@echo "\033[0;32m"
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<
	@echo "\033[1;31m [.working.]"
	@echo "$(SKIP)\033[2K\033[A\033[2K$(SKIP)"

clean: libstringclean liblistclean liblexerclean libparserclean libreadlineclean libexecclean
	@echo "$(U)$(C)[CLEAN]\033[0;32m"
	$(RM) $(OBJPATH)
	@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"

fclean: clean libstringfclean liblistfclean liblexerfclean libparserfclean libreadlinefclean libexecfclean
	@echo "$(U)$(C)[F-CLEAN]\033[0;32m"
	$(RM) $(NAME)
	@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

createdir:
	@mkdir -p $(OBJPATH)

$(LIBNAME):
	$(MAKE) -C $(addprefix lib, $@) all

libstringclean:
	$(MAKE) -C libstring clean

liblistclean:
	$(MAKE) -C liblist clean

libexecclean:
	$(MAKE) -C libexec clean

libreadlineclean:
	$(MAKE) -C libreadline clean

liblexerclean:
	$(MAKE) -C liblexer clean

libparserclean:
	$(MAKE) -C libparser clean

libstringfclean:
	$(MAKE) -C libstring fclean

liblistfclean:
	$(MAKE) -C liblist fclean

libexecfclean:
	$(MAKE) -C libexec fclean

libreadlinefclean:
	$(MAKE) -C libreadline fclean

liblexerfclean:
	$(MAKE) -C liblexer fclean

libparserfclean:
	$(MAKE) -C libparser fclean

re: fclean all

.PHONY: clean fclean createdir all re libstringclean libstringfclean\
	liblistclean liblistfclean libexecclean libexecfclean libparserclean\
	libparserfclean liblexerclean liblexerfclean libreadlineclean\
	libreadlinefclean
