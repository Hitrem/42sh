/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 05:36:57 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "source.h"
#include "export.h"
#include "shopt.h"
#include "readline.h"

int call_builtin(t_ast *node, char *cmd)
{
	if (strcmp(cmd, "echo") == 0)
		return (ft_echo(node));
	else if (strcmp(cmd, "alias") == 0)
	{
		g_alias = alias(node);
		return (g_pid_loop->return_value);
	}
	else if (strcmp(cmd, "unalias") == 0)
	{
		g_alias = unalias(node);
		return (g_pid_loop->return_value);
	}
	else if (strcmp(cmd, "exit") == 0)
		return (my_exit(node));
	else if (strcmp(cmd, "shopt") == 0)
		return (my_shopt(node));
	else if (strcmp(cmd, "cd") == 0)
		return (my_cd(node));
	else if (strcmp(cmd, "export") == 0)
		return (my_export(node));
	else if (strcmp(cmd, "source") == 0)
		return (my_source(node));
	node->return_value = 0;
	g_pid_loop->return_value = 0;
	return (0);
}
