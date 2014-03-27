/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_less_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:41:25 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 06:06:38 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include "exec.h"
#include "redirection.h"
#include "prompts.h"

int				less_input(t_red *red)
{
	red->fd = open(red->word, O_RDONLY, 0644);
	if (red->fd == -1)
	{
		strerror(errno);
		return (-1);
	}
	red->old = dup(red->ionumber);
	dup2(red->fd, red->ionumber);
	red->error = -1;
	return (0);
}

int				heredoc(t_red *red)
{
	g_pid_loop->heredoc = 1;
	g_pid_loop->heredoc = 0;
	red->fd = 0;
	red->old = dup(red->ionumber);
	dup2(red->fd, red->ionumber);
	red->error = -1;
	return (0);
}

int				tab_heredoc(t_red *red)
{
	g_pid_loop->heredoc = 1;
	g_pid_loop->heredoc = 0;
	red->fd = 0;
	red->old = dup(red->ionumber);
	dup2(red->fd, red->ionumber);
	red->error = -1;
	return (0);
}

int				duplic_input(t_red *red)
{
	int fd;

	fd = atoi(red->word);
	dup2(fd, red->ionumber);
	red->error = atoi(red->word);
	if (fd == -1)
	{
		strerror(errno);
		return (-1);
	}
	return (0);
}

int				read_write(t_red *red)
{
	red->fd = open(red->word, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (red->fd == -1)
	{
		strerror(errno);
		return (-1);
	}
	red->old = dup(red->ionumber);
	dup2(red->fd, red->ionumber);
	red->error = -1;
	return (0);
}
