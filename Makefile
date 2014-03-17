#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pferry <pferry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 20:01:16 by pferry            #+#    #+#              #
#    Updated: 2014/03/05 17:18:37 by pferry           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=42sh
CC=gcc
OBJ=$(SRC:.c=.o)
CFLAGS=-Wall -Wextra -Werror -I.
LIB=-Llibft/ -lft -L /usr/lib -ltermcap
HEADER=shell.h
SRC=main.c \
	ft_cd.c \
	ft_env.c \
	ft_signal.c \
	ft_setenv.c \
	ft_get_info.c \
	ft_is_spe_char.c \
	ft_lexer.c \
	ft_keyboard.c \
	ft_chardelete.c \
	ft_linechange.c \
	search_cmd.c

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo -n Compiling...

$(LIB):
	@make -C libft/

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo -n Delete

fclean: clean
	@rm -rf $(NAME)

re: fclean all
