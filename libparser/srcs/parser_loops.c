/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_loops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:12:27 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 09:47:49 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser_functions.h"
#include "parser.h"

static void	ft_init(t_token **current, int *once)
{
	*current = g_lists->tokens->value;
	discard_newline();
	*once = 1;
}

int			compound_list(t_ast **ast)
{
	t_token	*current;
	int		once;

	if (!g_lists->tokens || !g_lists->tokens->value)
		return (print_and_exit("Unexpected end of file"));
	ft_init(&current, &once);
	while (once || g_lists->tokens)
	{
		once = 0;
		if (!and_or(ast) || !g_lists->tokens)
			return (0);
		current = g_lists->tokens->value;
		if (current->type == SEMICOLON || current->type == NEWLINE)
		{
			g_lists->tokens = g_lists->tokens->next;
			if (!g_lists->tokens)
				break ;
			current = g_lists->tokens->value;
			discard_newline();
		}
		else
			break ;
	}
	return (1);
}

int			discard_to_done(void)
{
	t_token		*current;
	int			once;

	current = g_lists->tokens->value;
	once = 1;
	while (once || current->type != DONE)
	{
		once = 0;
		g_lists->tokens = g_lists->tokens->next;
		if (!g_lists->tokens)
			break ;
		current = g_lists->tokens->value;
	}
	g_lists->tokens = g_lists->tokens->next;
	return (0);
}

int			rule_while_until(t_ast **ast)
{
	t_ast	*new_cond;
	t_token	*current;
	t_ast	*new_do;

	new_cond = get_new_son(ast, COMMANDS, "COMMANDS");
	if (!compound_list(&new_cond))
		return (0);
	if (!g_lists->tokens)
		return (print_and_exit("Unexpected end of file"));
	current = g_lists->tokens->value;
	if (current->type != DO)
		return (print_and_exit("Missing 'do' keyword in loop statement"));
	g_lists->tokens = g_lists->tokens->next;
	new_do = get_new_son(ast, COMMANDS, "COMMANDS");
	if (!compound_list(&new_do))
		return (0);
	if (!g_lists->tokens)
		return (print_and_exit("Unexpected end of file"));
	current = g_lists->tokens->value;
	if (current->type != DONE)
		return (print_and_exit("Expected 'done' at the end of loop statement"));
	g_lists->tokens = g_lists->tokens->next;
	return (1);
}

int			rule_for(t_ast **ast)
{
	t_token	*current;

	if (!g_lists->tokens)
		return (0);
	if (!handle_in(ast))
		return (0);
	current = g_lists->tokens->value;
	if (current->type != SEMICOLON && current->type != NEWLINE)
		return (print_and_exit("Expected semicolon or newline"));
	g_lists->tokens = g_lists->tokens->next;
	discard_newline();
	if (!g_lists->tokens)
		return (print_and_exit("Unexpected end of file"));
	return (for_loop(ast));
}
