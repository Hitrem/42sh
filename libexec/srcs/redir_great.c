/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_great.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 21:41:46 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 02:50:05 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include "exec.h"
#include "redirection.h"

static int		great_output(t_red *red)
{
	int		dp;

	red->fd = open(red->word, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (red->fd == -1)
	{
		strerror(errno);
		return (-1);
	}
	red->old = dup(red->ionumber);
	dp = dup2(red->fd, red->ionumber);
	if (dp == -1 || red->old == -1)
		write(2, "42sh: dup2 failed\n", 18);
	red->error = -1;
	return (0);
}

static int		app_output(t_red *red)
{
	red->fd = open(red->word,
			O_APPEND | O_WRONLY | O_CREAT, 0644);
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

static int		duplic_output(t_red *red)
{
	red->fd = atoi(red->word);
	if (red->fd == -1)
	{
		strerror(errno);
		return (-1);
	}
	red->old = dup(red->ionumber);
	dup2(red->fd, red->ionumber);
	red->error = dup(2);
	dup2(red->fd, 2);
	return (0);
}

int				redir_great(t_red *red)
{
	if (red->type == RREDIR || red->type == CLOBBER)
		return (great_output(red));
	else if (red->type == DGREAT)
		return (app_output(red));
	else if (red->type == GREATAND)
		return (duplic_output(red));
	else
		return (redir_less(red));
	return (0);
}
