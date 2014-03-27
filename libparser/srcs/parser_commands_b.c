/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_commands_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 08:14:49 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 08:32:56 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser_functions.h"
#include "parser.h"

int				is_redirection(t_type type)
{
	return (type == IO_NUMBER
	|| type == RREDIR
	|| type == LREDIR
	|| type == DGREAT
	|| type == DLESS
	|| type == DLESSDASH
	|| type == GREATAND
	|| type == LESSAND
	|| type == CLOBBER
	|| type == LESSGREAT);
}

int				redirection(t_ast **ast)
{
	t_token	*current;

	current = g_lists->tokens->value;
	if (current->type == IO_NUMBER)
	{
		add_son(*ast, init_node(current, NULL, NULL));
		g_lists->tokens = g_lists->tokens->next;
		if (!g_lists->tokens)
			return (print_and_exit("Expected redirection after fd"));
	}
	current = g_lists->tokens->value;
	add_son(*ast, init_node(current, NULL, NULL));
	g_lists->tokens = g_lists->tokens->next;
	if (!g_lists->tokens)
		return (print_and_exit("Expected token after redirection"));
	current = g_lists->tokens->value;
	if (!current->type == WORD && !current->type == HEREDOC)
		return (print_and_exit("Expected WORD or HEREDOC after redirection"));
	add_son(*ast, init_node(current, NULL, NULL));
	return (1);
}

int				simple_command(t_ast **ast)
{
	t_ast	*new_cmd;
	t_token	*current;
	int		once;

	new_cmd = get_new_son(ast, COMMAND, "COMMAND");
	current = g_lists->tokens->value;
	once = 1;
	while (once || g_lists->tokens)
	{
		once = 0;
		current = g_lists->tokens->value;
		if (current->type == WORD || current->type == ASSIGNMENT_WORD ||
				current->type == VARIABLE)
			element(&new_cmd);
		else if (current->type == IO_NUMBER || is_redirection(current->type))
		{
			if (!redirection(&new_cmd))
				return (0);
		}
		else
			break ;
		g_lists->tokens = g_lists->tokens->next;
	}
	return (1);
}

int				command(t_ast **ast)
{
	t_token	*current;
	t_token	*next;

	if (is_shell_command((current = g_lists->tokens->value)))
		return (shell_command(ast));
	else if (current->type == ASSIGNMENT_WORD || current->type == WORD ||
			current->type == FUNCTION || current->type == VARIABLE)
	{
		if (!g_lists->tokens->next)
			return (simple_command(ast));
		else
		{
			next = g_lists->tokens->next->value;
			return (is_funcdec(current, next) ? funcdec(ast) :
			simple_command(ast));
		}
	}
	while (is_redirection(current->type))
	{
		g_lists->tokens = g_lists->tokens->next;
		if (!g_lists->tokens)
			break ;
		current = g_lists->tokens->value;
	}
	return (1);
}
