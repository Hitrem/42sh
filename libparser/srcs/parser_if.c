/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:29:12 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 03:13:47 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser_functions.h"
#include "parser.h"

static int	else_clause(t_ast **ast)
{
	t_token	*current;

	current = g_lists->tokens->value;
	g_lists->tokens = g_lists->tokens->next;
	if (!g_lists->tokens)
		return (print_and_exit("Cannot end command after ELSE/ELIF token"));
	if (!compound_list(ast))
		return (0);
	if (!g_lists->tokens)
		return (0);
	current = g_lists->tokens->value;
	if (current->type == THEN)
	{
		if (!compound_list(ast))
			return (0);
		if (!else_clause(ast))
			return (0);
	}
	return (1);
}

static int	handle_then(t_ast **ast)
{
	t_ast	*new_then;

	g_lists->tokens = g_lists->tokens->next;
	new_then = get_new_son(ast, COMMANDS, "COMMANDS");
	if (!compound_list(&new_then))
		return (0);
	if (!g_lists->tokens)
		return (print_and_exit("Missing 'fi' at the end of 'if' statement"));
	return (1);
}

static int	handle_else(t_ast **ast)
{
	t_token	*current;
	t_ast	*new_elif;
	t_ast	*new_else;

	current = g_lists->tokens->value;
	if (current->type == ELSE)
	{
		new_else = get_new_son(ast, COMMANDS, "COMMANDS");
		if (!else_clause(&new_else))
			return (0);
	}
	else if (current->type == ELIF)
	{
		new_elif = get_new_son(ast, IF, "IF");
		if (!else_clause(&new_elif))
			return (0);
	}
	return (1);
}

int			rule_if(t_ast **ast)
{
	t_ast	*new_cond;
	t_token	*current;

	new_cond = get_new_son(ast, COMMANDS, "COMMANDS");
	if (!compound_list(&new_cond))
		return (0);
	if (!g_lists->tokens)
		return (print_and_exit("Missing 'then' keyword in 'if' statement"));
	current = g_lists->tokens->value;
	if (current->type != THEN)
		return (print_and_exit("Missing 'then' keyword in 'if' statement"));
	if (!handle_then(ast))
		return (0);
	if (!handle_else(ast))
		return (0);
	current = g_lists->tokens->value;
	if (current->type == FI)
		g_lists->tokens = g_lists->tokens->next;
	else
		return (print_and_exit("Missing 'fi' at the end of 'if' statement"));
	return (1);
}
