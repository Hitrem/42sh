/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 05:27:56 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	every_commands(t_ast *tmp, int ret)
{
	while (tmp)
	{
		if (tmp->token->type == AND_IF)
			and_exec(tmp);
		else if (tmp->token->type == OR_IF)
			or_exec(tmp);
		else if (tmp->token->type == ASSIGNMENT)
			g_var = new_var(tmp);
		else if (tmp->token->type == FUNCTION)
			g_funct = new_funct(tmp);
		else
			type_node(tmp);
		if (tmp->token->type == AND_IF || tmp->token->type == OR_IF)
		{
			ret = tmp->brother->return_value;
			tmp = tmp->brother->brother;
		}
		else
		{
			ret = tmp->return_value;
			tmp = tmp->brother;
		}
	}
	return (ret);
}

int			statements(t_ast *node)
{
	int		ret;
	t_ast	*tmp;

	tmp = node->first_son;
	if (tmp->token->type == OR_IF || tmp->token->type == AND_IF)
		return (-1);
	type_node(tmp);
	ret = g_pid_loop->return_value;
	tmp = tmp->brother;
	node->return_value = every_commands(tmp, ret);
	return (0);
}

static int	type_node_bis(t_ast *node)
{
	if (node->token->type == COMMANDS)
	{
		if (node->first_son->brother
				&& node->first_son->brother->token->type == PIPE)
			my_pipe(node->first_son);
		else
			statements(node);
	}
	return (g_pid_loop->return_value);
}

int			type_node(t_ast *node)
{
	if (node == NULL)
		return (g_pid_loop->is_in_file + 1);
	if (node->token->type == COMMAND)
	{
		if (node->first_son->token->type == ASSIGNMENT)
			g_var = new_var(node->first_son);
		else
			exec_cmd(node);
	}
	else if (node->token->type == IF)
		exec_if(node);
	else if (node->token->type == WHILE || node->token->type == UNTIL)
		exec_while(node);
	else if (node->token->type == FOR)
		exec_for(node);
	else if (node->token->type == AND_IF || node->token->type == OR_IF)
		type_node(node->brother);
	else if (node->token->type == FUNCTION)
		g_funct = new_funct(node);
	else if (node->token->type == BANG)
		g_pid_loop->bang = 1;
	else
		return (type_node_bis(node));
	return (g_pid_loop->return_value);
}

int			init_var_function(t_ast *node)
{
	g_pid_loop->bang = 0;
	return (type_node(node));
}
