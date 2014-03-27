/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 08:00:02 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 08:07:23 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "readline.h"
#include "parser_functions.h"
#include "parser.h"

int				add_bang(t_ast **ast, t_lists *g_lists)
{
	t_token *current;

	current = g_lists->tokens->value;
	if (current->type == BANG)
	{
		add_son(*ast, init_node(current, NULL, NULL));
		g_lists->tokens = g_lists->tokens->next;
		if (!g_lists->tokens)
			return (print_and_exit("Unexpected end of file"));
	}
	return (1);
}

int				ft_func(t_ast **ast, t_lists *g_lists, t_token **current)
{
	add_son(*ast, init_node(*current, NULL, NULL));
	g_lists->tokens = g_lists->tokens->next;
	if (!g_lists->tokens)
		return (1);
	*current = g_lists->tokens->value;
	while ((*current)->type == NEWLINE)
		g_lists->tokens = g_lists->tokens->next;
	return (0);
}

int				pipeline(t_ast **ast, t_lists *g_lists)
{
	t_token		*current;
	int			once;

	once = 1;
	if (!add_bang(ast, g_lists))
		return (0);
	current = g_lists->tokens->value;
	while (once || g_lists->tokens)
	{
		once = 0;
		if (!command(ast))
			return (0);
		if (!g_lists->tokens)
			break ;
		current = g_lists->tokens->value;
		if (current->type == PIPE)
		{
			if (ft_func(ast, g_lists, &current))
				break ;
		}
		else
			break ;
	}
	return (1);
}
