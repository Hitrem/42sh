# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 13:50:38 by raudiber          #+#    #+#              #
#    Updated: 2014/03/17 21:17:51 by raudiber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -I$(PATH_INC)
CC = gcc

PATH_INC = includes/
PATH_SRC = srcs/

SRC =ft_abs.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_charjoin.c \
	ft_intlen.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memset.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_printf.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putmem.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr2.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdup.c \
	ft_strdel.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strsub.c \
	ft_strstr.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstaddend.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_tablen.c \
	ft_tabnew.c \
	ft_tabadd.c \
	ft_tabdel.c \
	ft_tabdub.c \
	get_next_line.c \

OBJS = $(addprefix $(PATH_SRC), $(SRC:.c=.o))
SRCS = $(addprefix $(PATH_SRC), $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@ranlib $@

$(PATH_SRC)%.o: $(PATH_SRC)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
