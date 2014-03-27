/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 19:09:15 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 08:13:23 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "readline.h"
#include "parser_functions.h"
#include "parser.h"

t_lists *g_lists = NULL;

int				and_or(t_ast **ast)
{
	t_token			*current;
	int				once;

	current = g_lists->tokens->value;
	once = 1;
	while (once || g_lists->tokens)
	{
		once = 0;
		if (!pipeline(ast, g_lists))
			return (0);
		if (!g_lists->tokens)
			break ;
		current = g_lists->tokens->value;
		if (current->type == AND_IF || current->type == OR_IF)
		{
			if (ft_func(ast, g_lists, &current))
				break ;
		}
		else
			break ;
	}
	return (1);
}

static t_token	*ft_init(int *once, t_token **new_cmds, t_ast **ast,
t_token **current)
{
	*once = 1;
	add_tok_garbage(NULL);
	*new_cmds = init_token(COMMANDS, "COMMANDS");
	*ast = init_node(*new_cmds, NULL, NULL);
	*current = g_lists->tokens->value;
	return (NULL);
}

static t_ast	*list(void)
{
	t_token		*new_cmds;
	t_ast		*ast;
	t_token		*current;
	t_token		*prev;
	int			once;

	prev = ft_init(&once, &new_cmds, &ast, &current);
	while (once || g_lists->tokens)
	{
		once = 0;
		if (!and_or(&ast))
			return (NULL);
		if (!g_lists->tokens)
			break ;
		prev = current;
		current = g_lists->tokens->value;
		if (prev == current)
		{
			printf("Unexpected token: %s\n", current->token);
			return (NULL);
		}
		if (current->type == SEMICOLON || current->type == NEWLINE)
			g_lists->tokens = g_lists->tokens->next;
	}
	return (ast);
}

t_ast			*get_ast(char *input)
{
	t_list			*head;
	t_ast			*ret;

	if (!g_lists)
		g_lists = (t_lists*)malloc(sizeof(t_lists));
	g_lists->tokens = get_tokens(input);
	if (!g_lists->tokens)
		return (NULL);
	head = g_lists->tokens;
	ret = list();
	g_lists->tokens = head;
	return (ret);
}
