/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:15:59 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 05:20:03 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include "exec.h"
#include "shopt.h"
#include "readline.h"

int				check_builtin(char *cmd)
{
	if ((strcmp(cmd, "exit") == 0) || (strcmp(cmd, "cd") == 0)
			|| (strcmp(cmd, "shopt") == 0) || (strcmp(cmd, "export") == 0)
			|| (strcmp(cmd, "alias") == 0) || (strcmp(cmd, "unalias") == 0)
			|| (strcmp(cmd, "echo") == 0) || (strcmp(cmd, "continue") == 0)
			|| (strcmp(cmd, "break") == 0) || (strcmp(cmd, "source") == 0)
			|| (strcmp(cmd, "history") == 0))
		return (1);
	return (0);
}

int				check_redirection(t_ast *node)
{
	if (node == NULL)
		return (0);
	if (node->token->type >= RREDIR && node->token->type <= LESSGREAT)
		return (1);
	return (check_redirection(node->brother));
}

int				exec_cmd(t_ast *node)
{
	char *call_alias;

	if (find_alias(node->first_son->token->token, g_alias) == 1)
	{
		call_alias = value_alias(node->token->token, g_alias, 2);
		if (check_builtin(call_alias) == 1)
			return (call_builtin(node->first_son, call_alias));
		if (find_funct(node->first_son->token->token, g_funct) == 1)
			return (execute_funct(node->first_son->token->token));
	}
	if (check_redirection(node->first_son) == 1)
		return (list_redirection(node));
	if (check_builtin(node->first_son->token->token) == 1)
		return (call_builtin(node->first_son, node->first_son->token->token));
	if (find_funct(node->first_son->token->token, g_funct) == 1)
		return (execute_funct(node->first_son->token->token));
	return (fork_and_execute(node));
}
