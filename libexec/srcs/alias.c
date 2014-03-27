/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 06:40:00 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static t_aliases	*add_alias(t_ast *node)
{
	t_aliases	*new;
	t_ast		*tmp;

	new = NULL;
	new = malloc(sizeof(t_aliases));
	new->alias = my_strcpy(node->brother->first_son->token->token);
	if (node->brother->first_son->brother == NULL)
		new->original = NULL;
	else
	{
		tmp = node->brother->first_son->brother;
		new->original = my_strcpy(tmp->token->token);
	}
	if (g_alias == NULL)
	{
		new->next = g_alias;
		return (new);
	}
	return (sort_list_alias(new));
}

static void			print_all_alias(t_aliases *g_alias)
{
	if (g_alias == NULL)
		return ;
	if (g_alias->original == NULL)
	{
		write(1, g_alias->alias, strlen(g_alias->alias));
		write(1, "=''\n", 4);
	}
	else
	{
		write(1, g_alias->alias, strlen(g_alias->alias));
		write(1, "='", 2);
		write(1, g_alias->original, strlen(g_alias->original));
		write(1, "'\n", 2);
	}
	print_all_alias(g_alias->next);
}

static void			alias_else(t_ast **tmp, t_ast **node, int turn)
{
	g_alias = add_alias((*tmp));
	if (turn == 0)
	{
		(*node)->return_value = 0;
		g_pid_loop->return_value = 0;
	}
}

t_aliases			*alias(t_ast *node)
{
	t_ast	*tmp;
	int		turn;

	tmp = node;
	turn = 0;
	while (tmp)
	{
		if (tmp->brother == NULL && tmp == node)
			print_all_alias(g_alias);
		else if (tmp->brother == NULL)
			break ;
		else if (tmp->brother->token->type == WORD)
		{
			print_alias(tmp->brother);
			turn = 1;
		}
		else if (tmp->brother->token->type == ASSIGNMENT)
		{
			alias_else(&tmp, &node, turn);
		}
		tmp = tmp->brother;
	}
	return (g_alias);
}
