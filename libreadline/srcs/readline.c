/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:51:48 by sde-segu          #+#    #+#             */
/*   Updated: 2014/03/27 07:39:14 by raudiber         ###   ########.fr       */
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
#include <string.h>
#include <errno.h>
#include "readline.h"
#include "exec.h"

static t_termdata		g_term_data;
char					g_term_buffer[2048];
int						g_current_pos = 0;
int						g_max_pos = 0;

int				restore_term(int tty, int choice, char *read_val, int len)
{
	if (choice && tty)
		tcsetattr(STDIN_FILENO, TCSANOW, &g_term_data.saved_attr);
	else if (!choice)
	{
		if (read_val[0] == 127 || read_val[0] == 8)
		{
			if (g_max_pos > 0)
			{
				tputs(tgetstr("le", NULL), 1, my_putchar);
				g_current_pos--;
				delete_char();
			}
		}
		else if (read_val[0] == 27)
			return (part_case(read_val));
		else if (read_val[0] == '\n' || read_val[0] == '\r')
			return (return_line(read_val, len));
		else if (read_val[0] < 27)
			return (part_case2(read_val));
		else
			add_char(read_val, len);
		return (1);
	}
	return (0);
}

int				part_case2(char *read_val)
{
	if (read_val[0] == 16)
		write(STDOUT_FILENO, "", 0);
	else if (read_val[0] == 14)
		write(STDOUT_FILENO, "", 0);
	else if (read_val[0] == 6)
		right();
	else if (read_val[0] == 2)
		left();
	else if (read_val[0] == 4)
	{
		if (g_max_pos > 0)
			delete_char();
		else
		{
			write(0, "\n", 1);
			return (0);
		}
	}
	else if (*read_val == 1 || *read_val == 5
		|| *read_val == 11 || *read_val == 12)
		fast_case(read_val, g_current_pos, g_max_pos);
	return (1);
}

void			init_term(void)
{
	struct termios attr;

	tcgetattr(STDIN_FILENO, &attr);
	g_term_data.saved_attr = attr;
	if (isatty(fileno(stdin)))
	{
		g_pid_loop->is_in_loop = 1;
		attr.c_lflag &= ~(ICANON | ECHO);
	}
	else
		g_pid_loop->is_in_loop = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &attr);
	init_terminal_data();
	signal(SIGINT, signal_handler);
	g_pid_loop->heredoc = 0;
}

void			init_terminal_data(void)
{
	int success;

	g_term_data.termtype = getenv("TERM");
	if (g_term_data.termtype == 0)
		write(STDOUT_FILENO, "Specify a terminal type with "
			"`setenv TERM <yourtype>'.\n", 55);
	success = tgetent(g_term_buffer, g_term_data.termtype);
	if (success < 0)
		write(STDERR_FILENO, "Could not access the termcap data base.\n", 40);
}

void			reset_term(void)
{
	int			i;

	i = 0;
	while (i < 2048)
	{
		g_term_buffer[i] = 0;
		i++;
	}
	g_current_pos = 0;
	g_max_pos = 0;
}
