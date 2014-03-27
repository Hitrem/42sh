/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:59:14 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 07:39:21 by raudiber         ###   ########.fr       */
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

static int		ft_func(char **buff, int *it, char *filename, int *fd)
{
	*buff = NULL;
	*it = 0;
	*fd = open(filename, O_RDONLY);
	return (1);
}

char			*readfile(char *filename, int exist)
{
	int		fd;
	int		len;
	char	*buff;
	int		it;
	int		once;

	once = ft_func(&buff, &it, filename, &fd);
	if (fd == -1)
	{
		//
		if (!exist)
			printf("42sh: readfile: %s: %s\n", filename, strerror(errno));
		return (NULL);
	}
	while (once || len == 256)
	{
		once = 0;
		//
		if ((buff = realloc(buff, sizeof(char) * 256 * (it + 1)))
		== NULL)
			return (NULL);
		len = read(fd, buff + (sizeof(char) * 256 * it), 256);
		it++;
	}
	buff[(sizeof(char) * 256 * (it - 1)) + len] = 0;
	close(fd);
	return (buff);
}

static void		ft_init(int *ret, int *len, char **tmp, int *i)
{
	*ret = 1;
	*len = 1;
	reset_term();
	*tmp = (char*)malloc(4);
	*i = 0;
}

int				readline2(char **buff, char *filename, char eline)
{
	int		i;
	int		ret;
	int		len;
	char	*tmp;

	if (filename != NULL)
		g_current_cmd->last = readfile(filename, 0);
	else if (!g_pid_loop->is_in_loop && !g_pid_loop->heredoc)
		return (readline(buff, filename, eline));
	else
	{
		*buff = g_term_buffer;
		ft_init(&ret, &len, &tmp, &i);
		while (i < 4)
			tmp[i++] = 0;
		while (len && ret && ret != -1)
		{
			len = read(STDIN_FILENO, tmp, 4);
			ret = restore_term(0, 0, tmp, len);
			g_current_cmd->last = *buff;
		}
		free(tmp);
		return (len > 0 && ret);
	}
	return (1);
}
