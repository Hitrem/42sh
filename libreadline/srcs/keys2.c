/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-segu <sde-segu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:50:14 by sde-segu          #+#    #+#             */
/*   Updated: 2014/03/27 05:40:08 by jwoodrow         ###   ########.fr       */
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

int			part_case(char *read_val)
{
	if (read_val[1] == '[')
	{
		if (read_val[2] == 'A')
			write(STDOUT_FILENO, "", 0);
		else if (read_val[2] == 'B')
			write(STDOUT_FILENO, "", 0);
		else if (read_val[2] == 'C')
			right();
		else if (read_val[2] == 'D')
			left();
		else if (read_val[2] == '3')
			delete_char();
		else
			tputs(tgetstr("cb", NULL), 1, my_putchar);
	}
	return (1);
}

int			return_line(char *read_val, int len)
{
	while (g_current_pos < g_max_pos)
	{
		tputs(tgetstr("nd", NULL), 1, my_putchar);
		g_current_pos++;
	}
	write(STDOUT_FILENO, read_val, len - 1);
	write(STDOUT_FILENO, "\n", 1);
	g_term_buffer[g_current_pos] = 0;
	return (-1);
}

int			kill_proc(void)
{
	char	read_val;

	if (g_pid_loop->pid != 0)
	{
		kill(g_pid_loop->pid, 15);
		g_pid_loop->pid = 0;
	}
	write(STDOUT_FILENO, "^C", 2);
	read_val = '\n';
	return (return_line(&read_val, 1));
}

void		signal_handler(int sig)
{
	sig++;
	kill_proc();
}
