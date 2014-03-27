/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:39:24 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 08:32:30 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser_functions.h"
#include "parser.h"

int				handle_loops(t_ast **ast)
{
	t_token	*current;
	t_ast	*new_for;
	t_ast	*while_until;

	current = g_lists->tokens->value;
	if (current->type == FOR)
	{
		g_lists->tokens = g_lists->tokens->next;
		new_for = get_new_son(ast, FOR, "FOR");
		if (!rule_for(&new_for))
			return (0);
	}
	else if (current->type == WHILE || current->type == UNTIL)
	{
		g_lists->tokens = g_lists->tokens->next;
		while_until = get_new_son(ast, current->type, current->token);
		if (!rule_while_until(&while_until))
			return (0);
	}
	return (1);
}

static int		ft_func2(t_ast **ast)
{
	if (!g_lists->tokens)
		return (print_and_exit("Unexpected end of file"));
	if (!compound_list(ast))
		return (0);
	if (!g_lists->tokens)
		return (print_and_exit("Unexpected end of file"));
	return (-1337);
}

int				shell_command(t_ast **ast)
{
	t_token	*current;
	t_ast	*new_if;
	int		ret;

	current = g_lists->tokens->value;
	if (current->type == LBRACE || current->type == LPARENT)
	{
		g_lists->tokens = g_lists->tokens->next;
		if ((ret = ft_func2(ast)) != -1337)
			return (ret);
		current = g_lists->tokens->value;
		if (current->type != RBRACE && current->type != RPARENT)
			return (print_and_exit("Expected '}' or ')'"));
		g_lists->tokens = g_lists->tokens->next;
	}
	else if (current->type == IF)
	{
		g_lists->tokens = g_lists->tokens->next;
		new_if = get_new_son(ast, IF, "IF");
		if (!rule_if(&new_if))
			return (0);
	}
	else if (!handle_loops(ast))
		return (0);
	return (1);
}

static int		ft_func1(t_token **current)
{
	if (!g_lists->tokens)
		return (print_and_exit("Expected double parenthesis"));
	*current = g_lists->tokens->value;
	if ((*current)->type != DOUBLEPARENT)
		return (print_and_exit("Expected '()' afternfunction name"));
	g_lists->tokens = g_lists->tokens->next;
	if (!g_lists->tokens)
		return (print_and_exit("Unexpected end of file"));
	return (-1337);
}

int				funcdec(t_ast **ast)
{
	t_ast	*new_fun;
	t_token	*current;
	t_ast	*new_cmds;
	int		ret;

	new_fun = get_new_son(ast, FUNCTION, "FUNCTION");
	current = g_lists->tokens->value;
	if (current->type == FUNCTION)
		g_lists->tokens = g_lists->tokens->next;
	if (!g_lists->tokens)
		return (print_and_exit("Expected function name"));
	current = g_lists->tokens->value;
	if (current->type != WORD)
		return (print_and_exit("Function name must be a WORD"));
	add_son(new_fun, init_node(current, NULL, NULL));
	g_lists->tokens = g_lists->tokens->next;
	ret = ft_func1(&current);
	if (ret != -1337)
		return (ret);
	discard_newline();
	if (!g_lists->tokens)
		return (print_and_exit("Unexpected end of file"));
	new_cmds = get_new_son(&new_fun, COMMANDS, "COMMANDS");
	return (shell_command(&new_cmds));
}
