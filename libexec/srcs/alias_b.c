/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:11:14 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 06:43:56 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void				print_alias(t_ast *node)
{
	char *als;
	char *orgl;

	if (find_alias(node->token->token, g_alias) == 0)
	{
		write(2, "42sh: alias: ", 13);
		write(2, node->token->token,
				strlen(node->token->token));
		write(2, ": not found\n", 12);
		node->return_value = 1;
		g_pid_loop->return_value = 1;
	}
	else
	{
		als = value_alias(node->token->token, g_alias, 1);
		orgl = value_alias(node->token->token, g_alias, 2);
		if (orgl == NULL)
			printf("%s=''\n", als);
		else
			printf("%s='%s'\n", als, orgl);
		node->return_value = 0;
		g_pid_loop->return_value = 0;
	}
}

int					find_alias(char *name, t_aliases *g_alias)
{
	if (g_alias == NULL)
		return (0);
	if (strcmp(name, g_alias->alias) == 0)
		return (1);
	return (find_alias(name, g_alias->next));
}

char				*value_alias(char *name, t_aliases *g_alias, int a)
{
	if (g_alias == NULL)
		return (NULL);
	if (strcmp(name, g_alias->alias) == 0)
	{
		if (a == 1)
			return (g_alias->alias);
		else if (a == 2)
			return (g_alias->original);
	}
	return (value_alias(name, g_alias->next, a));
}

static void			sort_list_else(t_aliases **prev, t_aliases **current
	, t_aliases **next)
{
	(*prev) = g_alias;
	(*current) = (*current)->next;
	if (*next)
		(*next) = (*next)->next;
}

t_aliases			*sort_list_alias(t_aliases *new)
{
	t_aliases *prev;
	t_aliases *current;
	t_aliases *next;

	prev = NULL;
	current = g_alias;
	next = g_alias->next;
	while (next && strcmp(next->alias, new->alias) < 0)
	{
		if (prev == NULL)
			sort_list_else(&prev, &current, &next);
		else
		{
			prev = prev->next;
			current = current->next;
			if (next)
				next = next->next;
		}
	}
	new->next = next;
	current->next = new;
	return (g_alias);
}
