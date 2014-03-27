/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 05:19:30 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include "exec.h"
#include "shopt.h"
#include "readline.h"

char		*use_variable(char *variable)
{
	char	*tmp;

	tmp = find_var(variable, g_var);
	return (tmp);
}

char		**command_center(t_ast *node)
{
	char	**cmd;
	int		i;
	t_ast	*tmp;

	cmd = malloc(sizeof(char*));
	cmd[0] = node->token->token;
	i = 1;
	while (node->brother)
	{
		cmd = realloc(cmd, sizeof(char*) * (i + 2));
		if (node->brother->token->type == VARIABLE)
			cmd[i] = use_variable(node->brother->token->token);
		else
			cmd[i] = node->brother->token->token;
		tmp = node->brother->brother;
		free(node->brother);
		node->brother = tmp;
		i++;
	}
	cmd = realloc(cmd, sizeof(char*) * (i + 1));
	cmd[i] = NULL;
	return (cmd);
}

int			execution(t_ast *node)
{
	char	**cmd;

	cmd = command_center(node);
	if (execvp(cmd[0], cmd) == -1)
	{
		g_pid_loop->return_value = 127;
		fprintf(stderr, "42sh: command not found: %s\n", cmd[0]);
		exit(127);
	}
	return (g_pid_loop->return_value);
}

int			status_change(t_ast *node, int status)
{
	if (status > 512)
	{
		node->return_value = 127;
		g_pid_loop->return_value = 127;
	}
	else
	{
		node->return_value = 1;
		g_pid_loop->return_value = 1;
	}
	return (g_pid_loop->return_value);
}

int			fork_and_execute(t_ast *node)
{
	int	status;

	status = 0;
	g_pid_loop->pid = fork();
	if (g_pid_loop->pid == 0)
		execution(node->first_son);
	else
	{
		waitpid(g_pid_loop->pid, &status, 0);
		node->return_value = status;
		if (g_pid_loop->return_value != 127)
			g_pid_loop->return_value = status;
	}
	if (status != 0)
		g_pid_loop->return_value = status_change(node, status);
	if (g_pid_loop->bang == 1)
	{
		g_pid_loop->bang = 0;
		if (g_pid_loop->return_value == 0)
			g_pid_loop->return_value = 1;
		else if (g_pid_loop->return_value != -1)
			g_pid_loop->return_value = 0;
	}
	return (g_pid_loop->return_value);
}
