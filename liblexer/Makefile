#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfanton <gfanton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:57:53 by gfanton           #+#    #+#              #
#    Updated: 2014/03/27 11:05:03 by jwoodrow         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NNAME = lexer
INCLUDE = ../include/
SRCPATH = srcs/
OBJPATH = obj
CFLAGS = -g3 -O3 -Wall -Werror -Wextra
C = \033[1;34m

SRCS = lexer.c\
	   lexer_builder.c\
	   lexer_builder_b.c\
	   lexer_printer.c\
	   lexer_quoting.c\
	   lexer_quoting_b.c\
	   lexer_recognition.c\
	   lexer_recognition_b.c\
	   lexer_separators.c\
	   lexer_tokenizer.c\
	   lexer_tokenizer_b.c\
	   lexer_types.c

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
