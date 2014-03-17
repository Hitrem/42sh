# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/01 18:50:57 by raudiber          #+#    #+#              #
#    Updated: 2014/03/17 21:22:48 by raudiber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh
LIBFT = libft.a
LIBFT_PATH = libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(HEADERS) -g
HEADERS = -Iincludes -Ilibft/includes

LDFLAGS = -L$(LIBFT_PATH) -lft

PATH_INC = -Iincludes -Ilibft/includes
PATH_SRC = ./srcs/

SRC = ft_cd.c \
		ft_chardele.c \
		ft_env.c \
		ft_get_info.c \
		ft_is_spe_char.c \
		ft_keyboard.c \
		ft_lexer.c \
		ft_linechange.c \
		ft_setenv.c \
		ft_signal. c \
		main.c \
		search_cmd.c \

SRCS = $(addprefix $(PATH_SRC), $(SRC))
OBJS = $(addprefix $(PATH_SRC), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(PATH_SRC)%.o: $(PATH_SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(LIBFT_PATH)/$(LIBFT)

re: fclean all

.PHONY: clean fclean re
