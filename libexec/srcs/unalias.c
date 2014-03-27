/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unalias.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 22:14:27 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 06:08:19 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_ast			*error_unalias(t_ast *node, int j)
{
	if (j == 0)
	{
		node->return_value = 1;
		write(STDERR_FILENO,
				"42sh: unalias: usage: unalias [-a] name [name...]\n", 50);
		g_pid_loop->return_value = 2;
	}
	else if (j == 1)
	{
		node->return_value = 1;
		g_pid_loop->return_value = 1;
		write(2, "42sh: unalias: ", 15);
		write(2, node->brother->token->token,
				strlen(node->brother->token->token));
		write(2, ": not found\n", 12);
		g_pid_loop->return_value = 1;
	}
	return (node);
}

t_aliases		*free_in_the_middle(t_aliases *tmp)
{
	t_aliases	*rm;

	if (tmp->next)
	{
		rm = tmp->next;
		tmp->next = tmp->next->next;
		free(rm->alias);
		free(rm->original);
		free(rm);
	}
	else
	{
		free(tmp->alias);
		free(tmp->original);
		free(tmp);
	}
	return (g_alias);
}

t_aliases		*tmp_node(t_ast *node)
{
	int		turn;
	t_ast	*tmpnode;

	tmpnode = node;
	turn = 0;
	while (tmpnode)
	{
		if (tmpnode->brother == NULL && tmpnode == node)
			turn = turn_change(turn, tmpnode, 1);
		else if (tmpnode->brother == NULL)
		{
			if (turn == 0)
				g_pid_loop->return_value = 0;
			break ;
		}
		else if (find_alias(tmpnode->brother->token->token, g_alias) == 0)
			turn = turn_change(turn, tmpnode, 2);
		else
			g_alias = free_part(tmpnode);
		tmpnode = tmpnode->brother;
	}
	return (g_alias);
}

t_aliases		*unalias(t_ast *node)
{
	if (node->brother && strcmp(node->brother->token->token, "-a") == 0)
	{
		free_alias();
		g_pid_loop->return_value = 0;
		return (NULL);
	}
	tmp_node(node);
	return (g_alias);
}
