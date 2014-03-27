/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:54:39 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 07:23:44 by jwoodrow         ###   ########.fr       */
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

void			fast_case(char *read_val, int g_current_pos, int g_max_pos)
{
	if (read_val[0] == 1)
		while (g_current_pos > 0)
			left();
	else if (read_val[0] == 5)
		while (g_current_pos < g_max_pos)
			right();
	else if (read_val[0] == 11)
		while (g_current_pos < g_max_pos)
			delete_char();
	else if (read_val[0] == 12)
		tputs(tgetstr("cl", NULL), 1, my_putchar);
}

static void		ft_func(char *tmp, int *len, int *it, int *once)
{
	*tmp = 'a';
	*len = 1;
	*it = 0;
	*once = 1;
}

int				readline(char **buff, char *filename, char eline)
{
	char	tmp;
	int		len;
	int		it;
	int		once;

	if (filename != NULL)
		*buff = readfile(filename, 0);
	else
	{
		ft_func(&tmp, &len, &it, &once);
		while (once || (len == 1 && tmp != 0))
		{
			once = 0;
			//
			if ((*buff = realloc(*buff, sizeof(char) * (it + 2))) == NULL)
				return (0);
			len = read(STDIN_FILENO, &tmp, 1);
			(*buff)[it++] = tmp;
		}
		(*buff)[it - 1] = 0;
		g_current_cmd->last = *buff;
		return (len > 0 || it > 1);
	}
	return (1);
	eline++;
}
