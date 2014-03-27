/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-segu <sde-segu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:49:46 by sde-segu          #+#    #+#             */
/*   Updated: 2014/03/27 10:52:41 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ncurses.h>
#include <termcap.h>
#include <term.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include "readline.h"
#include "exec.h"

int				my_putchar(int ch)
{
	char c;

	c = ch;
	return (write(STDOUT_FILENO, &c, 1));
}

int				add_char(char *str, int lent)
{
	int			i;
	size_t		len;
	size_t		j;
	int			ret;

	len = g_max_pos - g_current_pos;
	//
	if (len)
		memmove(g_term_buffer + sizeof(char) * (g_current_pos + lent),\
				g_term_buffer + sizeof(char) * g_current_pos,\
					len);
	i = 0;
	while (i < lent)
	{
		g_term_buffer[g_current_pos + i] = str[i];
		i++;
	}
	ret = write(STDOUT_FILENO, g_term_buffer + g_current_pos, len + lent);
	j = 0;
	while (j++ < len)
		tputs(tgetstr("le", NULL), 1, my_putchar);
	g_max_pos += lent;
	g_current_pos += lent;
	return (ret);
}

void			delete_char(void)
{
	size_t		i;
	size_t		len;

	len = g_max_pos - g_current_pos - 1;
	if (g_current_pos < g_max_pos)
	{
		//
		memmove(g_term_buffer + sizeof(char) * g_current_pos,
			g_term_buffer + sizeof(char) * (g_current_pos + 1),
			len);
		write(STDOUT_FILENO, g_term_buffer + g_current_pos, len);
		write(STDOUT_FILENO, " ", 1);
		i = 0;
		while (i <= len)
		{
			tputs(tgetstr("le", NULL), 1, my_putchar);
			i++;
		}
		g_max_pos--;
	}
}

void			left(void)
{
	if (g_current_pos > 0)
	{
		tputs(tgetstr("le", NULL), 1, my_putchar);
		g_current_pos--;
	}
}

void			right(void)
{
	if (g_current_pos < g_max_pos)
	{
		tputs(tgetstr("nd", NULL), 1, my_putchar);
		g_current_pos++;
	}
}
