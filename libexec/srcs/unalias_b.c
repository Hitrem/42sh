/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unalias_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:57:44 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 06:08:30 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_aliases	*free_part(t_ast *tmpnode)
{
	t_ast		*tmpnodebro;
	t_aliases	*tmp;
	t_aliases	*head;

	tmpnodebro = tmpnode->brother;
	tmp = g_alias;
	if (tmp->next != NULL)
	{
		while (strcmp(tmp->alias, tmpnodebro->token->token) != 0
				&& (tmpnodebro && tmp->next
					&& strcmp(tmp->next->alias, tmpnodebro->token->token) != 0))
			tmp = tmp->next;
	}
	if (tmp == g_alias && strcmp(tmp->alias, tmpnodebro->token->token) == 0)
	{
		head = g_alias->next;
		free(g_alias->alias);
		free(g_alias->original);
		free(g_alias);
		g_alias = head;
	}
	else
		g_alias = free_in_the_middle(tmp);
	return (g_alias);
}

int			turn_change(int turn, t_ast *tmpnode, int x)
{
	if (x == 1)
	{
		turn = 1;
		error_unalias(tmpnode, 0);
	}
	if (x == 2)
	{
		turn = 1;
		error_unalias(tmpnode, 1);
	}
	return (turn);
}
