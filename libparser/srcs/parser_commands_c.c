/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_commands_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 08:25:07 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 08:32:30 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser_functions.h"
#include "parser.h"

int				is_shell_command(t_token *tok)
{
	return (tok->type == LBRACE
	|| tok->type == LPARENT
	|| tok->type == FOR
	|| tok->type == WHILE
	|| tok->type == UNTIL
	|| tok->type == CASE
	|| tok->type == IF);
}

int				is_funcdec(t_token *tok, t_token *next)
{
	return (tok && (tok->type == FUNCTION
	|| (tok->type == WORD && next->type == DOUBLEPARENT)));
}

void			element(t_ast **ast)
{
	t_token	*current;
	char	*tmp;
	char	*val;
	t_ast	*new_ass;
	t_token	*new_var_tok;

	current = g_lists->tokens->value;
	if (current->type == ASSIGNMENT_WORD)
	{
		new_ass = get_new_son(ast, ASSIGNMENT, "ASSIGNMENT");
		tmp = strdup(current->token);
		new_var_tok = init_token(WORD, strtok(tmp, "="));
		add_son(new_ass, init_node(new_var_tok, NULL, NULL));
		add_tok_garbage(new_var_tok);
		val = strtok(NULL, "");
		if (val)
		{
			new_var_tok = init_token(WORD, val);
			add_son(new_ass, init_node(new_var_tok, NULL, NULL));
			add_tok_garbage(new_var_tok);
		}
		free(tmp);
	}
	else if (current->type == WORD || current->type == VARIABLE)
		add_son(*ast, init_node(current, NULL, NULL));
}
