/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:08:39 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 00:12:21 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "parser_functions.h"
#include "parser.h"

int		print_and_exit(char *message)
{
	fprintf(stderr, "%s\n", message);
	return (0);
}

t_ast	*get_new_son(t_ast **ast, t_type type, char *token)
{
	t_token	*new_token;
	t_ast	*new_son;

	new_token = init_token(type, token);
	new_son = init_node(new_token, NULL, NULL);
	add_tok_garbage(new_token);
	add_son(*ast, new_son);
	return (new_son);
}

void	add_tok_garbage(t_token *tok)
{
	g_lists->garbage_tokens = list_append(g_lists->garbage_tokens, tok);
}

void	discard_newline(void)
{
	t_token *current;

	current = g_lists->tokens->value;
	while (current->type == NEWLINE)
	{
		g_lists->tokens = g_lists->tokens->next;
		if (!g_lists->tokens)
			break ;
		current = g_lists->tokens->value;
	}
}
