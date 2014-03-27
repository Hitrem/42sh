/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/26 21:41:09 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include "exec.h"
#include "parser.h"

static void		exit_safe(int *new)
{
	free_lists();
	free_shopt();
	free_variables();
	free(g_pid_loop);
	close(new[0]);
	exit(new[1]);
}

static void		close_useless(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

static void		father(int *fd, pid_t *pid, int status)
{
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[1], &status, 0);
	waitpid(pid[0], &status, 0);
	g_pid_loop->return_value = WEXITSTATUS(status);
}

static void		ft_pid_zero(t_ast *ast, int fd[2], int new[1])
{
	new[0] = dup2(fd[0], 0);
	close_useless(fd);
	if (ast->brother && ast->brother->brother)
		new[1] = type_node(ast->brother->brother);
	exit_safe(new);
}

int				my_pipe(t_ast *ast)
{
	pid_t	pid[2];
	int		fd[2];
	int		status;
	int		new[2];

	status = 0;
	set_pipe(fd);
	if ((pid[0] = set_fork()) == 0)
		ft_pid_zero(ast, fd, new);
	else if ((pid[1] = set_fork()) == 0)
	{
		new[0] = dup2(fd[1], 1);
		close_useless(fd);
		new[1] = type_node(ast);
		exit_safe(new);
	}
	else
		father(fd, pid, status);
	if (ast->brother && ast->brother->brother && ast->brother->brother->brother)
		type_node(ast->brother->brother->brother);
	return (g_pid_loop->return_value);
}
